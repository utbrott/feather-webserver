#include "main.h"

StoredData_t storedData = {
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
};

u32 timeoutTimer = 0;

void setup()
{
    Wire.begin(I2C_ADDR);
    Wire.onReceive(i2cReceive);
    Serial.begin(115200);

    wifi::init();
    webserver::init();
}

void loop()
{
    wifi::client = webserver::server.available();
    if (wifi::client)
    {
        timeoutTimer = millis();
        String currentLine = "";

        while (wifi::client.connected() &&
               (millis() - timeoutTimer) <= CLIENT_TIMEOUT)
        {
            /**
             * Process request from the connecting client
             */
            timeoutTimer = millis();
            if (!wifi::client.available())
            {
                continue;
            }

            char c = wifi::client.read();
            webserver::header += c;

            if (c == '\n')
            {
                if (currentLine.length() == 0)
                {
                    webserver::serve(&storedData);
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
    }
}

void i2cReceive(int byteCount)
{
    // Build a string from I2C transmission
    String recv;
    while (Wire.available() > 0)
    {
        char recvChar = Wire.read();
        recv += recvChar;
    }

    // Decode into values
    decodeStr(&recv, &storedData);
}

void decodeStr(String *recv, StoredData_t *data)
{
    /**
     * Alloc char array for input string
     * Add 0 to the end of C string
     */
    char recvArray[recv->length() + 1];
    recv->toCharArray(recvArray, recv->length());
    recvArray[recv->length()] = 0;

    // Keeps count for each struct member
    u8 dataCounter[4] = {0, 0, 0, 0};

    /**
     * Read key-value pairs
     * Split string on `&` -> each key-value pair
     * Split pairs on `:` -> key : value
     */
    char *keyToken = strtok(recvArray, "&");
    while (keyToken != NULL)
    {
        char *valueToken = strchr(keyToken, ':');
        if (valueToken != 0)
        {
            *valueToken = 0;
            int key = atoi(keyToken);
            ++valueToken;

            // Assign value from valueToken to correct struct member
            switch (key)
            {
            case TEMPERATURE:
                data->temperature[dataCounter[TEMPERATURE]++] =
                    (f32)atoi(valueToken) / 100.0f;
                break;
            case PRESSURE:
                data->pressure[dataCounter[PRESSURE]++] = (f32)atoi(valueToken);
                break;
            case HUMIDITY:
                data->humidity[dataCounter[HUMIDITY]++] =
                    (f32)atoi(valueToken) / 100.0f;
                break;
            case FAILPERCENT:
                data->failedPercent[dataCounter[FAILPERCENT]++] =
                    (f32)atoi(valueToken) / 100.0f;
                break;
            }
        }
        keyToken = strtok(NULL, "&");
    }
}
