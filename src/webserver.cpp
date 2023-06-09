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
        for (String line : httpHeader)
        {
            wifi::client.println(line);
        }
        wifi::client.println();

        for (String line : webpageHead)
        {
            wifi::client.println(line);
        }

        for (u8 i = 0; i < ARRAYSIZE(webpageBody); ++i)
        {
            if (i == BODY_TAB_IDX)
            {
                printRow(data->temperature, "Temperature [&deg;C]");
                printRow(data->pressure, "Pressure [hPa]");
                printRow(data->humidity, "Humidity [%]");
                printRow(data->failedPercent, "Failed req. [%]");
                continue; // Skip printing from array
            }
            wifi::client.println(webpageBody[i]);
        }
    }

    template <typename T, size_t size, size_t length>
    void printRow(const T (&array)[size], const char (&rowTitleStr)[length])
    {
        static u8 fmtCharCount = 15;
        char line[length + fmtCharCount];

        sprintf(line, "<tr><td>%s</td>", rowTitleStr);
        wifi::client.println(line);

        // Template type does not matter, values cast to f32 for display
        for (T value : array)
        {
            char cell[25];
            sprintf(cell, "<td>%.1f</td>", (f32)value);
            wifi::client.println(cell);
        }

        wifi::client.println("</tr>");
    }
}