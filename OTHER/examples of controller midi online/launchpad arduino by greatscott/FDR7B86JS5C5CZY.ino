#include <Keypad.h>
#include <FastLED.h>
#define NUM_LEDS 36
#define DATA_PIN 2
CRGB leds[NUM_LEDS];
int lighttime = 200;
const byte ROWS = 6;
const byte COLS = 6;
char hexaKeys[ROWS][COLS] = {
  {'0', '1', '2', '3', '4', '5'},
  {'6', '7', '8', '9', 'A', 'B'},
  {'C', 'D', 'E', 'F', 'G', 'H'},
  {'I', 'J', 'K', 'L', 'M', 'N'},
  {'O', 'P', 'Q', 'R', 'S', 'T'},
  {'U', 'V', 'W', 'X', 'Y', 'Z'},
};
byte colPins[COLS] = {9, 10, 11, 12, A0, A1};
byte rowPins[ROWS] = {3, 4, 5, 6, 7, 8};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    switch (customKey) {
      case '0':
        leds[0] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[0] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(1);
        Serial.write(100);
        break;
      case '1':
        leds[1] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[1] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(2);
        Serial.write(100);
        break;
      case '2':
        leds[2] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[2] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(3);
        Serial.write(100);
        break;
      case '3':
        leds[3] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[3] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(4);
        Serial.write(100);
        break;
      case '4':
        leds[4] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[4] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(5);
        Serial.write(100);
        break;
      case '5':
        leds[5] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[5] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(6);
        Serial.write(100);
        break;
      case '6':
        leds[11] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[11] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(7);
        Serial.write(100);
        break;
      case '7':
        leds[10] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[10] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(8);
        Serial.write(100);
        break;
      case '8':
        leds[9] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[9] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(9);
        Serial.write(100);
        break;
      case '9':
        leds[8] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[8] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(10);
        Serial.write(100);
        break;
      case 'A':
        leds[7] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[7] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(11);
        Serial.write(100);
        break;
      case 'B':
        leds[6] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[6] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(12);
        Serial.write(100);
        break;
      case 'C':
        leds[12] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[12] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(13);
        Serial.write(100);
        break;
      case 'D':
        leds[13] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[13] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(14);
        Serial.write(100);
        break;
      case 'E':
        leds[14] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[14] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(15);
        Serial.write(100);
        break;
      case 'F':
        leds[15] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[15] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(16);
        Serial.write(100);
        break;
      case 'G':
        leds[16] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[16] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(17);
        Serial.write(100);
        break;
      case 'H':
        leds[17] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[17] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(18);
        Serial.write(100);
        break;
      case 'I':
        leds[23] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[23] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(19);
        Serial.write(100);
        break;
      case 'J':
        leds[22] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[22] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(20);
        Serial.write(100);
        break;
      case 'K':
        leds[21] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[21] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(21);
        Serial.write(100);
        break;
      case 'L':
        leds[20] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[20] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(22);
        Serial.write(100);
        break;
      case 'M':
        leds[19] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[19] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(23);
        Serial.write(100);
        break;
      case 'N':
        leds[18] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[18] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(24);
        Serial.write(100);
        break;
      case 'O':
        leds[24] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[24] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(25);
        Serial.write(100);
        break;
      case 'P':
        leds[25] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[25] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(26);
        Serial.write(100);
        break;
      case 'Q':
        leds[26] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[26] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(27);
        Serial.write(100);
        break;
      case 'R':
        leds[27] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[27] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(28);
        Serial.write(100);
        break;
      case 'S':
        leds[28] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[28] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(29);
        Serial.write(100);
        break;
      case 'T':
        leds[29] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[29] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(30);
        Serial.write(100);
        break;
      case 'U':
        leds[35] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[35] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(31);
        Serial.write(100);
        break;
      case 'V':
        leds[34] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[34] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(32);
        Serial.write(100);
        break;
      case 'W':
        leds[33] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[33] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(33);
        Serial.write(100);
        break;
      case 'X':
        leds[32] = CRGB::Blue;
        FastLED.show();
        delay(lighttime);
        leds[32] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(34);
        Serial.write(100);
        break;
      case 'Y':
        leds[31] = CRGB::Red;
        FastLED.show();
        delay(lighttime);
        leds[31] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(35);
        Serial.write(100);
        break;
      case 'Z':
        leds[30] = CRGB::Green;
        FastLED.show();
        delay(lighttime);
        leds[30] = CRGB::Black;
        FastLED.show();
        Serial.write(B10010000);
        Serial.write(36);
        Serial.write(100);
        break;
    }
  }
}
