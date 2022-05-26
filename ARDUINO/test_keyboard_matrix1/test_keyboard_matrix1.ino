#include "Adafruit_NeoPixel.h"
//#include "test1.h"
#define ROWS 3
#define COLS 3
bool mat[ROWS][COLS] = {0};
const byte Rowpins[ROWS] = {13, 12, 11};
const byte Colpins[COLS] = {10, 9, 8};
int note[ROWS][COLS] = {{11, 12, 13}, {21, 22, 23}, {31, 32, 33}};
byte n = 0;
byte keystatTEST[ROWS * COLS];

// neopixel
#define NEOPIXEL_PIN 2
#define NUMPIXELS 9
#define DELAYVAL 500
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(9600);
  for (byte i = 0; i < ROWS; i++) {  // set the rows to OUTPUT and HIGH
    pinMode(Rowpins[i], OUTPUT);
    // pinMode(Rowpins[i], INPUT);
    // digitalWrite(Rowpins[i], HIGH);
  }
  for (byte i = 0; i < COLS; i++) {  // set the columns to INPUT PULLUP
    pinMode(Colpins[i], INPUT_PULLUP);
  }
}

void loop() {
  // pixels.clear();
  readkeys();
  serial_printmatrix();
  array_from_matrix();
  showpixel_keypressed();
  sendNOTE();
  delay(10);
}

void readkeys() {
  for (byte i = 0; i < ROWS; i++) {
    digitalWrite(Rowpins[i], LOW);

    //  check columns
    for (byte j = 0; j < COLS; j++) {
      if (digitalRead(Colpins[j]) == LOW) {
        mat[i][j] = 1;
      } else {
        mat[i][j] = 0;
      }
    }

    // pinMode(Rowpins[i], INPUT);  // sets to high impedance (disables the row)
    digitalWrite(Rowpins[i], HIGH);
  }
}

void array_from_matrix() {
  // copy the matrix into an array
  n = 0;
  for (byte i = 0; i < ROWS; i++) {
    for (byte j = 0; j < COLS; j++) {
      keystatTEST[n] = mat[i][j];
      n++;
    }
  }
}

void serial_printmatrix() {
  // serial matrix print
  Serial.println();
  for (byte i = 0; i < ROWS; i++) {
    Serial.println();
    for (byte j = 0; j < COLS; j++) {
      Serial.print(mat[i][j]);
      Serial.print(", ");
    }
  }
}

void showpixel_keypressed() {
  // turn on the led based on the button pressed
  for (int i = 0; i < (ROWS * COLS); i++) {
    if (keystatTEST[i] == 1) {
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    pixels.show();
  }
}

void sendNOTE() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (mat[i][j] == 1) {
        Serial.println("NOTE ON: ");
        Serial.print(note[i][j]);
      }
    }
  }
}