typedef enum LightStates {
  Red,
  RedYellow,
  Green,
  Yellow
};
 
LightStates LState;
 
byte CarInput = D2;
 
boolean CarSense;
 
byte RedLed = D5;
byte YellowLed = D4;
byte GreenLed = D3;
 
int PotValue = 0;
 
void setup() {
  LState = Red;
  pinMode(CarInput, INPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(YellowLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
}
 
void loop() {
  CarSense = digitalRead(CarInput);
  if (CarSense == true) {
    LState = RedYellow;
  }
  switch (LState) {
    case Red:
      digitalWrite(RedLed, HIGH);
      digitalWrite(YellowLed, LOW);
      digitalWrite(GreenLed, LOW);
      break;
    case RedYellow:
      digitalWrite(RedLed, HIGH);
      digitalWrite(YellowLed, HIGH);
      digitalWrite(GreenLed, LOW);
      delay(2000);
      LState = Green;
      break;
    case Green:
      digitalWrite(YellowLed, LOW);
      digitalWrite(RedLed, LOW);
      digitalWrite(GreenLed, HIGH);
      delay(4000);
      LState = Yellow;
      break;
    case Yellow:
      digitalWrite(RedLed, LOW);
      digitalWrite(GreenLed, LOW);
      digitalWrite(YellowLed, HIGH);
      delay(1000);
      LState = Red;
      break;
  }
  delay(100);
}
