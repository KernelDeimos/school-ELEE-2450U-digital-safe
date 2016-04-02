#include "Dial.h"

int POT_PIN = 2;
int LED_PIN = 13;
int val = 0;

Dial *dial;

void setup() {
	pinMode(LED_PIN, OUTPUT);
	dial = new Dial();
}

void loop() {
	val = analogRead(POT_PIN);
	dial->update_value(val);
	digitalWrite(LED_PIN, HIGH);
	delay((dial->get_value_as_int()+1) * 100);
	digitalWrite(LED_PIN, LOW);
	delay((dial->get_value_as_int()+1) * 100);
}
