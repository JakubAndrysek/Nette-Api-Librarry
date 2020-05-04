# pragma once

#include <Arduino.h>

class NetteApi
{
    private:
        String _serverName;
        
    public:
        NetteApi(String serverName);
        ~NetteApi();
        String GetReqest(String reqest);
};


