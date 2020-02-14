#include "Arduino.h"
#include "InputManager.h"
#include "DisplayManager.h"

#define BUZZER_PIN D5

microboy::InputManager inputManager;
microboy::DisplayManager *displayManager;

int x = 0;
int y = 0;

void draw()
{
	displayManager->setPixel(x, y);
}

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

void loop()
{
	microboy::Action value = inputManager.read();

	switch (value)
	{
	case microboy::UP:
		y -= 1;
		break;
	case microboy::DOWN:
		y += 1;
		break;
	case microboy::LEFT:
		x -= 1;
		break;
	case microboy::RIGHT:
		x += 1;
		break;
	case microboy::ACTION:
		Serial.println("ACTION");
		break;
	default:
		break;
	}

	if (x < 0) { x = 0; }
	if (y < 0) { y = 0; }
	if (x > MAX_WIDTH) { x = MAX_WIDTH; }
	if (y > MAX_HEIGHT) { y = MAX_HEIGHT; }

	Serial.print(x);
	Serial.print(" , ");
	Serial.println(y);

	displayManager->update();

	delay(10);
}