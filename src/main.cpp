#include "Arduino.h"

#include "InputManager.h"
#include "DisplayManager.h"

#include "image.h"

#define BUZZER_PIN D5

microboy::InputManager inputManager;
microboy::DisplayManager *displayManager;

void draw();

int x = 0;
int y = 0;
int curr_frame = 0;

microboy::Action lastAction;

void setup()
{
	Serial.begin(115200);
	while (!Serial)
	{
	}

	pinMode(BUZZER_PIN, OUTPUT);
	digitalWrite(BUZZER_PIN, LOW);

	Serial.println("\nstarting...");

	displayManager = new microboy::DisplayManager();
	displayManager->setup(draw);
}

void draw()
{
	// displayManager->setPixel(x, y);

	// displayManager->drawCircle(x, y, 4);
	// displayManager->fillCircle(x, y, 2);

	// displayManager->drawHorizontalLine(x, y, 10);
	// displayManager->drawVerticalLine(x, y, 10);

	displayManager->drawXbm(x, y, FRAME_WIDTH, FRAME_HEIGHT, frames[curr_frame]);

	//   display->drawXbm(x + 34, y + 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);

	// displayManager->fillRect(x, y, 50, 50);

	// displayManager->drawLine(23, 14, 213, 50);
}

void nextFrame()
{
	curr_frame += 1;
	if (curr_frame == NUMBER_FRAMES)
	{
		curr_frame = 0;
	}
}

void loop()
{
	lastAction = inputManager.read();

	switch (lastAction)
	{
	case microboy::UP:
		y -= 1;
		nextFrame();
		break;
	case microboy::DOWN:
		y += 1;
		nextFrame();
		break;
	case microboy::LEFT:
		x -= 1;
		nextFrame();
		break;
	case microboy::RIGHT:
		x += 1;
		nextFrame();
		break;
	case microboy::ACTION:
		Serial.println("ACTION");
		break;
	default:
		break;
	}

	if (x < 0)
	{
		x = 0;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (x > MAX_WIDTH)
	{
		x = MAX_WIDTH;
	}
	if (y > MAX_HEIGHT)
	{
		y = MAX_HEIGHT;
	}

	displayManager->update();

	delay(20);
}