int a = 0;
void setup() {
  pinMode(5, OUTPUT); //Hangi pinden verilecek 5.pin 980 Hz
}

void loop() {
    delay(1000);
    a = a + 3;
    a = constrain(a,0,191);
    analogWrite(5,a); // ilk sayı hangi pin olduğ, ikinci sayı 0 ile 1023 arasında Duty cycle veriyor linear ilişki 0 da %0 1023 te %100
  }