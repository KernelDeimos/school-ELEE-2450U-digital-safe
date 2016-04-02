#include "utils.h"

#ifndef DIAL_H
#define DIAL_H

class Dial {
	private:
		int analog_value;
		int digital_value;
		void _update_digital_value();
	public:
		boolean get_value_0();
		boolean get_value_1();
		int get_value_as_int();
		void update_value(int analog_input);
};

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

void Dial::_update_digital_value() {
	const int zer_interval = 250;
	const int one_interval = 500;
	const int two_interval = 750;
	const int thr_interval = 1000;
	if ( in_interval(
		0, analog_value,
		zer_interval
		) ) {
		digital_value = 0;
	}

	else
	if ( in_interval(
		zer_interval,
		analog_value,
		one_interval
		) ) {
		digital_value = 1;
	}

	else
	if ( in_interval(
		one_interval,
		analog_value,
		two_interval
		) ) {
		digital_value = 2;
	}

	else
	if ( in_interval(
		two_interval,
		analog_value,
		thr_interval
		) ) {
		digital_value = 3;
	}

	else {
		digital_value = 9;
	}
}

#endif

