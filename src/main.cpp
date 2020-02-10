#include "Arduino.h"
#include "InputManager.h"
#include "Wire.h"
#include "SSD1306Wire.h"

SSD1306Wire display1(0x3c, D2, D1); // ADDRESS, SDA, SCL
SSD1306Wire display2(0x3d, D2, D1); // ADDRESS, SDA, SCL

microboy::InputManager inputManager;

void setup()
{
	Serial.begin(115200);
	while (!Serial)
	{
	}

	Serial.println("\nstarting...");

	// Initialising the UI will init the display too.
	display1.init();
	display2.init();

	display1.flipScreenVertically();
	display1.setFont(ArialMT_Plain_10);
	display1.setTextAlignment(TEXT_ALIGN_LEFT);

	display2.flipScreenVertically();
	display2.setFont(ArialMT_Plain_10);
	display2.setTextAlignment(TEXT_ALIGN_LEFT);

	// display1.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	// display2.begin(SSD1306_SWITCHCAPVCC, 0x3D);
}

void loop()
{
	display1.clear();
	display1.setColor(INVERSE);
	display1.drawString(0, 0, "Hello world 1: " + String(millis()));
	display1.display();

	display2.clear();
	display2.drawString(0, 0, "Hello world 2: " + String(millis()));
	display2.display();

	delay(10);
}