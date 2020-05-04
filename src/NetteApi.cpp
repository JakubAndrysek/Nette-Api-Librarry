#include "NetteApi.hpp"
#include <HTTPClient.h>

NetteApi::NetteApi(String serverName)
{
    _serverName = serverName;
}

NetteApi::~NetteApi()
{
}

String NetteApi::GetReqest(String reqest)
{
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(_serverName+"/"+reqest);
    //http.begin("http://192.168.0.148/Nette/pletacka-website-nette/api/v1/thisSensor/add-event/Pletacka2/work");
    //http.begin("http://192.168.0.148/Nette/pletacka-website-nette/api/v1/thissensor/ping");
    // http.begin("http://192.168.0.148/Nette/pletacka-website-nette/api/v1/thisSensor/add-event/Pletacka2/rework");
    // http.begin("http://192.168.0.148/Nette/pletacka-website-nette/api/v1/sensors/find-name/pl");

    
    // Specify content-type header
    // http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Prepare your HTTP POST request data
    // String httpRequestData =  "&value1=" + String(text) + "";
    // Serial.print("httpRequestData: ");
    // Serial.println(httpRequestData);

    // You can comment the httpRequestData variable above
    // then, use the httpRequestData variable below (for testing purposes without the BME280 sensor)
    //String httpRequestData = "api_key=tPmAT5Ab3j7F9&sensor=BME280&location=Office&value1=24.75&value2=49.54&value3=1005.14";

    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
}