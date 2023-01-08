int a = 0;
void setup() {
  pinMode(9, OUTPUT); //Hangi pinden verilecek onu anlatıyor 9.pin yidir
  // --Pins D9 and D10 - 15.63 kHz 10bit
  //TCCR1A = 0b00000011; //
  //TCCR1B = 0b00001001; // 

  // --Pins D9 and D10 - 7.82 kHz 10bit
  TCCR1A = 0b00000011; //
  TCCR1B = 0b00000001; // 

  // --Pins D9 and D10 - 1.93 kHz 10bit
  //TCCR1A = 0b00000011; //
  //TCCR1B = 0b00001010; //
}

void loop() {
    delay(1000);
    a = a + 5;
    a = constrain(a,0,610);
    analogWrite(9,a); // ilk sayı hangi pin olduğ, ikinci sayı 0 ile 1023 arasında Duty cycle veriyor linear ilişki 0 da %0 1023 te %100
  }