#include "main.h"

StoredData_t data = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
StoredData_t dummy = {{25.4, 26.4, 19.8}, {1000.5, 1001.2, 999.9}, {35.1, 36.2, 27.4}};
u32 timeoutTimer = 0;

void receiveEvent(int bytesRead)
{
    debug::println(debug::INFO, "New I2C transmission");
    String recv;
    while (Wire.available() > 0)
    {
        char c = Wire.read();
        recv += c;
    }

    Serial.println(recv);
    u8 dataCount, typeCount;
    String datatype[3];
    String data[DATA_COUNT];
    u16 value[DATA_COUNT];

    while (recv.length() > 0)
    {
        u8 idx = recv.indexOf('\n');
        if (idx == -1)
        {
            datatype[typeCount++] = recv;
            break;
        }

        datatype[typeCount++] = recv.substring(0, recv.indexOf('\n'));
        recv = recv.substring(idx + 1);
    }

    for (u8 i = 0; i < ARRAYSIZE(datatype); ++i)
    {
        String str = datatype[i];
        while (str.length() > 0)
        {
            u8 idx = str.indexOf('\t');
            if (idx == -1)
            {
                data[dataCount++] = str;
                break;
            }

            data[dataCount++] = str.substring(0, str.indexOf('\t'));
            str = str.substring(idx + 1);
        }
    }

    for (u8 i = 0; i < ARRAYSIZE(data); ++i)
    {
        value[i] = data[i].toInt();
        Serial.println(value[i]);
    }

    // TODO: Without dynamic memory alloc, needs fixing to work
    // char recvArray[recv.length() + 1];
    // recv.toCharArray(recvArray, recv.length());

    // u16 recvData[DATA_COUNT];
    // u8 splitItr = -1; // Array is empty

    // char *datatype = strtok(recvArray, "\n");
    // while (datatype != NULL)
    // {
    //     char *data = strchr(datatype, '\t');
    //     if (data != 0)
    //     {
    //         *data = 0;
    //         int datatypeId = atoi(datatype);
    //         ++data;
    //         int dataval = atoi(data);
    //         Serial.println(dataval);
    //     }
    //     datatype = strtok(NULL, "\n");
    // }
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