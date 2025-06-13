#include <Arduino.h>
#include "esp_camera.h"
#include "app_httpd.h"

static esp_err_t stream_handler(httpd_req_t *req) {
  Serial.println("📡 MJPEG stream available at /");
  camera_fb_t *fb = NULL;
  char *part_buf[64];
  static const char* _STREAM_CONTENT_TYPE = "multipart/x-mixed-replace;boundary=frame";
  static const char* _STREAM_BOUNDARY = "\r\n--frame\r\n";
  static const char* _STREAM_PART = "Content-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n";

  httpd_resp_set_type(req, _STREAM_CONTENT_TYPE);

  while (true) {
    fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("❌ Camera capture failed");
      continue;
    }

    size_t hlen = snprintf((char *)part_buf, 64, _STREAM_PART, fb->len);
    httpd_resp_send_chunk(req, _STREAM_BOUNDARY, strlen(_STREAM_BOUNDARY));
    httpd_resp_send_chunk(req, (const char *)part_buf, hlen);
    httpd_resp_send_chunk(req, (const char *)fb->buf, fb->len);
    esp_camera_fb_return(fb);
  }

  return ESP_OK;
}

esp_err_t startCameraServer() {
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  config.server_port = 80;

  httpd_uri_t stream_uri = {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = stream_handler,
    .user_ctx  = NULL
  };

  httpd_handle_t stream_httpd = NULL;
  if (httpd_start(&stream_httpd, &config) == ESP_OK) {
    httpd_register_uri_handler(stream_httpd, &stream_uri);
    return ESP_OK;
  }

  Serial.println("❌ Failed to start HTTP server");
  return ESP_FAIL;
}
