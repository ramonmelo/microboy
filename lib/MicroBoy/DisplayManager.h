#pragma once

#define WIDTH 128 * 2
#define HEIGHT 64
#define MAX_WIDTH WIDTH - 1
#define MAX_HEIGHT HEIGHT - 1
#define HALF_WIDTH WIDTH / 2

#include "Arduino.h"
#include "Wire.h"
#include "SSD1306Wire.h"

namespace microboy
{
class DisplayManager
{
public:
	DisplayManager();

	void setup(void (*drawFunc)());
	void update(void);

	// Drawing Functions
	void setPixel(int16_t x, int16_t y);
	void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
	void drawCircle(int16_t x, int16_t y, int16_t radius);
	void fillCircle(int16_t x, int16_t y, int16_t radius);
	void drawRect(int16_t x, int16_t y, int16_t width, int16_t height);
	void fillRect(int16_t x, int16_t y, int16_t width, int16_t height);
	void drawHorizontalLine(int16_t x, int16_t y, int16_t length);
	void drawVerticalLine(int16_t x, int16_t y, int16_t length);

	void drawFastImage(int16_t x, int16_t y, int16_t width, int16_t height, const uint8_t *image);
	void drawXbm(int16_t x, int16_t y, int16_t width, int16_t height, const uint8_t *xbm);

	void invertDisplay(void);
	void normalDisplay(void);

private:
	SSD1306Wire display1; // ADDRESS, SDA, SCL
	SSD1306Wire display2; // ADDRESS, SDA, SCL
	void (*draw)();
};
} // namespace microboy
