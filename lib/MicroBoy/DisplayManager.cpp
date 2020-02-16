#include "DisplayManager.h"

namespace microboy
{
DisplayManager::DisplayManager() : display1(0x3d, D2, D1), display2(0x3c, D2, D1), draw(NULL)
{
	display1.init();
	display1.flipScreenVertically();
	display1.setFont(ArialMT_Plain_10);
	display1.setTextAlignment(TEXT_ALIGN_LEFT);
	// display1.invertDisplay();
	display1.clear();
	display1.display();

	display2.init();
	display2.flipScreenVertically();
	display2.setFont(ArialMT_Plain_10);
	display2.setTextAlignment(TEXT_ALIGN_LEFT);
	// display2.invertDisplay();
	display2.clear();
	display2.display();
}

void DisplayManager::setup(void (*drawFunc)())
{
	draw = drawFunc;
}

void DisplayManager::update(void)
{
	display1.clear();
	display2.clear();

	if (draw != NULL)
	{
		draw();
	}

	display1.display();
	display2.display();
}

// Other functions

void DisplayManager::invertDisplay(void)
{
	display1.invertDisplay();
	display2.invertDisplay();
}

void DisplayManager::normalDisplay(void)
{
	display1.normalDisplay();
	display2.normalDisplay();
}

// Draw Funcs

void DisplayManager::setPixel(int16_t x, int16_t y)
{
	display1.setPixel(x, y);
	display2.setPixel(x - HALF_WIDTH, y);
}

void DisplayManager::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
	display1.drawLine(x0, y0, x1, y1);
	display2.drawLine(x0 - HALF_WIDTH, y0, x1 - HALF_WIDTH, y1);
}

void DisplayManager::drawCircle(int16_t x, int16_t y, int16_t radius)
{
	display1.drawCircle(x, y, radius);
	display2.drawCircle(x - HALF_WIDTH, y, radius);
}

void DisplayManager::fillCircle(int16_t x, int16_t y, int16_t radius)
{
	display1.fillCircle(x, y, radius);
	display2.fillCircle(x - HALF_WIDTH, y, radius);
}

void DisplayManager::drawRect(int16_t x, int16_t y, int16_t width, int16_t height)
{
	display1.drawRect(x, y, width, height);
	display2.drawRect(x - HALF_WIDTH, y, width, height);
}

void DisplayManager::fillRect(int16_t x, int16_t y, int16_t width, int16_t height)
{
	display1.fillRect(x, y, width, height);
	display2.fillRect(x - HALF_WIDTH, y, width, height);
}

void DisplayManager::drawHorizontalLine(int16_t x, int16_t y, int16_t length)
{
	display1.drawHorizontalLine(x, y, length);
	display2.drawHorizontalLine(x - HALF_WIDTH, y, length);
}
void DisplayManager::drawVerticalLine(int16_t x, int16_t y, int16_t length)
{
	display1.drawVerticalLine(x, y, length);
	display2.drawVerticalLine(x - HALF_WIDTH, y, length);
}

void DisplayManager::drawFastImage(int16_t x, int16_t y, int16_t width, int16_t height, const uint8_t *image)
{
	display1.drawFastImage(x, y, width, height, image);
	display2.drawFastImage(x - HALF_WIDTH, y, width, height, image);
}

void DisplayManager::drawXbm(int16_t x, int16_t y, int16_t width, int16_t height, const uint8_t *xbm)
{
	display1.drawXbm(x, y, width, height, xbm);
	display2.drawXbm(x - HALF_WIDTH, y, width, height, xbm);
}

} // namespace microboy