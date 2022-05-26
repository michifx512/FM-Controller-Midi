void ReadAllSliders(){
  SliVal[0]=analogRead(Sli1_pin)/8;
  SliVal[1]=analogRead(Sli2_pin)/8;
  SliVal[2]=analogRead(Sli3_pin)/8;
  SliVal[3]=analogRead(Sli4_pin)/8;
  SliVal[4]=analogRead(Sli5_pin)/8;
  SliVal[5]=analogRead(Sli6_pin)/8;
  SliVal[6]=analogRead(Sli7_pin)/8;
  SliVal[7]=analogRead(Sli8_pin)/8;
  SliVal[8]=analogRead(Sli9_pin)/8;
  SliVal[9]=analogRead(Sli10_pin)/8;
}

void AreSlidersChanged(){
  for(byte i=0; i<10; i++){
    if(SliVal[i]!=SliVal_pre[i]){
      if(i<=7){
        switch(page){
          case PAGE1:
            MIDI.sendNoteOn(PAGE1_SliNotes[i], SliVal[i], CHANNEL);
            break;
          case PAGE2:
            MIDI.sendNoteOn(PAGE2_SliNotes[i], SliVal[i], CHANNEL);
            break;
        }
      }
      else{
        if(i==8)
          MIDI.sendNoteOn(17, SliVal[i], CHANNEL);
        else
          MIDI.sendNoteOn(18, SliVal[i], CHANNEL);
      }
      SliVal_pre[i]=SliVal[i];
    }
  }
}

void ResetSlidersHandler(){
  if(!Button[13])
    ResetSliders_EndTime=millis()+RESET_SLIDERS_TIME;
  if(millis()>=ResetSliders_EndTime)
    for(byte i=0; i<10; i++){
      if(i<=7){
        MIDI.sendNoteOn(PAGE1_SliNotes[i], NOTEMIN, CHANNEL);
        MIDI.sendNoteOn(PAGE2_SliNotes[i], NOTEMIN, CHANNEL);
      }
      else{
        if(i==8)
          MIDI.sendNoteOn(17, NOTEMIN, CHANNEL);
        else
          MIDI.sendNoteOn(18, NOTEMIN, CHANNEL);
      }
    }
}

void ReadAllRows(){
  ButtonRows[0]=digitalRead(Row1_pin);
  ButtonRows[1]=digitalRead(Row2_pin);
  ButtonRows[2]=digitalRead(Row3_pin);
  ButtonRows[3]=digitalRead(Row4_pin);
  ButtonRows[4]=digitalRead(Row5_pin);
  ButtonRows[5]=digitalRead(Row6_pin);
  ButtonRows[6]=digitalRead(Row7_pin);
  ButtonRows[7]=digitalRead(Row8_pin);
}

void ActionOnPression(byte index, bool value){
  byte temp=0;
  switch(index){
    case 0:
      temp=Led1_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(20, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(20, NOTEMIN, CHANNEL);
      break;
    case 1:
      temp=Led2_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(21, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(21, NOTEMIN, CHANNEL);
      break;
    case 2:
      temp=Led3_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(22, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(22, NOTEMIN, CHANNEL);
      break;
    case 3:
      temp=Led4_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(23, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(23, NOTEMIN, CHANNEL);
      break;
    case 4:
      temp=Led5_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(24, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(24, NOTEMIN, CHANNEL);
      break;
    case 5:
      temp=Led6_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(25, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(25, NOTEMIN, CHANNEL);
      break;
    case 6:
      temp=Led12_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(26, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(26, NOTEMIN, CHANNEL);
      break;
    case 7:
      temp=Led11_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(27, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(27, NOTEMIN, CHANNEL);
      break;
    case 8:
      temp=Led10_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(28, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(28, NOTEMIN, CHANNEL);
      break;
    case 9:
      temp=Led9_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(29, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(29, NOTEMIN, CHANNEL);
      break;
    case 10:
      temp=Led8_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(30, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(30, NOTEMIN, CHANNEL);
      break;
    case 11:
      temp=Led7_pin;
      digitalWrite(temp, !value);
      if(value)
        MIDI.sendNoteOn(31, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(31, NOTEMIN, CHANNEL);
      break;
    case 16:
      if(value)
        MIDI.sendNoteOn(33, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(33, NOTEMIN, CHANNEL);
      break;
    case 17:
      if(value)
        MIDI.sendNoteOn(34, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(34, NOTEMIN, CHANNEL);
      break;
    case 18:
      if(value)
        MIDI.sendNoteOn(35, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(35, NOTEMIN, CHANNEL);
      break;
    case 19:
      if(value)
        MIDI.sendNoteOn(36, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(36, NOTEMIN, CHANNEL);
      break;
    case 20:
      if(value)
        MIDI.sendNoteOn(37, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(37, NOTEMIN, CHANNEL);
      break;
    case 21:
      if(value)
        MIDI.sendNoteOn(38, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(38, NOTEMIN, CHANNEL);
      break;
    case 22:
      if(value)
        MIDI.sendNoteOn(39, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(39, NOTEMIN, CHANNEL);
      break;
    case 23:
      if(value)
        MIDI.sendNoteOn(40, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(40, NOTEMIN, CHANNEL);
      break;
    case 24:
      if(value)
        MIDI.sendNoteOn(42, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(42, NOTEMIN, CHANNEL);
      break;
    case 25:
      if(value)
        MIDI.sendNoteOn(43, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(43, NOTEMIN, CHANNEL);
      break;
    case 26:
      if(value)
        MIDI.sendNoteOn(44, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(44, NOTEMIN, CHANNEL);
      break;
    case 27:
      if(value)
        MIDI.sendNoteOn(45, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(45, NOTEMIN, CHANNEL);
      break;
    case 28:
      if(value)
        MIDI.sendNoteOn(46, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(46, NOTEMIN, CHANNEL);
      break;
    case 29:
      if(value)
        MIDI.sendNoteOn(47, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(47, NOTEMIN, CHANNEL);
      break;
    case 30:
      if(value)
        MIDI.sendNoteOn(48, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(48, NOTEMIN, CHANNEL);
      break;
    case 31:
      if(value)
        MIDI.sendNoteOn(57, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(57, NOTEMIN, CHANNEL);
      break;
    case 32:
      if(value)
        MIDI.sendNoteOn(50, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(50, NOTEMIN, CHANNEL);
      break;
    case 33:
      if(value)
        MIDI.sendNoteOn(51, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(51, NOTEMIN, CHANNEL);
      break;
    case 34:
      if(value)
        MIDI.sendNoteOn(52, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(52, NOTEMIN, CHANNEL);
      break;
    case 35:
      if(value)
        MIDI.sendNoteOn(53, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(53, NOTEMIN, CHANNEL);
      break;
    case 36:
      if(value)
        MIDI.sendNoteOn(54, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(54, NOTEMIN, CHANNEL);
      break;
    case 37:
      if(value)
        MIDI.sendNoteOn(55, NOTEMAX, CHANNEL);
      else
        MIDI.sendNoteOff(55, NOTEMIN, CHANNEL);
      break;
    default:
      break;
  }
  if(index==12){
    digitalWrite(Led13_pin, !value);
    digitalWrite(Led14_pin, value);
    page=value?PAGE2:PAGE1;
  }
}

void ReadButtonMatrix(){
  for(byte c=0; c<5; c++){
    switch(c){
      case 0:
        digitalWrite(Col1_pin, LOW);
        digitalWrite(Col2_pin, HIGH);
        digitalWrite(Col3_pin, HIGH);
        digitalWrite(Col4_pin, HIGH);
        digitalWrite(Col5_pin, HIGH);
        ReadAllRows();
        for(byte i=0; i<8; i++){
          if(ButtonRows[i]==false)
            Button[i]=true;
          else
            Button[i]=false;
        }
        break;
      case 1:
        digitalWrite(Col1_pin, HIGH);
        digitalWrite(Col2_pin, LOW);
        digitalWrite(Col3_pin, HIGH);
        digitalWrite(Col4_pin, HIGH);
        digitalWrite(Col5_pin, HIGH);
        ReadAllRows();
        for(byte i=0; i<8; i++){
          if(ButtonRows[i]==false)
            Button[i+8]=true;
          else
            Button[i+8]=false;
        }
        break;
      case 2:
        digitalWrite(Col1_pin, HIGH);
        digitalWrite(Col2_pin, HIGH);
        digitalWrite(Col3_pin, LOW);
        digitalWrite(Col4_pin, HIGH);
        digitalWrite(Col5_pin, HIGH);
        ReadAllRows();
        for(byte i=0; i<8; i++){
          if(ButtonRows[i]==false)
            Button[i+16]=true;
          else
            Button[i+16]=false;
        }
        break;
      case 3:
        digitalWrite(Col1_pin, HIGH);
        digitalWrite(Col2_pin, HIGH);
        digitalWrite(Col3_pin, HIGH);
        digitalWrite(Col4_pin, LOW);
        digitalWrite(Col5_pin, HIGH);
        ReadAllRows();
        for(byte i=0; i<8; i++){
          if(ButtonRows[i]==false)
            Button[i+24]=true;
          else
            Button[i+24]=false;
        }
        break;
      case 4:
        digitalWrite(Col1_pin, HIGH);
        digitalWrite(Col2_pin, HIGH);
        digitalWrite(Col3_pin, HIGH);
        digitalWrite(Col4_pin, HIGH);
        digitalWrite(Col5_pin, LOW);
        ReadAllRows();
        for(byte i=0; i<8; i++){
          if(ButtonRows[i]==false)
            Button[i+32]=true;
          else
            Button[i+32]=false;
        }
        break;
    }
  }
}
