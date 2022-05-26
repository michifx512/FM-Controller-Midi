/*
 * Setup & Settings Header File
 * Version: V0.1
 */

// ---------- CONSTANTS ----------
// DEFINES
#define NROWS 15
#define NCOLS 15
#define NFADERS 15

#define MODE_PIN 24 // SETUP/MODE PIN
#define FOOTSW_PINL 11
#define FOOTSW_PINR 12

#define AV_FACTOR 3 // how many values are taken to average the fader value

// FastLED DEFINES
#define NUM_LEDS 60
#define LEDS_DATA_PIN 26
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define INITIAL_BRIGHTNESS 255
#define VOLTS 5
CRGB leds[NUM_LEDS];

const byte FADERPINS[NFADERS] = {A13, A14, A15, A16, A17, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9};
// const byte FADERPINS[NFADERS] = {A13, A14, A15, A16, A17};
const byte ROWPINS[NROWS] = {5, 4, 3, 2};
const byte COLPINS[NCOLS] = {32, 31, 30, 29, 28, 33, 34, 35, 36, 37, 10, 9, 8, 7, 6};

// ---------- VARIABLES ----------

// SETUP VARIABLES

byte midi_channel = 0;
bool fader_output_note = false; // false-> CC VALUES, true->NOTE VALUES
byte note_preset_selector = 0;
bool led_feedback = true; // true-> feedback from pc, false->internal preset
byte led_preset_selector = 0;
byte led_brightness_selector = 4;
byte led_brightness = 255;

#define SETUPROWS 2
#define SETUPCOLS 15
bool setup_state[SETUPROWS][SETUPCOLS];
bool setup_state_pre[SETUPROWS][SETUPCOLS];

// ACTUAL READINGS VARIABLES
bool keystate[NROWS][NCOLS] = {0}; // matrix
bool keystate_pre[NROWS][NCOLS] = {0};
bool fl_state = 0; // Footswitch Left
bool fl_state_pre = 0;
bool fr_state = 0; // Footswitch Right
bool fr_state_pre = 0;
int faderval_10bit[NFADERS] = {0};
byte faderval_7bit[NFADERS] = {0};
byte faderval_7bit_pre[NFADERS] = {0};

// MIDI PRESETS
struct note_preset {
	byte note[NROWS][NCOLS];
	byte fl_note;
	byte fr_note;
};
note_preset preset_out[5];

void struct_init() {
	preset_out[0] = {
		{
			//"note" matrix
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},			  // 1st row
			{15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29}, // 2nd row
			{30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44}, // 3rd row
			{45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59}  // 4th row
		}																  // end "note" matrix
	};
	preset_out[0].fl_note = 126;
	preset_out[0].fr_note = 127;
}

// ---------- FUNCTIONS ----------
void pin_setup() {
	for (byte r = 0; r < NROWS; r++) { // matrix rows
		pinMode(ROWPINS[r], INPUT);
	}

	for (byte c = 0; c < NCOLS; c++) { // matrix columns
		pinMode(COLPINS[c], INPUT_PULLUP);
	}

	pinMode(MODE_PIN, INPUT_PULLUP);
	pinMode(FOOTSW_PINL, INPUT_PULLUP);
	pinMode(FOOTSW_PINR, INPUT_PULLUP);
}

void FastLED_InitialSetup() {
	FastLED.addLeds<CHIPSET, LEDS_DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	FastLED.setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(INITIAL_BRIGHTNESS);
	FastLED.clear();
	FastLED.show();
}
