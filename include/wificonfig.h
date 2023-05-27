#ifndef WIFICONFIG_H
#define WIFICONFIG_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <WiFi101.h>
#include "wificredentials.h"
#include "debug.h"

/**
 * @brief Hardware pinout for WiFi expansion board
 * @note See: https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500
 */
#define WIFISHIELD_PINS 8, 7, 4, 2

namespace wifi
{
    /**
     * @brief WiFi client object.
     */
    extern WiFiClient client;
    void init(void);
    void printStatus(void);
    String getLocalIp(IPAddress ip);
}

#endif /* WIFICONFIG_H */