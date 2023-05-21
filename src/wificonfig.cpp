#include "wificonfig.h"

namespace wifi
{
    WiFiClient client;

    void init(void)
    {
        display::clear();
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

        display::println("Connecting...", 0, 1, display::font_6x8);

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
    }

    void printStatus(void)
    {
        debug::println(debug::INFO, "Connected to: " + String(WiFi.SSID()) + " (" + String(WiFi.RSSI()) + "dBm)");
        debug::println(debug::INFO, "Local IP: " + getLocalIp(WiFi.localIP()));
    }

    String getLocalIp(IPAddress ip)
    {
        String addr;
        for (u8 i = 0; i < 3; ++i)
        {
            addr += String(ip[i], DEC);
            addr += ".";
        }
        addr += String(ip[3]);
        return addr;
    }
}