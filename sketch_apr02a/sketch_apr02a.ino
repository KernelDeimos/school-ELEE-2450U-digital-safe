#include "pins.h"

#include "DigitalSafe.h"

int val = 0;

DigitalSafe *ds;

void setup() {
	Serial.begin(9600);
	pinMode(CLK_BEEP_PIN, OUTPUT);
	pinMode(FEEDBACK_PIN, OUTPUT);

	pinMode(LED_R, OUTPUT);
	pinMode(LED_B, OUTPUT);
	pinMode(LED_G, OUTPUT);

	pinMode(OUTSIDE_BUTTON_PIN, INPUT);

	ds = new DigitalSafe();
}

void loop() {
	ds->loop();
}

