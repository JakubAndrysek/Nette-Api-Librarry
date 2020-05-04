#include <Arduino.h>
#include "NetteApi.hpp"
#include <WiFi.h>
#include <HTTPClient.h>


#define SERVER      "http://example.com/api/sensors/add-event"
#define SSID       "SSID"
#define PASSWORD   "PASSWORD"
#include "credentials.h"

NetteApi api(SERVER);

void setup() {
  Serial.begin(115200);

  WiFi.begin(SSID, PASSWORD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Start");
  api.GetReqest("Pletacka2/on");
}

void loop() {
  api.GetReqest("Pletacka2/work");
  delay(1000);
  api.GetReqest("Pletacka2/stop");
  delay(1000);
}