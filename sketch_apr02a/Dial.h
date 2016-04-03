#include "utils.h"
#include "Arduino.h";

#ifndef DIAL_H
#define DIAL_H

class Dial {
	private:
		// Stored Values
		int analog_value;
		int digital_value;
		// Calibrated Values
		int max_value = 0;
		// Pre-computer values
		int intervals[9];
		void _update_digital_value();
		void _update_interval_ranges();
	public:
		const int AMOUNT_INTERVALS = 8;
		Dial();
		boolean get_value_0();
		boolean get_value_1();
		int get_value_as_int();
		void update_value(int analog_input);
};

Dial::Dial() {
	for (int i=0; i < AMOUNT_INTERVALS; i++) {
		intervals[i] = 0;
	}
	max_value = 1024;
	_update_interval_ranges();
}

boolean Dial::get_value_0() {
	return 0;
}

boolean Dial::get_value_1() {
	return 0;
}

int Dial::get_value_as_int() {
	return digital_value;
}

void Dial::update_value(int analog_input) {
	analog_value = analog_input;
	_update_digital_value();

}

void Dial::_update_interval_ranges() {
	int inc = max_value / 8;
	for (int i=1; i <= AMOUNT_INTERVALS; i++) {
		intervals[i] = i*inc;
	}
}

void Dial::_update_digital_value() {
	for (int i=0; i < AMOUNT_INTERVALS; i++) {
		int lb = intervals[i];
		int ub = intervals[i+1];
		if ( in_interval(lb, analog_value, ub) ) {
			// Serial.println(i);
			digital_value = i;
			return;
		}
	}

	// If it wasn't in range, update the range!
	/*
	max_value = analog_value;
	_update_interval_ranges();
	*/

	// Also, return a lame error value
	digital_value = 0;
	return;

}

#endif

