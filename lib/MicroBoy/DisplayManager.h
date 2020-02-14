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
	void update();

	// Drawing Functions
	void setPixel(int16_t x, int16_t y);

	private:
	SSD1306Wire display1; // ADDRESS, SDA, SCL
	SSD1306Wire display2; // ADDRESS, SDA, SCL
	void (*draw)();
};
} // namespace microboy
