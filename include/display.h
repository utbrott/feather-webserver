#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/**
 * @brief Button pin definitions on the display expansion board
 */

#define BTN_A 9
#define BTN_B 6
#define BTN_C 5

#define DISPLAY_ADDR 0x3C

namespace display
{
    void init(void);
    void initIo(void);
    void clear(void);
}

#endif /* DISPLAY_H */