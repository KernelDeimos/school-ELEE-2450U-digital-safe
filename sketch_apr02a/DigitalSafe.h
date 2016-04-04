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
	state = SAFE_STATE_WAIT;

	dial = new Dial();
	pwinput = new PasswordInput(dial);
}

void DigitalSafe::loop() {

	switch (state) {
		case SAFE_STATE_WAIT:
			{
				int outside_button = digitalRead(OUTSIDE_BUTTON_PIN);
				if (outside_button == HIGH) {
					state = SAFE_STATE_INPUT;
					pwinput->reset();
				}
			}
			break;
		case SAFE_STATE_INPUT:
			{
				val = analogRead(POT_PIN);
				dial->update_value(val);
				pwinput->update_time(millis());

				if (pwinput->is_ready()) {
					state = SAFE_STATE_WAIT;

					// Play opening sound
					for (int i=0; i < 25; i++) {
						digitalWrite(CLK_BEEP_PIN, HIGH);
						delay(4);
						digitalWrite(CLK_BEEP_PIN, LOW);
						delay(4);
					}
					for (int i=0; i < 50; i++) {
						digitalWrite(CLK_BEEP_PIN, HIGH);
						delay(2);
						digitalWrite(CLK_BEEP_PIN, LOW);
						delay(2);
					}
					for (int i=0; i < 100; i++) {
						digitalWrite(CLK_BEEP_PIN, HIGH);
						delay(1);
						digitalWrite(CLK_BEEP_PIN, LOW);
						delay(1);
					}
				}
			}
			break;
	}
	
}
