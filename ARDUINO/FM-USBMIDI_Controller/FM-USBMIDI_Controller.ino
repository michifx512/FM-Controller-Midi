/*
   Project Name: Teensy USB-MIDI CONTROLLER
   Author: EFF Service - Francesco Michieletto
   Version: V0.9
*/

// Libraries
#include "FastLED.h"
#include "MIDIUSB.h"

// Headers
#include "Setup.h"

#include "General_Functions.h"

// ---------- SETUP and LOOP ----------
void setup() {
  pin_setup();
  FastLED_InitialSetup();
  struct_init();
}

uint8_t hue = 0;

void loop() {
  mode_button();

  //FastLED.clear();
  for (byte i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue - (i * 17) , 255, 255);
    /*
      if(i%2==0){
        leds[i]=CRGB(0,0,255);
      } else{
        leds[i]=CRGB(255,0,0);
      }
    delay(1);
    FastLED.show();*/
  }
  EVERY_N_MILLISECONDS(5) {
    hue++;
  }
  FastLED.show();
  readmatrix();
  readfaders();

  fader_out();
  button_out();
  MidiUSB.flush();
}
