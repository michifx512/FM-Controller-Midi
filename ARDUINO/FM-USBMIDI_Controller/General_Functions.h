/*
   Functions Header File
   Version: V0.1
*/

// FUNCTION DECLARATIONS
void noteOn(byte channel, byte pitch, byte velocity);
void noteOff(byte channel, byte pitch, byte velocity);
void controlChange(byte channel, byte control, byte value);
void mode_button();
void setupchanged(byte r, byte c);
void led_setup_feedback_update();
void readmatrix();
void readfaders_w_averaging();
void fadervalue_correction();
void fader_10_to_7_bit();

// ---------- MIDIUSB UTILITY FUNCTIONS ----------
void noteOn(byte channel, byte pitch, byte velocity) {
	midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
	MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
	midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
	MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
	midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
	MidiUSB.sendMIDI(event);
}

// ---------- FastLED FUNCTIONS ----------
void led_setup_feedback_update() {
	for (byte i = 0; i < 5; i++) { // midi channel
		if (i != midi_channel)
			leds[i] = CRGB(30, 30, 30);
		else
			leds[i] = CRGB(0, 255, 255);
	}
	if (fader_output_note == 0) {
		leds[5] = CRGB(255, 127, 0);
		leds[6] = CRGB(30, 30, 30);
	} else {
		leds[5] = CRGB(30, 30, 30);
		leds[6] = CRGB(255, 127, 0);
	}
	for (byte i = 10; i < 15; i++) { // note preset
		if (i - 10 != note_preset_selector)
			leds[i] = CRGB(30, 30, 30);
		else
			leds[i] = CRGB(0, 255, 255);
	}
	if (led_feedback == 0) {
		leds[15] = CRGB(255, 127, 0);
		leds[16] = CRGB(30, 30, 30);
		for (byte i = 20; i < 25; i++) // note preset
			leds[i] = CRGB(0, 0, 0);
	} else {
		leds[15] = CRGB(30, 30, 30);
		leds[16] = CRGB(255, 127, 0);
		for (byte i = 20; i < 25; i++) { // note preset
			if (i - 20 != led_preset_selector)
				leds[i] = CRGB(30, 30, 30);
			else
				leds[i] = CRGB(0, 255, 255);
		}
	}
	for (byte i = 25; i < 30; i++) { // note preset
		if (i - 25 != led_brightness_selector)
			leds[i] = CRGB(30, 30, 30);
		else
			leds[i] = CRGB(0, 255, 255);
	}
}

// ---------- MODE BUTTON ----------
void mode_button() {
	while (!digitalRead(MODE_PIN)) {
		FastLED.clear();

		for (byte r = 0; r < SETUPROWS; r++) {
			pinMode(ROWPINS[r], OUTPUT);
			digitalWrite(ROWPINS[r], LOW);
			for (byte c = 0; c < SETUPCOLS; c++) {
				setup_state[r][c] = !digitalRead(COLPINS[c]);
				if (setup_state[r][c] != setup_state_pre[r][c]) {
					setup_state_pre[r][c] = setup_state[r][c];
					if (setup_state[r][c] == 1)
						setupchanged(r, c);
				}
			}
			pinMode(ROWPINS[r], INPUT); // Sets the row back to high impedance
			delayMicroseconds(125);
		}
		led_setup_feedback_update();
		FastLED.setBrightness(led_brightness);
		FastLED.show();
	}
}

void setupchanged(byte r, byte c) {
	if (r == 0) {
		if (c < 5) // midi channel has changed
			midi_channel = c;
		else if (c == 5 || c == 6) // CC/NOTE boolean has changed
			fader_output_note = c - 5;
		else if (c > 9) // note preset selector has changed
			note_preset_selector = c - 10;

	} else if (r == 1) {
		if (c < 2) { // led feedback boolean has changed
			led_feedback = c;
		} else if (c > 4 && c < 10) { // led preset selector has changed
			led_preset_selector = c - 5;
		} else if (c > 9) {
			led_brightness_selector = c - 10;
			led_brightness = led_brightness_selector * 63.75;
		}
	}
}

// ---------- MATRIX FUNCTIONS ----------
void readmatrix() {
	for (byte r = 0; r < NROWS; r++) {
		pinMode(ROWPINS[r], OUTPUT);
		digitalWrite(ROWPINS[r], LOW);
		for (byte c = 0; c < NCOLS; c++)
			keystate[r][c] = !digitalRead(COLPINS[c]);
		pinMode(ROWPINS[r], INPUT); // Sets the row back to high impedance
		delayMicroseconds(125);
	}
	fl_state = !digitalRead(FOOTSW_PINL);
	fr_state = !digitalRead(FOOTSW_PINR);
}

// ---------- FADER FUNCTIONS ----------
void readfaders() {
	for (byte i = 0; i < NFADERS; i++) {
		int averaging = 0;
		for (byte j = 0; j < AV_FACTOR; j++) {
			averaging += analogRead(FADERPINS[i]);

			delayMicroseconds(125);
		}
		faderval_10bit[i] = averaging / AV_FACTOR;

		if (faderval_10bit[i] < 56) {
			faderval_10bit[i] = map(faderval_10bit[i], 0, 55, 0, 190);
		} else if (faderval_10bit[i] >= 56 && faderval_10bit[i] <= 950) {
			faderval_10bit[i] = map(faderval_10bit[i], 56, 950, 191, 784);
		} else {
			faderval_10bit[i] = map(faderval_10bit[i], 951, 1023, 785, 1023);
		}

		faderval_7bit[i] = faderval_10bit[i] / 8;
	}
}

// ---------- MIDI OUT COMMANDS ----------
void fader_out() {
	for (byte i = 0; i < NFADERS; i++) {
		if (faderval_7bit[i] != faderval_7bit_pre[i]) { // send only if value changed
			faderval_7bit_pre[i] = faderval_7bit[i];
			if (fader_output_note == false) { // cc values need to be sent
				controlChange(midi_channel, i + 60, faderval_7bit[i]);
			} else {
				noteOn(midi_channel, i + 60, faderval_7bit[i]);
			}
		}
	}
}

void button_out() {
	for (byte r = 0; r < NROWS; r++) {
		for (byte c = 0; c < NCOLS; c++) {
			if (keystate[r][c] != keystate_pre[r][c]) { // send only if state changed
				keystate_pre[r][c] = keystate[r][c];
				if (keystate[r][c] == true)
					noteOn(midi_channel, preset_out[note_preset_selector].note[r][c], 127);
				else
					noteOff(midi_channel, preset_out[note_preset_selector].note[r][c], 0);
			}
		}
	}
	if (fl_state != fl_state_pre) {
		fl_state_pre = fl_state;
		if (fl_state == true)
			noteOn(midi_channel, preset_out[note_preset_selector].fl_note, 127);
		else
			noteOff(midi_channel, preset_out[note_preset_selector].fl_note, 0);
	}
	if (fr_state != fr_state_pre) {
		fr_state_pre = fr_state;
		if (fr_state == true)
			noteOn(midi_channel, preset_out[note_preset_selector].fr_note, 127);
		else
			noteOff(midi_channel, preset_out[note_preset_selector].fr_note, 0);
	}
}
