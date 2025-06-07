
Setting up the AWS IoT Core approach is a fantastic skill to have for any IoT project. It's the professional, secure, and scalable way to handle device communication.

Here is a step-by-step guide to get your ESP32 devices sending JSON data to an S3 bucket using AWS IoT Core.

### The Goal: A Simple, Secure Data Pipeline

This is the flow we are building:

**ESP32 Device** -> (sends JSON over MQTT) -> **AWS IoT Core** -> (IoT Rule triggers) -> **Amazon S3 Bucket**

---

### Phase 1: AWS Console Setup (The Cloud Side)

Log in to your AWS Console and follow these steps.

#### Step 1: Find Your AWS IoT Endpoint

This is the unique server address your ESP32 will connect to. You'll need it later.
1.  Navigate to the **AWS IoT Core** service.
2.  In the left-hand navigation pane, click on **Settings**.
3.  Under **Device data endpoint**, copy the long URL. It will look like `a1b2c3d4e5f6g7-ats.iot.us-east-1.amazonaws.com`. **Save this somewhere safe.**

#### Step 2: Create the S3 Bucket (The Destination)

This is where your JSON files will be stored.
1.  Navigate to the **S3** service.
2.  Click **Create bucket**.
3.  Give it a **globally unique name** (e.g., `my-esp32-data-bucket-` followed by some random numbers).
4.  Choose the same **AWS Region** you are using for IoT Core.
5.  Leave all other settings as default and click **Create bucket**.

#### Step 3: Create the Device Identity (The "Thing" and its Policy)

We need to register a device in IoT Core and define what it's allowed to do.

1.  Navigate back to **AWS IoT Core**.
2.  In the left pane, go to **Manage** -> **Things**.
3.  Click **Create things**.
4.  Choose **Create a single thing** and click **Next**.
5.  Give your thing a **Name** (e.g., `esp32-01`). This name is important and can be used in your code.
6.  Leave the other settings as default and click **Next**.
7.  Under **Device certificate**, choose **Auto-generate a new certificate (recommended)** and click **Next**.
8.  Now, you need to create a **Policy**. A policy is a set of permissions. Click **Create policy**.
    *   **Policy name:** `esp32-allow-publish-policy`
    *   **Policy effect:** `Allow`
    *   **Policy action:** Select `iot:Connect`, `iot:Publish`, `iot:Subscribe`, and `iot:Receive`.
    *   **Policy resource:** This is critical for security. It specifies *which* topics the device can use. Use this ARN, replacing `aws-region` and `aws-account-id` with your own (you can see these in the top right of the console).
        ```json
        arn:aws:iot:aws-region:aws-account-id:topic/devices/${iot:Connection.Thing.ThingName}/*
        arn:aws:iot:aws-region:aws-account-id:client/${iot:Connection.Thing.ThingName}
        ```
        *   **What this does:** It allows the device to connect using its thing name as the client ID and publish/subscribe to any topic that starts with `devices/esp32-01/`. This is a great security practice.
    *   Click **Create**.
9.  Back on the "Create thing" page, select the policy you just created (`esp32-allow-publish-policy`) and click **Create thing**.

10. **CRITICAL STEP:** You will now be on a page to download your credentials. You only get this one chance. Download all of these files and keep them secure:
    *   **Device certificate** (`...-certificate.pem.crt`)
    *   **Private key** (`...-private.pem.key`)
    *   **Public key** (`...-public.pem.key`)
    *   **Root CA certificate**. You'll need a Root CA to verify the AWS server. Click the "Download" link and choose the **Amazon Root CA 1**.

#### Step 4: Create the IoT Rule (The "Glue")

This rule will listen for messages from your device and automatically save them to S3.

1.  In the IoT Core left pane, go to **Message Routing** -> **Rules**.
2.  Click **Create rule**.
3.  **Name:** `saveDeviceDataToS3`
4.  **Rule query statement:** This is like an SQL query for your IoT data. Use this:
    ```sql
    SELECT * FROM 'devices/+/data'
    ```
    *   **What this does:** It selects all data (`*`) from any message published to a topic that matches the pattern `devices/ANYTHING/data`. For example, `devices/esp32-01/data`. The `+` is a single-level wildcard.
5.  **Action:**
    *   Click **Add action**.
    *   Select **Store a message in an Amazon S3 bucket**.
    *   For **S3 bucket**, select the bucket you created in Step 2.
    *   For the **Key**, this is the filename. We can make it dynamic! Use this template:
        ```
        ${topic(2)}/${timestamp()}.json
        ```
        *   **What this does:**
            *   `${topic(2)}`: Takes the second part of the MQTT topic (in `devices/esp32-01/data`, this would be `esp32-01`).
            *   `${timestamp()}`: Adds a unique timestamp to prevent files from overwriting each other.
            *   This will create files in S3 like: `esp32-01/1668631567.json`
6.  **IAM Role:** The rule needs permission to write to S3.
    *   Click **Create a new role**.
    *   Give the role a name (e.g., `iot-rule-s3-access-role`). AWS will automatically generate the correct permissions.
    *   Click **Create role**.
7.  Finally, click **Create rule** at the bottom of the page.

**The cloud setup is now complete!**

---

### Phase 2: ESP32 Code (The Device Side)

Now, let's program the ESP32. This example uses the Arduino IDE and the popular `PubSubClient` library.

#### 1. Install Libraries

In the Arduino IDE Library Manager (`Sketch > Include Library > Manage Libraries...`), install:
*   `PubSubClient` by Nick O'Leary
*   `ArduinoJson` by Benoît Blanchon

#### 2. Store Your Credentials

**Do not** put your secret keys directly in your main `.ino` file. Create a new tab in the Arduino IDE and name it `secrets.h`.

```cpp
// In secrets.h

#include <pgmspace.h>

#define SECRET
#define THINGNAME "esp32-01" // Must match the Thing Name in AWS IoT

const char WIFI_SSID[] = "YourWiFi_SSID";
const char WIFI_PASSWORD[] = "YourWiFi_Password";
const char AWS_IOT_ENDPOINT[] = "a1b2c3d4e5f6g7-ats.iot.us-east-1.amazonaws.com"; // Your endpoint from Step 1

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
-----PASTE YOUR AmazonRootCA1.pem HERE-----
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
-----PASTE YOUR ...-certificate.pem.crt HERE-----
-----END CERTIFICATE-----
)EOF";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
-----PASTE YOUR ...-private.pem.key HERE-----
-----END RSA PRIVATE KEY-----
)EOF";
```

#### 3. The Main Sketch (`.ino` file)

This code connects to WiFi, securely connects to AWS IoT, and publishes a JSON message every 30 seconds.

```cpp
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "secrets.h"

#define AWS_IOT_PORT 8883
#define AWS_IOT_PUBLISH_TOPIC "devices/" THINGNAME "/data"

WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);

void connectAWS() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Configure WiFiClientSecure to use the AWS certificates
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker
  client.setServer(AWS_IOT_ENDPOINT, AWS_IOT_PORT);

  Serial.println("Connecting to AWS IoT");
  while (!client.connect(THINGNAME)) {
    Serial.print(".");
    delay(100);
  }

  if (!client.connected()) {
    Serial.println("AWS IoT Timeout!");
    return;
  }
  
  Serial.println("AWS IoT Connected!");
}

void publishMessage() {
  StaticJsonDocument<200> doc;
  doc["timestamp"] = millis();
  doc["sensor_a"] = random(100);
  doc["sensor_b"] = random(50, 150);

  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer);

  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
  Serial.print("Published to ");
  Serial.print(AWS_IOT_PUBLISH_TOPIC);
  Serial.print(": ");
  Serial.println(jsonBuffer);
}

void setup() {
  Serial.begin(115200);
  connectAWS();
}

void loop() {
  if (!client.connected()) {
    connectAWS();
  }
  client.loop(); // Important to maintain connection
  
  publishMessage();
  delay(30000); // Send data every 30 seconds
}
```

### Final Steps and Testing

1.  Open the `secrets.h` file and paste in your WiFi credentials, your unique AWS IoT endpoint, and the three certificates you downloaded.
2.  Plug in your ESP32, select the correct board and port in the Arduino IDE, and upload the code.
3.  Open the **Serial Monitor** at 115200 baud. You should see it connect to WiFi and then successfully connect to AWS IoT. Every 30 seconds, it will print the JSON message it sent.
4.  Go to your **S3 bucket** in the AWS Console. You should see a new folder named `esp32-01`. Inside, you will find JSON files created every 30 seconds, each containing the data from your device!

You have now successfully set up a robust and secure data pipeline for your ESP32 project. To add your other 11 devices, you simply repeat **Step 3** (Create the Thing and its credentials) and use the new set of certificates for each new device.
