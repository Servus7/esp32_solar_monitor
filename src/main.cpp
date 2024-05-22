#include <WiFi.h>
#include <WebServer.h>

#define LED_PIN 8

const char* ssid     = "ESP32-Access-Point";
const char* password = "123456789";

WebServer server(80);
bool ledOn = false;

String website(uint8_t ledOn) {
  String ptr = R"(
    <!DOCTYPE html>
    <html>
      <head><meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
      <title>Solar Boat Monitor</title>
      <style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
        body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}
        .button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}
        .button-on {background-color: #3498db;}
        .button-on:active {background-color: #2980b9;}
        .button-off {background-color: #34495e;}
        .button-off:active {background-color: #2c3e50;}
        p {font-size: 14px;color: #888;margin-bottom: 10px;}
      </style>
    </head>
    <body>
      <h1>ESP32 Web Server</h1>
      <h3>Using Access Point(AP) Mode</h3>
  )";
  
  if (ledOn) {
    ptr +="<p>LED Status: ON</p><a class=\"button button-off\" href=\"/led/off\">OFF</a>\n";
  } else {
    ptr +="<p>LED Status: OFF</p><a class=\"button button-on\" href=\"/led/on\">ON</a>\n";
  }

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}

void handle_OnConnect() {
  server.send(200, "text/html", website(ledOn)); 
}

void handle_ledOn() {
  ledOn = true;
  server.send(200, "text/html", website(true)); 
}

void handle_ledOff() {
  ledOn = false;
  server.send(200, "text/html", website(false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  WiFi.softAP(ssid, password);

  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/led/on", handle_ledOn);
  server.on("/led/off", handle_ledOff);
  server.onNotFound(handle_NotFound);
  
  server.begin();
}

void loop() {
  server.handleClient();

  digitalWrite(LED_PIN, ledOn ? LOW : HIGH);
}
