#include <Arduino.h>
#include "NetteApi.hpp"
#include <WiFi.h>
#include <HTTPClient.h>


#define SSID       "SSID"
#define PASSWORD   "PASSWORD"
#include "credentials.h"

NetteApi addEvent("http://example.com/api/sensors/add-event");
NetteApi json("http://example.com/api/v1/sensors/create");

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
  addEvent.GetReqest("Pletacka2/on");
  delay(2000);
}

void loop() {
  auto postReturn = json.PostReqest("{\"number\": \"15\",\"name\": \"Plete15\",\"description\": \"\"}");
  Serial.println("Post return : "+String(postReturn.code)+" ->\""+String(postReturn.main));
  delay(5000);
}