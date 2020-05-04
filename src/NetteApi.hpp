# pragma once

#include <Arduino.h>

class NetteApi
{


    private:
        String _serverName;
        struct output
        {
            int code;
            String main;
        };
        enum returnCode
        {
            NO_SEND = 0,
            NO_INTERNET = -1,
        };
    public:
        

        NetteApi(String serverName);
        ~NetteApi();
        NetteApi::output GetReqest(String reqest);
        NetteApi::output PostReqest(String reqest);
        
};


