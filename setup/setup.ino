//# INPUT #​
//Arduino pins och bytedata

//# OUTPUT #​
//Funktioner för att stänga av/på​
//Namn på knappar

typedef enum LightStates {
  Red,
  RedYellow,
  Green,
  Yellow
};

LightStates LState;

//Trafficlights
byte red_led_1 = D1;
byte yellow_led_1 = D2;
byte green_led_1 = D3;

byte red_led_2 = D4;
byte yellow_led_2 = D5;
byte green_led_2 = D6;

byte red_led_3 = D7;
byte yellow_led_3 = D7;
byte green_led_3 = D9;

byte red_led_4 = D10;
byte yellow_led_4 = 11;
byte green_led_4 = 12;

byte red_led_5 = 13;
byte yellow_led_5 = 14;
byte green_led_5 = 15;

byte red_led_6 = 16;
byte yellow_led_6 = 17;
byte green_led_6 = 18;

byte red_led_7 = 19;
byte yellow_led_7 = 20;
byte green_led_7 = 21;

byte red_led_8 = 22;
byte yellow_led_8 = 23;
byte green_led_8 = 24;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_led_1, OUTPUT);
  pinMode(yellow_led_1, OUTPUT);
  pinMode(green_led_1, OUTPUT);
  pinMode(red_led_2, OUTPUT);
  pinMode(yellow_led_2, OUTPUT);
  pinMode(green_led_2, OUTPUT);
  pinMode(red_led_3, OUTPUT);
  pinMode(yellow_led_3, OUTPUT);
  pinMode(green_led_3, OUTPUT);
  pinMode(red_led_4, OUTPUT);
  pinMode(yellow_led_4, OUTPUT);
  pinMode(green_led_4, OUTPUT);
  pinMode(red_led_5, OUTPUT);
  pinMode(yellow_led_5, OUTPUT);
  pinMode(green_led_5, OUTPUT);
  pinMode(red_led_6, OUTPUT);
  pinMode(yellow_led_6, OUTPUT);
  pinMode(green_led_6, OUTPUT);
  pinMode(red_led_7, OUTPUT);
  pinMode(yellow_led_7, OUTPUT);
  pinMode(green_led_7, OUTPUT);
  pinMode(red_led_8, OUTPUT);
  pinMode(yellow_led_8, OUTPUT);
  pinMode(green_led_8, OUTPUT);

  LState = Red;
}

void loop() {
  // put your main code here, to run repeatedly:

}

void light_state(bool state, int t_light) {
  if (state) {
    switch (t_light) {
      case 1:
        updateState(RedYellow, red_led_1, yellow_led_1, green_led_1);
        break;
      case 2:
        updateState(RedYellow, red_led_2, yellow_led_2, green_led_2);
        break;
      case 3:
        updateState(RedYellow, red_led_3, yellow_led_3, green_led_3);
        break;
      case 4:
        updateState(RedYellow, red_led_4, yellow_led_4, green_led_4);
        break;
      case 5:
        updateState(RedYellow, red_led_5, yellow_led_5, green_led_5);
        break;
      case 6:
        updateState(RedYellow, red_led_6, yellow_led_6, green_led_6);
        break;
      case 7:
        updateState(RedYellow, red_led_7, yellow_led_7, green_led_7);
        break;
      case 8:
        updateState(RedYellow, red_led_8, yellow_led_8, green_led_8);
        break;
    }
  }
}

void updateState(LightStates LState, int red_pin, int yellow_pin, int green_pin) {
  switch (LState) {
    case Red:
      digitalWrite(red_pin, HIGH);
      digitalWrite(yellow_pin, LOW);
      digitalWrite(green_pin, LOW);
      break;
    case RedYellow:
      digitalWrite(red_pin, HIGH);
      digitalWrite(yellow_pin, HIGH);
      digitalWrite(green_pin, LOW);
      delay(2000);
      LState = Green;
      break;
    case Green:
      digitalWrite(red_pin, LOW);
      digitalWrite(yellow_pin, LOW);
      digitalWrite(green_pin, HIGH);
      delay(4000);
      LState = Yellow;
      break;
    case Yellow:
      digitalWrite(red_pin, LOW);
      digitalWrite(yellow_pin, HIGH);
      digitalWrite(green_pin, LOW);
      delay(1000);
      LState = Red;
      break;
  }
}
