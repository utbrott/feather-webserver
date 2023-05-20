#include "wificonfig.h"

WiFiClient client;

namespace wifi
{
    void init(void)
    {
        debug::println(debug::INFO, "Trying to init WiFi module...");
        WiFi.setPins(WIFISHIELD_PINS);

        // Check if WiFi module is present
        if (WiFi.status() == WL_NO_SHIELD)
        {
            debug::println(debug::ERR, "WiFi module init fail (disconnected?)");
            while (true)
            {
                // Pause forever
            }
        }

        pinMode(LED_BUILTIN, OUTPUT);
        debug::println(debug::INFO, "Attempting connection to: " + String(WIFI_SSID));

        /* TODO: Display on screen */

        while (WiFi.status() != WL_CONNECTED)
        {
            WiFi.begin(WIFI_SSID, WIFI_PASS);

            digitalWrite(LED_BUILTIN, 1);
            delay(250);
            digitalWrite(LED_BUILTIN, 0);
            delay(250);
        }

        digitalWrite(LED_BUILTIN, 1);

        printStatus();

        /* TODO: Display on screen */
    }

    void printStatus(void)
    {
        debug::println(debug::INFO, "Connected to: " + String(WiFi.SSID()) + " (" + String(WiFi.RSSI()) + "dBm)");
    }
}