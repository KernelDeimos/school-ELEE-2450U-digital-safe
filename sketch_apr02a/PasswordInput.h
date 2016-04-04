#include "pins.h";
#include "utils.h"
#include "Arduino.h";

#ifndef PASSWORDINPUT_H
#define PASSWORDINPUT_H

const int PASSWORD_INPUT_CYCLE = 2000;

class PasswordInput {
private:
	Dial *dial;
	unsigned long last_millis;
	boolean last_millis_is_inited;
	int inputs[8];
	int inputs_c; // current input index
public:
	PasswordInput(Dial *dial);
	void update_time(unsigned long millis);
	void _on_password_input();
	boolean is_ready();
	void reset();
};

PasswordInput::PasswordInput(Dial *dial) {
	this->dial = dial;
	inputs_c = 0;
	last_millis_is_inited = false;
}

void PasswordInput::update_time(unsigned long millis) {
	if (!last_millis_is_inited) {
		last_millis_is_inited = true;
		last_millis = millis;
	}
	else
	if (millis - last_millis >= PASSWORD_INPUT_CYCLE) {
		last_millis = millis;
		_on_password_input();
	}
}

void PasswordInput::_on_password_input() {
	// Get digit entry from the dial
	int passwd = dial->get_value_as_int();
	Serial.println(passwd);
	if (inputs_c < 8) {
		inputs[inputs_c++] = passwd;
	}

	Serial.println("Beep!");
	for (int i=0; i < 100; i++) {
		digitalWrite(CLK_BEEP_PIN, HIGH);
		delay(1);
		digitalWrite(CLK_BEEP_PIN, LOW);
		delay(1);
	}
}

boolean PasswordInput::is_ready() {
	if (inputs_c >= 8) return true;
	return false;
}

void PasswordInput::reset() {
	inputs_c=0;
}

#endif
