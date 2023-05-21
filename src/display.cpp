#include "display.h"

Adafruit_SSD1306 ssd1306 = Adafruit_SSD1306(128, 32, &Wire);

namespace display
{
    void init(void)
    {
        ssd1306.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDR);
        ssd1306.display();
        ssd1306.setTextSize(font_6x8);
        ssd1306.setTextColor(SSD1306_WHITE);
        ssd1306.setCursor(0, 0);
    }

    void initIo(void)
    {
        pinMode(BTN_A, INPUT_PULLUP);
        pinMode(BTN_B, INPUT_PULLUP);
        pinMode(BTN_C, INPUT_PULLUP);
    }

    void clear(void)
    {
        ssd1306.clearDisplay();
        ssd1306.display();
        ssd1306.setCursor(0, 0);
    }

    void println(String text, u8 col = 0, u8 row = 0, TextSize size = font_6x8)
    {
        ssd1306.setTextSize(size);
        ssd1306.setCursor(col * (size * BASEFONT_WIDTH), row * (size * BASEFONT_HEIGHT));
        ssd1306.println(text);
        ssd1306.display();
    }
}