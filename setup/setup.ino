//# INPUT #​
//Arduino pins och bytedata

//# OUTPUT #​
//Funktioner för att stänga av/på​
//Namn på knappar

#include "variables.h"

typedef enum {
  Red,
  RedYellow,
  Green,
  Yellow
} LightStates;

LightStates LState;

//Trafficlights
byte red_led_1 = 1;
byte yellow_led_1 = 2;
byte green_led_1 = 3;

byte red_led_2 = 4;
byte yellow_led_2 = 5;
byte green_led_2 = 6;

byte red_led_3 = 7;
byte yellow_led_3 = 7;
byte green_led_3 = 9;

byte red_led_4 = 10;
byte yellow_led_4 = 11;
byte green_led_4 = 38; //fixa detta till 14

byte red_led_5 = 13;
byte yellow_led_5 = 39; //fixa detta till 14
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

#define button_pin_0 25
#define button_pin_1 26
#define button_pin_2 27
#define button_pin_3 28
#define button_pin_4 29

bool button_state_0;
bool button_state_1;
bool button_state_2;
bool button_state_3;
bool button_state_4;

unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  //Trafikljus pinModes
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

  Serial.begin(9600);

  //Knapparnas pinModes
  pinMode(button_pin_0, INPUT);
  pinMode(button_pin_1, INPUT);
  pinMode(button_pin_2, INPUT);
  pinMode(button_pin_3, INPUT);
  pinMode(button_pin_4, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state_0 = digitalRead(button_pin_0);
  button_state_1 = digitalRead(button_pin_1);
  button_state_2 = digitalRead(button_pin_2);
  button_state_3 = digitalRead(button_pin_3);
  button_state_4 = digitalRead(button_pin_4);

  ButtonStates[0] = button_state_0;
  ButtonStates[1] = button_state_1;
  ButtonStates[2] = button_state_2;
  ButtonStates[3] = button_state_3;
  ButtonStates[4] = button_state_4;

  if (button_state_0 || button_state_1 || button_state_2 || button_state_3 || button_state_4) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void LightState(int t_light) {
  switch (t_light) {
    case 0:
      updateState(LState, red_led_1, yellow_led_1, green_led_1, previousMillis);
      break;
    case 1:
      updateState(LState, red_led_2, yellow_led_2, green_led_2, previousMillis);
      break;
    case 2:
      updateState(LState, red_led_3, yellow_led_3, green_led_3, previousMillis);
      break;
    case 3:
      updateState(LState, red_led_4, yellow_led_4, green_led_4, previousMillis);
      break;
    case 4:
      updateState(LState, red_led_5, yellow_led_5, green_led_5, previousMillis);
      break;
    case 5:
      updateState(LState, red_led_6, yellow_led_6, green_led_6, previousMillis);
      break;
    case 6:
      updateState(LState, red_led_7, yellow_led_7, green_led_7, previousMillis);
      break;
    case 7:
      updateState(LState, red_led_8, yellow_led_8, green_led_8, previousMillis);
      break;
  }
}

void updateState(LightStates &LState, int red_pin, int yellow_pin, int green_pin, unsigned long &previousMillis) {
  unsigned long currentMillis = millis();

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
      if (currentMillis - previousMillis >= 2000) {
        LState = Green;
        previousMillis = currentMillis;
      }
      break;
    case Green:
      digitalWrite(red_pin, LOW);
      digitalWrite(yellow_pin, LOW);
      digitalWrite(green_pin, HIGH);
      if (currentMillis - previousMillis >= 4000) {
        LState = Yellow;
        previousMillis = currentMillis;
      }
      break;
    case Yellow:
      digitalWrite(red_pin, LOW);
      digitalWrite(yellow_pin, HIGH);
      digitalWrite(green_pin, LOW);
      if (currentMillis - previousMillis >= 1000) {
        LState = Red;
        previousMillis = currentMillis;
      }
      break;
  }
}
