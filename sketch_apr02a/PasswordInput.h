#include "pins.h";
#include "utils.h"
#include "Arduino.h";

#ifndef PASSWORDINPUT_H
#define PASSWORDINPUT_H

const int PASSWORD_INPUT_CYCLE = 100;

class PasswordInput {
private:
	Dial *dial;
	unsigned long last_millis;
public:
	PasswordInput(Dial *dial);
	void update_time(unsigned long millis);
	void _on_password_input();
};

PasswordInput::PasswordInput(Dial *dial) {
	this->dial = dial;
}

void PasswordInput::update_time(unsigned long millis) {
	if (millis - last_millis >= PASSWORD_INPUT_CYCLE) {
		last_millis = millis;
		_on_password_input();
	}
}

void PasswordInput::_on_password_input() {
	// Get digit entry from the dial
	int passwd = dial->get_value_as_int();
	Serial.println(passwd);
	// Write the value to the LED
	digitalWrite(LED_R, (passwd==1 || passwd==3 || passwd==5 || passwd==7) ? HIGH : LOW);
	digitalWrite(LED_G, (passwd==2 || passwd==3 || passwd==6 || passwd==7) ? HIGH : LOW);
	digitalWrite(LED_B, (passwd>=4) ? HIGH : LOW);


	for (int i=0; i < 100; i++) {
		digitalWrite(CLK_BEEP_PIN, HIGH);
		delay(1);
		digitalWrite(CLK_BEEP_PIN, LOW);
		delay(1);
	}
	Serial.println("Beep!");
}

#endif
