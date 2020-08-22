#include "NetteApi.hpp"
#include <HTTPClient.h>
#include <vector>

NetteApi::NetteApi()
{
  
}

NetteApi::NetteApi(String serverName)
{
    _serverName = serverName;
}


NetteApi::~NetteApi()
{
}

void NetteApi::setServerName(String serverName)
{
  _serverName = serverName;
}

String NetteApi::getServerName()
{
  return _serverName;
}

/**
 * @brief GET request
 * 
 * @param reqest request raw request
 * @return NetteApi::output - [int code, String main, String request] 
 */
NetteApi::output NetteApi::GetReqest(String reqest)
{
  output getOutput;
  
  // Code is from https://techtutorialsx.com/2017/05/19/esp32-http-get-requests/
  if(WiFi.status()== WL_CONNECTED)
  {
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(_serverName+"/"+reqest);
 
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
      String payload = http.getString();
      // Serial.println(httpCode);
      // Serial.println(payload);
      getOutput.code = httpCode;
      getOutput.main = payload;
    }
    else 
    {
      // Serial.print("Error on sending POST: ");
      // Serial.println(httpResponseCode);
      getOutput.code = NO_SEND;
      getOutput.main = "Error on sending GET request";
    }
    
    http.end();  //Free resources
    
  }
  else
  {  
    // Serial.println("No internet connection");
    getOutput.code = NO_INTERNET;
    getOutput.main = "No internet connection";
  }

  getOutput.request = String(_serverName+"/"+reqest);

  return getOutput;
  
}


/**
 * @brief POST request
 * 
 * @param String request raw request
 * @return NetteApi::output output - [int code, String main, String request] 
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
      postOutput.main = "Error on sending POST request";
    }
    
    http.end();  //Free resources
    
  }
  else
  {  
    // Serial.println("No internet connection");
    postOutput.code = NO_INTERNET;
    postOutput.main = "No internet connection";
  }

  return postOutput;

}