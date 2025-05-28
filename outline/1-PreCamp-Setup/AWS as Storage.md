Okay, sending data directly to an AWS S3 bucket from an embedded device like the ESP32-S3 introduces a new set of challenges, primarily around authentication.

Unlike GitHub's Personal Access Tokens, AWS S3 uses a more complex signature mechanism called AWS Signature Version 4 (SigV4) for authenticating requests. Implementing SigV4 directly on an ESP32 is extremely difficult and often not practical due to:

Cryptographic Complexity: SigV4 involves multiple SHA256 hashes and HMAC-SHA256 operations on various parts of the request (headers, payload, URI, query parameters) in a specific order.
Time Synchronization: SigV4 requires the request to be signed with a timestamp that is very close to the actual time the request is received by AWS (within 5 minutes). This means your ESP32 needs robust NTP time synchronization.
Memory and Processing Overhead: Performing these cryptographic operations and constructing the canonical request string can be memory-intensive and computationally heavy for a microcontroller.
Managing Credentials: Storing your AWS Access Key ID and Secret Access Key directly on an IoT device is generally considered a security risk.
Recommended & Practical Solution: Pre-signed URLs
The industry-standard and most secure way to handle direct uploads from IoT devices to S3 is by using AWS S3 Pre-signed URLs.

How it works:

Backend Service: You create a small, secure backend service (e.g., an AWS Lambda function, a simple serverless API Gateway endpoint, a Python Flask/Node.js Express application on an EC2 instance, etc.).
ESP32 Request: Your ESP32-S3 makes a simple HTTP request to this backend service, telling it "I want to upload a file named image_X.jpg of type image/jpeg."
Backend Generates Pre-signed URL: The backend service, using your AWS Access Key ID/Secret Access Key (which are stored securely on the backend, not the ESP32), generates a pre-signed URL for S3. This URL contains temporary credentials allowing anyone with the URL to upload a specific file to a specific S3 location for a limited time (e.g., 5 minutes, 1 hour).
Backend Responds: The backend sends this pre-signed URL back to the ESP32.
ESP32 Upload: The ESP32 then performs a simple HTTP PUT request directly to the received pre-signed URL, sending the raw JPEG image data as the request body. No complex SigV4 authentication needed on the ESP32! S3 validates the pre-signed URL and allows the upload.
This approach offloads the security-sensitive credential handling and complex signing to a secure server, making the ESP32's role much simpler and more robust.

Implementation with Pre-signed URLs
I will provide the ESP32 code for this approach. You will need to set up a simple backend service yourself (which is outside the scope of this ESP32 code, but I'll describe what it needs to do).

Required Setup:

AWS Account:

S3 Bucket: Create an S3 bucket in your desired region.
IAM User/Role: Create an IAM user or role with permissions to perform s3:PutObject on your S3 bucket. You will use the credentials (Access Key ID and Secret Access Key) of this user/role for your backend service.
Backend Service: Set up your chosen backend component (e.g., AWS Lambda + API Gateway) that can generate pre-signed URLs.
Arduino IDE & Libraries:

WiFi.h
HTTPClient.h
ArduinoJson by Benoit Blanchon (v6 is recommended).
esp32-camera (Usually comes with the ESP32 core).
Step 1: secrets.h (Modified)
// secrets.h
#ifndef SECRETS_H
#define SECRETS_H

// WiFi Credentials
#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASSWORD "Your_WiFi_Password"

// AWS S3 Configuration
// Your S3 bucket name
#define AWS_S3_BUCKET_NAME "your-esp32-camera-uploads-bucket"
// Your AWS region (e.g., "us-east-1", "eu-west-2")
#define AWS_S3_REGION "us-east-1"
// Define a folder path within your bucket for organization. Images will be stored as s3://YOUR_BUCKET/images/image_YYYYMMDD_HHmmss.jpg
#define AWS_S3_FOLDER_PATH "images"

// Pre-signed URL Generator Endpoint
// This is YOUR custom backend endpoint that will generate the pre-signed URL for upload.
// Example for a simple GET request: "https://your-api-gateway-id.execute-api.us-east-1.amazonaws.com/prod/get-s3-presigned-url"
// Example for a POST request: "https://your-api-gateway-id.execute-api.us-east-1.amazonaws.com/prod/generate-upload-url"
#define PRESIGNED_URL_GENERATOR_ENDPOINT "http://your.backend.service/get-s3-presigned-url" // <--- REPLACE THIS WITH YOUR BACKEND ENDPOINT

#endif
Important: Your AWS Access Key ID and Secret Access Key do NOT go into secrets.h on the ESP32. They are used by your secure backend service.

Step 2: arduino_camera_s3_upload.ino
We don't need base64.h anymore for the S3 upload itself, as we'll send raw binary data.

// arduino_camera_s3_upload.ino
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> // Make sure you have ArduinoJson library installed (v6 recommended)

#include "esp_camera.h"
#include "camera_pins.h" // For ESP32-S3 boards, this file maps the camera pins.

#include "secrets.h" // Your WiFi credentials and S3 config

// ==============================================================================
// CAMERA CONFIGURATION
// ==============================================================================

// IMPORTANT: Replace this with the correct camera model for your ESP32-S3 board
// #define CAMERA_MODEL_ESP32S3_CAM_BOARD // For Espressif's official S3-CAM
// #define CAMERA_MODEL_XIAO_ESP32S3_SENSE
// If you're unsure, try the `Camera Example` in the esp32-camera library,
// it usually has these defines at the top. Comment out or define the correct one.
#define CAMERA_MODEL_ESP32S3_CAM_BOARD // <---- ADJUST THIS FOR YOUR BOARD!

// Camera Settings
#define PHOTO_RESOLUTION FRAMESIZE_QVGA // FRAMESIZE_QVGA (320x240) good for memory.
                                      // FRAMESIZE_VGA (640x480) is possible but more memory intensive.
                                      // FRAMESIZE_SVGA (800x600) or higher will likely crash due to RAM.
#define JPEG_QUALITY     10              // 10-63, lower is higher quality (larger file)

// ===================================
// GLOBAL VARIABLES
// ===================================
camera_config_t camera_config;

// ===================================
// SETUP
// ===================================
void setup() {
  Serial.begin(115200);
  Serial.setTxBufferSize(512); // Increase buffer size for serial output
  Serial.println("\n");

  initWiFi();
  initCamera();

  // Trigger an upload
  uploadPhotoToS3();

  // You might want to upload periodically:
  // For demonstration, commenting out continuous upload.
  // In a real application, you'd use a timer or specific event.
  // Serial.println("Entering loop to periodically upload (every 30 seconds)...");
}

// ===================================
// LOOP
// ===================================
void loop() {
  // Example: Upload every 30 seconds
  // You might want to remove delay and use a non-blocking timer
  // or trigger on motion detection, etc.
  // delay(30000);
  // uploadPhotoToS3();

  // Keep the loop running for other tasks if any
  delay(10);
}

// ===================================
// FUNCTIONS
// ===================================

void initWiFi() {
  WiFi.mode(WIFI_STA);
  Serial.printf("Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int timeout = 0;
  while (WiFi.status() != WL_CONNECTED && timeout < 20) {
    delay(500);
    Serial.print(".");
    timeout++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(" Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println(" WiFi connection failed. Please check credentials and try again.");
    ESP.restart(); // Restart if WiFi fails to connect
  }
}

void initCamera() {
  Serial.println("Initializing camera...");

  // Based on the CAMERA_MODEL_... defined, the pins are set in camera_pins.h
  camera_config.ledc_channel = LEDC_CHANNEL_0;
  camera_config.ledc_timer = LEDC_TIMER_0;
  camera_config.pin_d0 = Y2_GPIO_NUM;
  camera_config.pin_d1 = Y3_GPIO_NUM;
  camera_config.pin_d2 = Y4_GPIO_NUM;
  camera_config.pin_d3 = Y5_GPIO_NUM;
  camera_config.pin_d4 = Y6_GPIO_NUM;
  camera_config.pin_d5 = Y7_GPIO_NUM;
  camera_config.pin_d6 = Y8_GPIO_NUM;
  camera_config.pin_d7 = Y9_GPIO_NUM;
  camera_config.pin_xclk = XCLK_GPIO_NUM;
  camera_config.pin_pclk = PCLK_GPIO_NUM;
  camera_config.pin_vsync = VSYNC_GPIO_NUM;
  camera_config.pin_href = HREF_GPIO_NUM;
  camera_config.pin_sscb_sda = SIOD_GPIO_NUM;
  camera_config.pin_sscb_scl = SIOC_GPIO_NUM;
  camera_config.pin_pwdn = PWDN_GPIO_NUM;
  camera_config.pin_reset = RESET_GPIO_NUM;
  camera_config.xclk_freq_hz = 20000000;
  camera_config.pixel_format = PIXFORMAT_JPEG;

  // framesize and quality
  camera_config.frame_size = PHOTO_RESOLUTION;
  camera_config.jpeg_quality = JPEG_QUALITY;
  camera_config.fb_count = 1;

  // Camera init
  esp_err_t err = esp_camera_init(&camera_config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x\n", err);
    ESP.restart();
  }

  Serial.println("Camera initialized successfully.");

  sensor_t *s = esp_camera_sensor_get();
  if (s == NULL) {
    Serial.println("Failed to get camera sensor object!");
    ESP.restart();
  }
}

// Function to get local time for filename stamping.
// Crucial for S3 uploads for unique filenames.
// You might need to set your NTP server and timezone in a real application.
void getLocalTime(struct tm *timeinfo) {
  // Use NTP to get time (UTC)
  configTime(0, 0, "pool.ntp.org");
  setenv("TZ", "UTC", 1); // Set timezone to UTC
  tzset(); // Apply timezone settings

  Serial.print("Waiting for NTP time sync...");
  int retry = 0;
  // getLocalTime returns false if time is not yet synchronized
  while (!::getLocalTime(timeinfo) && retry < 10) { // Note: ::getLocalTime to avoid conflict if any custom function exists
    delay(1000);
    Serial.print(".");
    retry++;
  }
  Serial.println();
  if (retry >= 10) {
    Serial.println("Warning: NTP time sync failed. Using default time or 0.");
  } else {
    Serial.println("Time synced.");
  }
}


void uploadPhotoToS3() {
  Serial.println("Capturing photo...");
  camera_fb_t *fb = NULL;
  fb = esp_camera_fb_get();

  if (!fb) {
    Serial.println("Camera capture failed!");
    return;
  }

  Serial.printf("Photo captured: Size %d bytes, Format JPEG\n", fb->len);

  // Generate a unique filename using timestamp
  struct tm timeinfo;
  getLocalTime(&timeinfo); // This will block until time is synced or timeout
  
  char filename[64];
  strftime(filename, sizeof(filename), "%Y%m%d_%H%M%S.jpg", &timeinfo); // e.g., 20231027_103045.jpg
  
  String s3ObjectKey = String(AWS_S3_FOLDER_PATH) + "/" + filename; // e.g., images/20231027_103045.jpg

  Serial.printf("Requesting pre-signed URL for S3 object key: %s\n", s3ObjectKey.c_str());

  HTTPClient http;
  http.begin(PRESIGNED_URL_GENERATOR_ENDPOINT);
  http.addHeader("Content-Type", "application/json");

  // Create JSON payload for the backend service
  StaticJsonDocument<256> requestDoc; // Small capacity as we only send filename and content type
  requestDoc["objectKey"] = s3ObjectKey;
  requestDoc["contentType"] = "image/jpeg";
  requestDoc["bucket"] = AWS_S3_BUCKET_NAME; // Optional: send bucket name as well if the backend is generic

  String requestBody;
  serializeJson(requestDoc, requestBody);

  Serial.printf("Sending pre-signed URL request body: %s\n", requestBody.c_str());

  int httpCode = http.POST(requestBody);

  String preSignedUrl = "";
  if (httpCode == HTTP_CODE_OK) { // HTTP 200 OK
    String payload = http.getString();
    Serial.println("Pre-signed URL backend response:");
    Serial.println(payload);

    // Parse the JSON response from your backend
    DynamicJsonDocument responseDoc(512); // Adjust size as needed for your backend's response
    DeserializationError error = deserializeJson(responseDoc, payload);

    if (!error) {
      preSignedUrl = responseDoc["uploadUrl"].as<String>(); // Assuming your backend returns a JSON with "uploadUrl" key
      Serial.printf("Received pre-signed URL from backend:\n%s\n", preSignedUrl.c_str());
    } else {
      Serial.printf("Failed to parse JSON response from backend: %s\n", error.c_str());
    }
  } else {
    Serial.printf("Failed to get pre-signed URL from backend. HTTP Error: %d - %s\n", httpCode, http.errorToString(httpCode).c_str());
    Serial.println(http.getString()); // Print backend error response
  }
  http.end(); // Close connection to backend service

  if (preSignedUrl.length() > 0) {
    Serial.println("Attempting to upload image directly to S3 via pre-signed URL...");

    HTTPClient s3_http;
    s3_http.begin(preSignedUrl);
    s3_http.addHeader("Content-Type", "image/jpeg");
    // No Authorization header needed when using a pre-signed URL for PUT!

    // Send the raw binary data from the camera frame buffer
    httpCode = s3_http.PUT(fb->buf, fb->len);

    Serial.printf("S3 PUT response code: %d\n", httpCode);

    if (httpCode == HTTP_CODE_OK) { // HTTP 200 OK means successful upload
      Serial.println("Image uploaded to S3 successfully!");
    } else {
      Serial.printf("S3 Upload failed. HTTP Error: %d - %s\n", httpCode, s3_http.errorToString(httpCode).c_str());
      String responseBody = s3_http.getString();
      Serial.println("S3 Error Response:");
      Serial.println(responseBody); // S3 often returns XML error details
    }
    s3_http.end(); // Close S3 connection
  } else {
    Serial.println("No pre-signed URL obtained, skipping S3 upload.");
  }


  esp_camera_fb_return(fb); // Release camera frame buffer
}
Conceptual Backend Service (Example in Python using Flask & boto3)
This is a very minimal example to give you an idea of what your backend service needs to do. You would deploy this on AWS Lambda + API Gateway, or a simple server.

# backend_service.py (Example using Flask and boto3)
# To run locally:
# pip install Flask boto3
# FLASK_APP=backend_service.py flask run

from flask import Flask, request, jsonify
import boto3
import os

app = Flask(__name__)

# --- AWS Configuration ---
# IMPORTANT: DO NOT hardcode credentials in production.
# Use IAM roles for Lambda, environment variables for other services.
AWS_ACCESS_KEY_ID = os.environ.get('AWS_ACCESS_KEY_ID')
AWS_SECRET_ACCESS_KEY = os.environ.get('AWS_SECRET_ACCESS_KEY')
AWS_REGION = os.environ.get('AWS_REGION', 'us-east-1') # Must match what's in secrets.h if provided by ESP32

s3_client = boto3.client(
    's3',
    region_name=AWS_REGION,
    aws_access_key_id=AWS_ACCESS_KEY_ID,
    aws_secret_access_key=AWS_SECRET_ACCESS_KEY
)

@app.route('/get-s3-presigned-url', methods=['POST'])
def get_s3_presigned_url():
    data = request.json
    if not data:
        return jsonify({"error": "Invalid JSON"}), 400

    object_key = data.get('objectKey')
    content_type = data.get('contentType', 'application/octet-stream')
    bucket_name = data.get('bucket', 'your-esp32-camera-uploads-bucket') # Default or sent by ESP32

    if not object_key:
        return jsonify({"error": "Missing 'objectKey' in request"}), 400
    
    # Generate pre-signed URL for PUT object
    try:
        # Client method 'put_object' refers to the S3 operation
        # ExpiresIn is in seconds. 300 seconds = 5 minutes
        response = s3_client.generate_presigned_url(
            ClientMethod='put_object',
            Params={
                'Bucket': bucket_name,
                'Key': object_key,
                'ContentType': content_type
            },
            ExpiresIn=300 # URL validity in seconds
        )
        return jsonify({"status": "success", "uploadUrl": response}), 200
    except Exception as e:
        print(f"Error generating pre-signed URL: {e}")
        return jsonify({"error": f"Failed to generate pre-signed URL: {str(e)}"}), 500

if __name__ == '__main__':
    # Flask development server (not for production)
    app.run(host='0.0.0.0', port=5000, debug=True)

    # For AWS Lambda, you'd integrate this with a serverless framework
    # or handle it as a Lambda function.
    # The `app` object would be used by `wsgi_app` or similar.
To deploy the backend to AWS Lambda:

Create a Lambda function (e.g., using Python 3.9+ runtime).
Add a requirements.txt with boto3 and Flask (if using Flask).
Set environment variables: AWS_ACCESS_KEY_ID, AWS_SECRET_ACCESS_KEY, AWS_REGION.
Configure the Lambda function's execution role with s3:PutObject permissions on your target bucket.
Set up an API Gateway endpoint (HTTP API is simplest) that triggers this Lambda function.
The PRESIGNED_URL_GENERATOR_ENDPOINT in secrets.h will be the URL of this API Gateway endpoint.
Key Considerations & Troubleshooting:
NTP Time Synchronization: The getLocalTime function needs to succeed for filename stamping. If NTP fails, your filenames might be generic or incorrect. Ensure your ESP32 has internet access for NTP.
S3 Bucket Policy: Ensure your S3 bucket policy doesn't explicitly deny the s3:PutObject action for the IAM user/role used by your backend service.
CORS (Cross-Origin Resource Sharing): If your backend service is accessed directly from a web page (e.g., for testing), you might need to configure CORS headers on your backend. This is usually not an issue when the ESP32 is the client.
Network Connectivity: Verify both the ESP32's connection to your backend service and the backend service's connection to AWS S3.
Memory Management: Image buffers (fb->buf) and HTTP client buffers can consume significant RAM. If you encounter crashes, try reducing PHOTO_RESOLUTION or JPEG_QUALITY.
Error Handling: Observe the serial output for HTTP errors (httpCode). S3 will often return detailed XML error messages in the response body if an upload fails (e.g., permission denied, bucket not found).
Pre-signed URL Expiration: If the pre-signed URL expires before the ESP32 can use it, the S3 upload will fail (HTTP 403 Forbidden). Keep the ExpiresIn duration reasonable for your use case (e.g., 300 seconds is 5 minutes, usually more than enough).
Backend Security: Never hardcode your AWS credentials in your backend code if it's going into production. Use IAM roles (for Lambda/EC2) or AWS Secrets Manager for secure credential management.
This setup provides a robust and secure way to upload images directly from your ESP32-S3 camera to an AWS S3 bucket.

Citation Sources
https://forum.arduino.cc/t/mkr1000-runs-loop-once-on-battery-but-then-doesnt-run-anymore/1068029?page=2 
https://github.com/CodyTolene/Flipper-Zero-Camera-Suite 
https://github.com/JohnMankovich/pdamiani-DT 
https://github.com/RobertWojtowicz/miscale2garmin 
https://github.com/XazkerBoy/RemoteReely 
https://github.com/adafruit/Adafruit_Learning_System_Guides 
https://medium.com/@codingmatheus/sending-images-to-claude-3-using-amazon-be
