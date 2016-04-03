#include "pins.h"

#include "Dial.h"
#include "PasswordInput.h"

const int SAFE_STATE_WAIT = 0;
const int SAFE_STATE_INPUT = 1;

class DigitalSafe {
private:
	int val;
	int state;

	Dial *dial;
	PasswordInput *pwinput;

public:
	DigitalSafe();
	void loop();
};

DigitalSafe::DigitalSafe() {
	val = 0;
	state = 0;

	dial = new Dial();
	pwinput = new PasswordInput(dial);
}

void DigitalSafe::loop() {
	val = analogRead(POT_PIN);
	dial->update_value(val);
	pwinput->update_time(millis());
}
