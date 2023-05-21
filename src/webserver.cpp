#include "webserver.h"

namespace webserver
{
    WiFiServer server(SERVER_PORT);
    String header;

    void init(void)
    {
        while (WiFi.status() != WL_CONNECTED)
        {
            // Wait for WiFi to connect before starting server
        }

        debug::println(debug::INFO, "Webserver started on port " + String(SERVER_PORT, DEC));
        server.begin();
        display::clear();
        display::println("Webserver started:", 0, 1, display::font_6x8);
        display::println(wifi::getLocalIp(WiFi.localIP()), 0, 2, display::font_6x8);
    }

    void printIp(void)
    {
        display::clear();
        display::println("Webserver IP:", 0, 1, display::font_6x8);
        display::println(wifi::getLocalIp(WiFi.localIP()), 0, 2, display::font_6x8);
    }

}