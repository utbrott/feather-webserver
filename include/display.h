#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "globals.h"

/**
 * @brief Button pin definitions on the display expansion board
 */

#define BTN_A 9
#define BTN_B 6
#define BTN_C 5

#define DISPLAY_ADDR 0x3C
#define BASEFONT_WIDTH 6
#define BASEFONT_HEIGHT 8

namespace display
{
    enum TextSize : u8
    {
        font_6x8 = 1,
        font_12x16 = 2,
        font_18x24 = 3,
    };

    void init(void);
    void initIo(void);
    void clear(void);
    void println(String text, u8 col, u8 row, TextSize size);
}

#endif /* DISPLAY_H */