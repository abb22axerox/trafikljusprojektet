//# INPUT #​
//Arduino pins och bytedata

//# OUTPUT #​
//[]
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
byte yellow_led_4 = D11;
byte green_led_4 = D12;

byte red_led_5 = D13;
byte yellow_led_5 = D14;
byte green_led_5 = D15;

byte red_led_6 = D16;
byte yellow_led_6 = D17;
byte green_led_6 = D18;

byte red_led_7 = D19;
byte yellow_led_7 = D20;
byte green_led_7 = D21;

byte red_led_8 = D22;
byte yellow_led_8 = D23;
byte green_led_8 = D24;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_led_1, OUTPUT);
  pinMode(yellow_led_1, OUTPUT);
  pinMode(green_led_1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
