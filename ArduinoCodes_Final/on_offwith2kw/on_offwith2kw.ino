int a = 0;
int b;
int curDuty;
int mVperAmp = 66; //30A Modül Settings
int SensorVout ;
int PotPin;
int PotValue;
double AmpThrough;
double RefAmp;
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
  if (a < 100) // Softstart 20 seconds
  {
    delay(1000);
    a = a + 5;
    a = constrain(a,0,101); //%10 duty max
    analogWrite(9,a); // ilk sayı hangi pin olduğ, ikinci sayı 0 ile 1023 arasında Duty cycle veriyor linear ilişki 0 da %0 1023 te %100
    curDuty = a;
  }
  else if (a >= 100) // ON off kontrol
  {
    PotValue = analogRead(A3);
    PotValue = map(PotValue,0,1023,0,4);
    SensorVout = analogRead(A0);
    AmpThrough = ((((SensorVout / 1023.0) * 5000) - 2500) / mVperAmp) + 0.09;
    if(PotValue == 0 && AmpThrough < 15 ) // 0.5 A
    {
      RefAmp = 0.5;
      if (AmpThrough > (RefAmp + 0.05))
      {
        b = curDuty;
        b = b-5;
        b = constrain(b,1,1022);
        curDuty = b;
        analogWrite(9,b);
        delay(100);
      }
      else if (AmpThrough < (RefAmp - 0.05))
      {
        b = curDuty;
        b = b+5;
        b = constrain(b,1,1022);
        curDuty = b;
        analogWrite(9,b);
        delay(100);
      }
    }
    else if(PotValue == 1 && AmpThrough < 15) // 1 A
    {
      RefAmp = 1.0;
      if (AmpThrough > (RefAmp + 0.07))
      {
        b = curDuty;
        b = b-5;
        b = constrain(b,1,1022);
        curDuty = b;
        analogWrite(9,b);
        delay(100);
      }
      else if (AmpThrough < (RefAmp - 0.07) )
      {
        b = curDuty;
        b = b+5;
        b = constrain(b,1,1022);
        curDuty = b;
        analogWrite(9,b);
        delay(100);
      }
    }
    else if (PotValue == 2 && AmpThrough < 15) //1.5 A
    {
      RefAmp = 1.5;
      if (AmpThrough >= (RefAmp + 0.1))
      {
        b = curDuty;
        b = b-5;
        b = constrain(b,1,1022);
        curDuty = b;
        analogWrite(9,b);
        delay(100);
      }
      else if (AmpThrough < (RefAmp - 0.1))
      {
        b = curDuty;
        b = b+5;
        b = constrain(b,1,1022);
        curDuty = b;
        analogWrite(9,b);
        delay(100);
      }
    }
    else if (PotValue == 3 && AmpThrough < 15) // SALDIR REİS 2KW
    {
      b = curDuty;
      b = b+5;
      b = constrain(b,1,610);
      curDuty = b;
      analogWrite(9,b);
      delay(500);
    }
    else if (AmpThrough > 15)
    {
    analogWrite(9,0); // akım 15i geçti duty 0 ver
    delay(10000); //10 saniye bekletiyor
    }
  }

  }