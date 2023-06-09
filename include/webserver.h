#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <Arduino.h>
#include <SPI.h>
#include <WiFi101.h>
#include "wificonfig.h"
#include "webpage.h"

#define SERVER_PORT 80
#define BODY_TAB_IDX 7

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
    void serve(StoredData_t *data);

    template <typename T, size_t size, size_t length>
    void printRow(const T (&array)[size], const char (&rowTitleStr)[length]);
}

#endif /* WEBSERVER_H */