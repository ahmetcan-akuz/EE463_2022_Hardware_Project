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
  pinMode(5, OUTPUT); //Hangi pinden verilecek onu anlatıyor 9.pin yidir
}

void loop() {
  if (a < 60) // Softstart 20 seconds
  {
    delay(1000);
    a = a + 3;
    a = constrain(a,0,61); //%25 duty max
    analogWrite(5,a); // ilk sayı hangi pin olduğ, ikinci sayı 0 ile 1023 arasında Duty cycle veriyor linear ilişki 0 da %0 1023 te %100
    curDuty = a;
  }
  else if (a >= 60) // ON off kontrol
  {
    PotValue = analogRead(A3);
    PotValue = map(PotValue,0,1023,0,3);
    SensorVout = analogRead(A0);
    AmpThrough = ((((SensorVout / 1023.0) * 5000) - 2500) / mVperAmp) + 0.09;
    if(PotValue == 0 && AmpThrough < 15 ) // 0.5 A
    {
      RefAmp = 2.5;
      if (AmpThrough > (RefAmp + 0.1))
      {
        b = curDuty;
        b = b-2;
        b = constrain(b,1,191);
        curDuty = b;
        analogWrite(5,b);
        delay(400);
      }
      else if (AmpThrough < (RefAmp - 0.1))
      {
        b = curDuty;
        b = b+2;
        b = constrain(b,1,191);
        curDuty = b;
        analogWrite(5,b);
        delay(400);
      }
    }
    else if(PotValue == 1 && AmpThrough < 15) // 1 A
    {
      RefAmp = 2.0;
      if (AmpThrough > (RefAmp + 0.07))
      {
        b = curDuty;
        b = b-2;
        b = constrain(b,1,191);
        curDuty = b;
        analogWrite(5,b);
        delay(300);
      }
      else if (AmpThrough < (RefAmp - 0.07) )
      {
        b = curDuty;
        b = b+2;
        b = constrain(b,1,191);
        curDuty = b;
        analogWrite(5,b);
        delay(300);
      }
    }
    else if (PotValue == 2 && AmpThrough < 15) //1.5 A
    {
      RefAmp = 1.5;
      if (AmpThrough >= (RefAmp + 0.05))
      {
        b = curDuty;
        b = b-2;
        b = constrain(b,1,191);
        curDuty = b;
        analogWrite(5,b);
        delay(200);
      }
      else if (AmpThrough < (RefAmp - 0.05))
      {
        b = curDuty;
        b = b+2;
        b = constrain(b,1,191);
        curDuty = b;
        analogWrite(5,b);
        delay(200);
      }
    }
    else if (AmpThrough > 15)
    {
    analogWrite(5,0); // akım 15i geçti duty 0 ver
    delay(10000); //10 saniye bekletiyor
    }
  }

  }