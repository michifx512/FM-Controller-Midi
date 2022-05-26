/*void readkeys() {
  for (byte i = 0; i < ROWS; i++) {
    digitalWrite(Rowpins[i], LOW);
    // pinMode(Rowpins[i], OUTPUT); //test?

    //  check columns
    for (byte j = 0; j < COLS; j++) {
      if (digitalRead(Colpins[j]) == LOW) {
        mat[i][j] = 1;
      } else {
        mat[i][j] = 0;
      }
    }

    digitalWrite(Rowpins[i], HIGH);
    // pinMode(Rowpins[i], INPUT); //test?
  }
}*/