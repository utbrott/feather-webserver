#include "main.h"


void setup()
{
    Serial.begin(115200);

    display::init();
    display::initIo();
    display::clear();

    wifi::init();
    webserver::init();
    attachInterrupt(digitalPinToInterrupt(BTN_A), webserver::printIp, RISING);
}

void loop()
{
}