# pragma once

#include <Arduino.h>

/**
 * @brief Library for communication between ESP32 and Nette Api
 * 
 */
class NetteApi
{


    private:
        String _serverName;
        struct output
        {
            int code;
            String main;
            String request;
        };
        enum returnCode
        {
            NO_SEND = 0,
            NO_INTERNET = -1,
        };
    public:
        
        /**
         * @brief Nette Api constructor
         * 
         */
        NetteApi();

        /**
         * @brief Nette Api constructor with server name
         * 
         * @param serverName 
         */
        NetteApi(String serverName);

        /**
         * @brief Nette Api destructor
         * 
         */
        ~NetteApi();

        /**
         * @brief Set Server Name
         * 
         * @param serverName 
         */
        void setServerName(String serverName);

        /**
         * @brief Get the Reqest object
         * 
         * @param reqest 
         * @return NetteApi::output 
         */
        NetteApi::output GetReqest(String reqest);

        /**
         * @brief 
         * 
         * @param reqest 
         * @return NetteApi::output 
         */
        NetteApi::output PostReqest(String reqest);
        
};


