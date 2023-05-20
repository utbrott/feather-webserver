#include "main.h"

void setup()
{
  Serial.begin(115200);

  display::init();
  display::initIo();
  display::clear();

  wifi::init();
}

void loop()
{
}