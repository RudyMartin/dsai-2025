
Thoughts
Expand to show model's summarized thoughts
You want to send data from your ESP32-S3 camera to Google Cloud Storage (GCS).

Similar to AWS S3, Google Cloud Storage also uses robust authentication mechanisms. Directly implementing the full OAuth2.0 / JWT (JSON Web Token) based authentication, which GCS primarily uses, on an ESP32 is even more challenging and resource-intensive than AWS SigV4. It involves:

Generating a JSON Web Token (JWT) on the device. This requires performing RSA-256 cryptographic signing using a private key, which is computationally expensive and memory-intensive for an ESP32.
Exchanging the JWT for an ephemeral OAuth2.0 access token by making an HTTP POST request to Google's authentication server.
Using this access token in the Authorization header for subsequent GCS API requests.
Managing token expiry and refreshing.
Therefore, the recommended and practical solution for GCP Cloud Storage from an ESP32 is also using pre-signed URLs.

Recommended & Practical Solution: Google Cloud Storage Signed URLs
The workflow is almost identical to the AWS S3 pre-signed URL approach:

Backend Service (GCP or other): You create a secure backend service (e.g., an AWS Lambda function, a Google Cloud Function, a Cloud Run service, a Python Flask/Node.js Express application, etc.).
ESP32 Request: Your ESP32-S3 captures an image and makes a simple HTTP request to this backend service, asking for a signed URL to upload a specific file (e.g., image_X.jpg).
Backend Generates Signed URL: The backend service, using its securely stored Google Cloud Service Account credentials, generates a signed URL for your GCS bucket. This URL grants temporary permission to upload a file to a specific location for a limited time.
Backend Responds: The backend sends this signed URL back to the ESP32.
ESP32 Upload: The ESP32 then performs a simple HTTP PUT request directly to the received signed URL, sending the raw JPEG image data as the request body. GCS validates the signed URL and allows the upload.
This approach offloads all the complex authentication and credential management to your secure backend, making the ESP32's job much simpler and maintaining security.

Implementation with Google Cloud Storage Signed URLs
I will provide the ESP32 code for this approach. You will need to set up a simple backend service yourself (which is outside the scope of this ESP32 code, but I'll describe what it needs to do).

Required GCP Setup:

GCP Project: Ensure you have an active Google Cloud Project.

Cloud Storage Bucket: Create a bucket in your desired region.

Service Account:

Go to IAM & Admin > Service Accounts.
Create a new Service Account.
Grant it a role that allows uploading objects to your bucket, e.g., Storage Object Creator (or even Storage Object Admin for simplicity in testing, but narrow down permissions for production).
Generate JSON Key: After creating the service account, click on it, go to Keys, and Add Key > Create new key > JSON. Download this JSON file. This file contains the credentials your backend service will use to authenticate with GCP. DO NOT put this key on your ESP32.
Backend Service: Set up your chosen backend component (e.g., Google Cloud Function deployed via Cloud Console or gcloud CLI) that can generate signed URLs.

Arduino IDE & Libraries:

WiFi.h
HTTPClient.h
ArduinoJson by Benoit Blanchon (v6 is recommended).
esp32-camera (Usually comes with the ESP32 core).
Step 1: secrets.h (Modified for GCP)
// secrets.h
#ifndef SECRETS_H
#define SECRETS_H

// WiFi Credentials
#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASSWORD "Your_WiFi_Password"

// GCP Cloud Storage Configuration
#define GCP_PROJECT_ID "your-gcp-project-id" // e.g., "my-esp32-project-123456"
#define GCP_BUCKET_NAME "your-gcs-bucket-name" // e.g., "esp32-camera-uploads"
// Define a folder path within your bucket for organization. Images will be stored as gs://YOUR_BUCKET/images/image_YYYYMMDD_HHmmss.jpg
#define GCP_FOLDER_PATH "images"

// Signed URL Generator Endpoint
// This is YOUR custom backend endpoint that will generate the signed URL for upload.
// Example for a Google Cloud Function: "https://<REGION>-<PROJECT_ID>.cloudfunctions.net/generateSignedUrl"
#define SIGNED_URL_GENERATOR_ENDPOINT "https://your.backend.service/generateSignedUrl" // <--- REPLACE THIS WITH YOUR BACKEND ENDPOINT

#endif
Important: Your GCP Service Account JSON key does NOT go into secrets.h on the ESP32. It is used by your secure backend service.

Step 2: arduino_camera_gcs_upload.ino
This code is almost identical to the AWS S3 version, as the ESP32's interaction pattern (requesting URL, then PUTting to URL) is the same. Only the secrets.h defines and the service names change.

// arduino_camera_gcs_upload.ino
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> // Make sure you have ArduinoJson library installed (v6 recommended)

#include "esp_camera.h"
#include "camera_pins.h" // For ESP32-S3 boards, this file maps the camera pins.

#include "secrets.h" // Your WiFi credentials and GCP config

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
  uploadPhotoToGCS();

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
  // uploadPhotoToGCS();

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
// Crucial for unique filenames.
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


void uploadPhotoToGCS() {
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
  
  String gcsObjectKey = String(GCP_FOLDER_PATH) + "/" + filename; // e.g., images/20231027_103045.jpg

  Serial.printf("Requesting signed URL for GCS object key: %s\n", gcsObjectKey.c_str());

  HTTPClient http;
  http.begin(SIGNED_URL_GENERATOR_ENDPOINT);
  http.addHeader("Content-Type", "application/json");

  // Create JSON payload for the backend service
  StaticJsonDocument<256> requestDoc; // Small capacity as we only send filename and content type
  requestDoc["objectKey"] = gcsObjectKey;
  requestDoc["contentType"] = "image/jpeg";
  requestDoc["bucket"] = GCP_BUCKET_NAME; // Optional: send bucket name as well if the backend is generic
  requestDoc["projectId"] = GCP_PROJECT_ID; // Optional: send project ID

  String requestBody;
  serializeJson(requestDoc, requestBody);

  Serial.printf("Sending signed URL request body: %s\n", requestBody.c_str());

  int httpCode = http.POST(requestBody);

  String signedUrl = "";
  if (httpCode == HTTP_CODE_OK) { // HTTP 200 OK
    String payload = http.getString();
    Serial.println("Signed URL backend response:");
    Serial.println(payload);

    // Parse the JSON response from your backend
    DynamicJsonDocument responseDoc(512); // Adjust size as needed for your backend's response
    DeserializationError error = deserializeJson(responseDoc, payload);

    if (!error) {
      signedUrl = responseDoc["uploadUrl"].as<String>(); // Assuming your backend returns a JSON with "uploadUrl" key
      Serial.printf("Received signed URL from backend:\n%s\n", signedUrl.c_str());
    } else {
      Serial.printf("Failed to parse JSON response from backend: %s\n", error.c_str());
    }
  } else {
    Serial.printf("Failed to get signed URL from backend. HTTP Error: %d - %s\n", httpCode, http.errorToString(httpCode).c_str());
    Serial.println(http.getString()); // Print backend error response
  }
  http.end(); // Close connection to backend service

  if (signedUrl.length() > 0) {
    Serial.println("Attempting to upload image directly to GCS via signed URL...");

    HTTPClient gcs_http;
    // For signed URLs, the hostname might be storage.googleapis.com
    gcs_http.begin(signedUrl);
    gcs_http.addHeader("Content-Type", "image/jpeg");
    // No Authorization header needed when using a signed URL for PUT!

    // Send the raw binary data from the camera frame buffer
    httpCode = gcs_http.PUT(fb->buf, fb->len);

    Serial.printf("GCS PUT response code: %d\n", httpCode);

    if (httpCode == HTTP_CODE_OK) { // HTTP 200 OK means successful upload
      Serial.println("Image uploaded to GCS successfully!");
    } else {
      Serial.printf("GCS Upload failed. HTTP Error: %d - %s\n", httpCode, gcs_http.errorToString(httpCode).c_str());
      String responseBody = gcs_http.getString();
      Serial.println("GCS Error Response:");
      Serial.println(responseBody); // GCS often returns HTML/XML error details
    }
    gcs_http.end(); // Close GCS connection
  } else {
    Serial.println("No signed URL obtained, skipping GCS upload.");
  }

  esp_camera_fb_return(fb); // Release camera frame buffer
}
Conceptual Backend Service (Example in Python using Google Cloud Client Library)
This is a very minimal example to give you an idea of what your backend service needs to do. You would typically deploy this as a Google Cloud Function or a Cloud Run service.

# main.py or app.py (for Google Cloud Function/Cloud Run)
# To install: pip install google-cloud-storage Flask

from flask import Flask, request, jsonify
from google.cloud import storage # Google Cloud Storage client library
import os

app = Flask(__name__)

# Initialize Google Cloud Storage client
# When deployed on Google Cloud (Cloud Functions, Cloud Run, App Engine, etc.),
# authentication is handled automatically using the service account associated
# with the environment.
# If running locally, you'd need to set the GOOGLE_APPLICATION_CREDENTIALS
# environment variable to point to your service account JSON key file.
storage_client = storage.Client()

@app.route('/generateSignedUrl', methods=['POST'])
def generate_signed_url():
    data = request.json
    if not data:
        return jsonify({"error": "Invalid JSON"}), 400

    object_name = data.get('objectKey') # This typically includes the folder path, e.g., "images/my-image.jpg"
    content_type = data.get('contentType', 'application/octet-stream')
    bucket_name = data.get('bucket', 'your-gcs-bucket-name') # Default or sent by ESP32

    if not object_name:
        return jsonify({"error": "Missing 'objectKey' in request"}), 400
    
    # Generate signed URL
    try:
        bucket = storage_client.bucket(bucket_name)
        blob = bucket.blob(object_name)

        # Generate a signed URL for uploading a blob.
        # This URL is valid for 5 minutes.
        signed_url = blob.generate_signed_url(
            version="v4",
            expiration=300, # Expires in 300 seconds (5 minutes)
            method="PUT",
            content_type=content_type
        )
        return jsonify({"status": "success", "uploadUrl": signed_url}), 200
    except Exception as e:
        print(f"Error generating signed URL: {e}")
        return jsonify({"error": f"Failed to generate signed URL: {str(e)}"}), 500

if __name__ == '__main__':
    # Local development server (not for production)
    app.run(host='0.0.0.0', port=8080, debug=True)

    # For Google Cloud Function deployment:
    # Your GCF entry point would call `generate_signed_url`
    # and handle the Flask request/response directly or via a wrapper like `functions_framework`.
To deploy the backend to Google Cloud Function:

Create a new Cloud Function in your GCP project.
Select a runtime (e.g., Python 3.9+).
Set the entry point to generate_signed_url (assuming your Python file is main.py).
Add google-cloud-storage and Flask to your requirements.txt file.
Ensure the Cloud Function's default service account has the necessary permissions (e.g., Storage Object Creator) on your GCS bucket.
The SIGNED_URL_GENERATOR_ENDPOINT in secrets.h will be the trigger URL for this Cloud Function.
Key Considerations & Troubleshooting:
NTP Time Synchronization: As with AWS, correct time on the ESP32 is crucial for unique filenames.
GCS Bucket Permissions: Ensure the Service Account used by your backend has the Storage Object Creator role on your bucket. Without it, the generate_signed_url call will fail.
Backend Security: Never hardcode your GCP Service Account JSON key in your production backend code. Google Cloud Functions and Cloud Run automatically handle authentication through their associated service accounts, making it highly secure. If you run your backend outside GCP, use environment variables (GOOGLE_APPLICATION_CREDENTIALS) or other secure methods.
Network Connectivity: Verify both the ESP32's connection to your backend service and the backend service's connection to Google Cloud Storage.
Memory Management: Image buffers (fb->buf) and HTTP client buffers are critical. If you encounter crashes (Guru Meditation), try reducing PHOTO_RESOLUTION or JPEG_QUALITY.
Error Handling: Observe the serial output for HTTP errors (httpCode). GCS often returns detailed error messages in the response body if an upload fails.
Signed URL Expiration: If the signed URL expires before the ESP32 can use it, the GCS upload will fail (HTTP 403 Forbidden). Keep the expiration duration reasonable (e.g., 5 minutes).
This setup provides a robust and secure way to upload images directly from your ESP32-S3 camera to a Google Cloud Storage bucket.

Citation Sources
https://forum.arduino.cc/t/mkr1000-runs-loop-once-on-battery-but-then-doesnt-run-anymore/1068029?page=2 
https://github.com/CodyTolene/Flipper-Zero-Camera-Suite 
https://github.com/RobertWojtowicz/miscale2garmin 
https://github.com/XazkerBoy/RemoteReely 
https://github.com/adafruit/Adafruit_Learning_System_Guides 
