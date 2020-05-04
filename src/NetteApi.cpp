#include "NetteApi.hpp"
#include <HTTPClient.h>
#include <vector>

NetteApi::NetteApi(String serverName)
{
    _serverName = serverName;
}

NetteApi::~NetteApi()
{
}

String NetteApi::GetReqest(String reqest)
{
  // Code is from https://techtutorialsx.com/2017/05/19/esp32-http-get-requests/
  if(WiFi.status()== WL_CONNECTED)
  {
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(_serverName+"/"+reqest);
 
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
  else
  {
    Serial.println("No internet connection");
  }
  
}


/**
 * POST request - text/plain
 * @param String request raw request
 * @return struct output - [int code, String main] 
*/
NetteApi::output NetteApi::PostReqest(String reqest)
{
  //Code is from https://techtutorialsx.com/2017/05/20/esp32-http-post-requests/
  output postOutput;
  

  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
    
    HTTPClient http;   
    
    http.begin(_serverName);  //Specify destination for HTTP request
    http.addHeader("Content-Type", "text/plain");             //Specify content-type header
    
    int httpResponseCode = http.POST(reqest);   //Send the actual POST request
    
    if(httpResponseCode>0){
    
      String response = http.getString();                       //Get the response to the request
    
      // Serial.println(httpResponseCode);   //Print return code
      // Serial.println(response);           //Print request answer
      postOutput.code = httpResponseCode;
      postOutput.main = response;
      return postOutput;
    
    }
    else
    {
      // Serial.print("Error on sending POST: ");
      // Serial.println(httpResponseCode);
      postOutput.code = NO_SEND;
      postOutput.main = "Error on sending POST";
    }
    
    http.end();  //Free resources
    
  }else
  {  
    // Serial.println("No internet connection");
    postOutput.code = NO_INTERNET;
    postOutput.main = "No internet connection";
  }

  return postOutput;

}