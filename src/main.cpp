#include "main.h"

void setup()
{
  Serial.begin(115200);

  display::initScreen();
  display::clear();
  display::initIo();
  display::initText();
}

void loop()
{
}