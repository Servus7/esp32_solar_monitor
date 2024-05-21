#include <Arduino.h>
#include <WiFi.h>

const char* ssid     = "ESP32-Access-Point";
const char* password = "123456789";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.begin();
}

void loop() {
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) {
    Serial.println("New Client."); 
  }
}
