void ReadAllSliders(){
  Sli1=analogRead(Sli1_pin);
  Sli2=analogRead(Sli2_pin);
  Sli3=analogRead(Sli3_pin);
  Sli4=analogRead(Sli4_pin);
  Sli5=analogRead(Sli5_pin);
  Sli6=analogRead(Sli6_pin);
  Sli7=analogRead(Sli7_pin);
  Sli8=analogRead(Sli8_pin);
  Sli9=analogRead(Sli9_pin);
  Sli10=analogRead(Sli10_pin);
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

void LedOnPression(byte index, bool value){
  value=!value;
  byte temp=0;
  switch(index){
    case 0:
      temp=Led1_pin;
      digitalWrite(temp, value);
      break;
    case 1:
      temp=Led2_pin;
      digitalWrite(temp, value);
      break;
    case 2:
      temp=Led3_pin;
      digitalWrite(temp, value);
      break;
    case 3:
      temp=Led4_pin;
      digitalWrite(temp, value);
      break;
    case 4:
      temp=Led5_pin;
      digitalWrite(temp, value);
      break;
    case 5:
      temp=Led6_pin;
      digitalWrite(temp, value);
      break;
    case 6:
      temp=Led12_pin;
      digitalWrite(temp, value);
      break;
    case 7:
      temp=Led11_pin;
      digitalWrite(temp, value);
      break;
    case 8:
      temp=Led10_pin;
      digitalWrite(temp, value);
      break;
    case 9:
      temp=Led9_pin;
      digitalWrite(temp, value);
      break;
    case 10:
      temp=Led8_pin;
      digitalWrite(temp, value);
      break;
    case 11:
      temp=Led7_pin;
      digitalWrite(temp, value);
      break;
    default:
      break;
  }
  if(index==12){
    digitalWrite(Led13_pin, value);
    digitalWrite(Led14_pin, !value);
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
