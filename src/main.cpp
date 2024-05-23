#include <WiFi.h>
#include <WebServer.h>
#include <wifi_config.h>
#include <ArduinoJson.h>

#define LED_PIN 8

WebServer server(80);

String website() {
  String ptr = R"(
<!DOCTYPE html>
<html lang="en">
  <head>
    <title>Solar Monitor</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
    <style>
      html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
      body {margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}
      p {font-size: 14px;color: #888;margin-bottom: 10px;}
    </style>
  </head>
  <body>
    <h1>ESP32 Web Server</h1>
    <h3>Using Access Point(AP) Mode</h3>
    <script>
      function run() {
        // Creating Our XMLHttpRequest object 
        let xhr = new XMLHttpRequest();

        // Making our connection  
        xhr.open("GET", '/data', true);

        // function execute after request is successful 
        xhr.onreadystatechange = function () {
            if (this.readyState == 4 && this.status == 200) {
                alert(this.responseText);
            }
        }
        // Sending our request 
        xhr.send();
      }
      run();
    </script>
  </body>
</html>  
  )";

  return ptr;
}

void requestRoot() {
  Serial.println("request: GET /");
  server.send(200, "text/html", website()); 
}

void requestData() {
  Serial.println("request: GET /data");

  // create json document
  JsonDocument doc;
  doc["sensor"] = "gps";
  doc["time"] = 1351824120;
  doc["data"][0] = 48.756080;
  doc["data"][1] = 2.302038;

  // convert to string
  String json;
  serializeJson(doc, json);

  // respond
  server.send(200, "text/json", json); 
}

void requestNotFound() {
  Serial.println("request: NOT FOUND");
  server.send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("start wifi ap");
  WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
  delay(100);
  
  Serial.println("start server");
  server.on("/", requestRoot);
  server.on("/data", requestData);
  server.onNotFound(requestNotFound);
  server.begin();
}

void loop() {
  server.handleClient();
}
