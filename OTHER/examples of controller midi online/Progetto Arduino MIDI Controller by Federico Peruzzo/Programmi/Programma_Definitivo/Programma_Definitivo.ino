/*
 * Project Name: Arduino USB - MIDI Controller
 * Author: EFF Service - Federico Peruzzo
 * Version: a.1
 */

 //Libraries
#include <MIDI.h>

struct MySettings : public midi::DefaultSettings
{
    static const long BaudRate = 115200;
};

// Create a 'MIDI' object using MySettings bound to Serial2.
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);


 //Headers Files
#include "SetupsAndSettings.h"
#include "GeneralFunctions.h"


void setup() {
  MIDI.begin();
  InitialLEDSetup();
  InitialButtonSetup();
  PinSetup();
  ReadAllSliders();
  for(byte set=0; set<10; set++){
    SliVal_pre[set]=SliVal[set];
  }
  page=PAGE1;
}

void loop() {
  MIDI.read();
  ReadAllSliders();
  AreSlidersChanged();
  ReadButtonMatrix();
  for(byte i=0; i<40; i++){
    if(Button[i]&&!Button_pre[i]){
      change[i]=!change[i];
      ActionOnPression(i, change[i]);
    }
    Button_pre[i]=Button[i];
  }
  ResetSlidersHandler();
}
