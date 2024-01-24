//# INPUT #​
//Arduino pins och bytedata

//# OUTPUT #​
//Funktioner för att stänga av/på​
//Namn på knappar

#include "variables.h"

typedef enum LightStates {
  Red,
  RedYellow,
  Green,
  Yellow
};

LightStates LState;

//Trafficlights
byte red_led_1 = 22;
byte yellow_led_1 = 23;
byte green_led_1 = 24;

byte red_led_2 = 25;
byte yellow_led_2 = 26;
byte green_led_2 = 27;

byte red_led_3 = 28;
byte yellow_led_3 = 29;
byte green_led_3 = 30;

byte red_led_4 = 31;
byte yellow_led_4 = 32;
byte green_led_4 = 33;

byte red_led_5 = 34;
byte yellow_led_5 = 35;
byte green_led_5 = 36;

byte red_led_6 = 37;
byte yellow_led_6 = 38;
byte green_led_6 = 39;

byte red_led_7 = 40;
byte yellow_led_7 = 41;
byte green_led_7 = 42;

byte red_led_8 = 43;
byte yellow_led_8 = 44;
byte green_led_8 = 45;

#define button_pin_0 46
#define button_pin_1 47
#define button_pin_2 48
#define button_pin_3 49
#define button_pin_4 50



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

  display_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state_0 = digitalRead(button_pin_0);
  button_state_1 = digitalRead(button_pin_1);
  button_state_2 = digitalRead(button_pin_2);
  button_state_3 = digitalRead(button_pin_3);
  button_state_4 = digitalRead(button_pin_4);

  unsigned long currentMillis = millis();


  unsigned long millisDifference = currentMillis - previousMillis;

  if (0 < millisDifference && millisDifference < 1000) {
    LState = RedYellow;
  }
  else if (1000 < millisDifference && millisDifference < 6000) {
    LState = Green;
  }
  else if (6000 < millisDifference && millisDifference < 8000) {
    LState = Yellow;
  }
  else if (8000 < millisDifference && millisDifference < 10000) {
    LState = Red;
  }
  else if (10000 < millisDifference) {
    previousMillis = currentMillis;
  }

  knappar_loop();
  pot_loop();
  int first, second;
  Traffic_System(&first, &second);
  addToQue(first, second);
  display_loop();
  finalExecution_loop();
}

void LightState(int t_light) {

  switch (t_light) {
    case 0:
      updateState(red_led_1, yellow_led_1, green_led_1, previousMillis);
      break;
    case 1:
      updateState(red_led_2, yellow_led_2, green_led_2, previousMillis);
      break;
    case 2:
      updateState(red_led_3, yellow_led_3, green_led_3, previousMillis);
      break;
    case 3:
      updateState(red_led_4, yellow_led_4, green_led_4, previousMillis);
      break;
    case 4:
      updateState(red_led_5, yellow_led_5, green_led_5, previousMillis);
      break;
    case 5:
      updateState(red_led_6, yellow_led_6, green_led_6, previousMillis);
      break;
    case 6:
      updateState(red_led_7, yellow_led_7, green_led_7, previousMillis);
      break;
    case 7:
      updateState(red_led_8, yellow_led_8, green_led_8, previousMillis);
      break;
  }
}

void updateState(int red_pin, int yellow_pin, int green_pin, unsigned long &previousMillis) {
  
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
      // if (currentMillis - previousMillis >= 2000) {
      //   LState = Green;
      //   previousMillis = currentMillis;
      // }
      break;
    case Green:
      digitalWrite(red_pin, LOW);
      digitalWrite(yellow_pin, LOW);
      digitalWrite(green_pin, HIGH);
      // if (currentMillis - previousMillis >= 4000) {
      //   LState = Yellow;
      //   previousMillis = currentMillis;
      // }
      break;
    case Yellow:
      digitalWrite(red_pin, LOW);
      digitalWrite(yellow_pin, HIGH);
      digitalWrite(green_pin, LOW);
      // if (currentMillis - previousMillis >= 1000) {
      //   LState = Red;
      //   previousMillis = currentMillis;
      // }
      break;
  }
}
