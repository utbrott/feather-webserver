#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <Arduino.h>
#include <SPI.h>
#include <WiFi101.h>
#include "wificonfig.h"
#include "display.h"

#define SERVER_PORT 80

namespace webserver
{
    /**
     * @brief Webserver object. Needs to be initialized with a port.
     */
    extern WiFiServer server;

    /**
     * @brief HTTP request storage variable.
     */
    extern String header;

    void init(void);
    void printIp(void);
}

#endif /* WEBSERVER_H */