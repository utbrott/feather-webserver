#include "main.h"

StoredData_t data = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
StoredData_t dummy = {{25.4, 26.4, 19.8}, {1000.5, 1001.2, 999.9}, {35.1, 36.2, 27.4}};
u32 timeoutTimer = 0;

void receiveEvent(int bytesRead)
{
    debug::println(debug::INFO, "New I2C transmission");
    while (Wire.available() > 0)
    {
        // TODO: Split incoming message into actual data
        char c = Wire.read();
        Serial.write(c);
    }
    debug::println(debug::INFO, "Done");
}

void setup()
{
    Wire.begin(I2C_ADDR);
    Wire.onReceive(receiveEvent);
    Serial.begin(115200);

    // TODO: Use u8g2 to get display back?
    // display::init();
    // display::initIo();
    // display::clear();

    wifi::init();
    webserver::init();
    attachInterrupt(digitalPinToInterrupt(BTN_A), webserver::printIp, RISING);
}

void loop()
{
    wifi::client = webserver::server.available();
    if (wifi::client)
    {
        timeoutTimer = millis();
        String currentLine = "";

        while (wifi::client.connected() && (millis() - timeoutTimer) <= CLIENT_TIMEOUT)
        {
            timeoutTimer = millis();
            if (!wifi::client.available())
            {
                continue;
            }

            char c = wifi::client.read();
            Serial.write(c);
            webserver::header += c;

            if (c == '\n')
            {
                if (currentLine.length() == 0)
                {
                    webserver::serve(&dummy);
                    break;
                }
                currentLine = "";
            }
            else if (c != '\r')
            {
                currentLine += c;
            }
        }
        webserver::header = "";
        wifi::client.stop();
        Serial.println();
    }
}