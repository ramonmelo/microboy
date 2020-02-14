#include "DisplayManager.h"

namespace microboy
{
DisplayManager::DisplayManager() : display1(0x3d, D2, D1), display2(0x3c, D2, D1), draw(NULL)
{
	display1.init();
	display1.flipScreenVertically();
	display1.setFont(ArialMT_Plain_10);
	display1.setTextAlignment(TEXT_ALIGN_LEFT);
	display1.clear();
	display1.display();

	display2.init();
	display2.flipScreenVertically();
	display2.setFont(ArialMT_Plain_10);
	display2.setTextAlignment(TEXT_ALIGN_LEFT);
	display2.clear();
	display2.display();
}

void DisplayManager::setup(void (*drawFunc)())
{
	draw = drawFunc;
}

void DisplayManager::update()
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

// Draw Funcs

void DisplayManager::setPixel(int16_t x, int16_t y)
{
	if (x < HALF_WIDTH)
	{
		display1.setPixel(x, y);
	}
	else
	{
		x -= HALF_WIDTH;
		display2.setPixel(x, y);
	}
}

} // namespace microboy