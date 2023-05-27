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
    }

    void serve(StoredData_t *data)
    {
        for (u8 i = 0; i < ARRAYSIZE(httpHeader); ++i)
        {
            wifi::client.println(httpHeader[i]);
        }
        wifi::client.println();

        for (u8 i = 0; i < ARRAYSIZE(webpageHead); ++i)
        {
            wifi::client.println(webpageHead[i]);
        }

        for (u8 i = 0; i < ARRAYSIZE(webpageBody); ++i)
        {
            if (i == BODY_TAB_IDX)
            {
                serveData(data);
                continue; // Skip printing from array
            }
            wifi::client.println(webpageBody[i]);
        }
    }

    void serveData(StoredData_t *data)
    {
        wifi::client.println("<tr><td>Temperature (&deg;C)</td>");
        for (u8 i = 0; i < 3; ++i)
        {
            wifi::client.println("<td>");
            wifi::client.println(data->temperature[i]);
            wifi::client.println("</td>");
        }
        wifi::client.println("</tr>");

        wifi::client.println("<tr><td>Pressure (hPa)</td>");
        for (u8 i = 0; i < 3; ++i)
        {
            wifi::client.println("<td>");
            wifi::client.println(data->pressure[i]);
            wifi::client.println("</td>");
        }
        wifi::client.println("</tr>");

        wifi::client.println("<tr><td>Humidity (%)</td>");
        for (u8 i = 0; i < 3; ++i)
        {
            wifi::client.println("<td>");
            wifi::client.println(data->humidity[i]);
            wifi::client.println("</td>");
        }
        wifi::client.println("</tr>");
    }
}