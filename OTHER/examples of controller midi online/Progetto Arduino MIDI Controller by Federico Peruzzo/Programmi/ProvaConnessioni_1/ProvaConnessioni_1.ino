/*
 * Project Name: Arduino USB - MIDI Controller
 * Author: EFF Service - Federico Peruzzo
 * Version: a.1
 */

 //Libraries
 
 //Headers Files
#include "SetupsAndSettings.h"
#include "GeneralFunctions.h"


void setup() {
  InitialLEDSetup();
  InitialButtonSetup();
  PinSetup();

Serial.begin(115200);
Serial.println("Test Matrice");

  
}

void loop() {
  ReadAllSliders();
  ReadButtonMatrix();
  for(byte i=0; i<40; i++){
    if(Button[i]&&!Button_pre[i]){
      change[i]=!change[i];
      LedOnPression(i, change[i]);
      Serial.println("Bottone n."+String(i+1));
    }
    Button_pre[i]=Button[i];
  }
}
