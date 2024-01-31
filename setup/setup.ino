//# INPUT #​
//Arduino pins och bytedata

//# OUTPUT #​
//Funktioner för att stänga av/på​
//Namn på knappar

#include "variables.h"

#define button_pin_0 46
#define button_pin_1 47
#define button_pin_2 48
#define button_pin_3 49
#define button_pin_4 50

struct light_data_struct {
  byte red_pin;
  byte yellow_pin;
  byte green_pin;

  unsigned long start_millis;
  // int index_key;
};

light_data_struct light_data[8];
int light_data_length = 8;

//                                     r     ry    g     y
unsigned long light_cycle_timings[] = {1000, 2000, 4000, 2000};
int light_cycles_length = 4;

void setup() {

  // Set light_data pins
  //              r   y   g
  light_data[0] = {22, 23, 24};
  light_data[1] = {25, 26, 27};
  light_data[2] = {28, 29, 30};
  light_data[3] = {31, 32, 33};
  light_data[4] = {34, 35, 36};
  light_data[5] = {37, 38, 39};
  light_data[6] = {40, 41, 42};
  light_data[7] = {43, 44, 45};

  for (int i = 0; i < light_data_length; i++) {
    pinMode(light_data[i].red_pin, OUTPUT);
    pinMode(light_data[i].yellow_pin, OUTPUT);
    pinMode(light_data[i].green_pin, OUTPUT);
  }

  //Knapparnas pinModes
  pinMode(button_pin_0, INPUT);
  pinMode(button_pin_1, INPUT);
  pinMode(button_pin_2, INPUT);
  pinMode(button_pin_3, INPUT);
  pinMode(button_pin_4, INPUT);

  Serial.begin(9600);

  display_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state_0 = digitalRead(button_pin_0);
  button_state_1 = digitalRead(button_pin_1);
  button_state_2 = digitalRead(button_pin_2);
  button_state_3 = digitalRead(button_pin_3);
  button_state_4 = digitalRead(button_pin_4);

  unsigned long current_millis = millis();
  UpdateLightStates(current_millis);

  knappar_loop();
  pot_loop();
  int first, second;
  Traffic_System(&first, &second);
  addToQue(first, second);
  display_loop();
  // finalExecution_loop();
}

int GetLightStateKey(unsigned long start_millis, unsigned long current_millis)
{
  unsigned long tot_millis = start_millis;
  for (int i = 0; i < light_cycles_length; i++)
  {
    tot_millis += light_cycle_timings[i];

    if (current_millis < tot_millis)
    {
      return i;
    }
  }
  // Default light state: RED (0)
  return 0;
}

void SetLightState(int light_state_key, int light_index)
{
  light_data_struct ld = light_data[light_index];
  byte red_pin = ld.red_pin, yellow_pin = ld.yellow_pin, green_pin = ld.green_pin;

  switch (light_state_key) {
    case 0: // Red
      digitalWrite(red_pin, HIGH);
      digitalWrite(yellow_pin, LOW);
      digitalWrite(green_pin, LOW);
      break;
    case 1: // RedYellow
      digitalWrite(red_pin, HIGH);
      digitalWrite(yellow_pin, HIGH);
      digitalWrite(green_pin, LOW);
      break;
    case 2: // Green
      digitalWrite(red_pin, LOW);
      digitalWrite(yellow_pin, LOW);
      digitalWrite(green_pin, HIGH);
      break;
    case 3: // Yellow
      digitalWrite(red_pin, LOW);
      digitalWrite(yellow_pin, HIGH);
      digitalWrite(green_pin, LOW);
      break;
    default:
      Serial.println("ERR - light_state_key invalid");
  }
}

void UpdateLightStates(unsigned long current_millis)
{
  for (int light_index = 0; light_index < light_data_length; light_index++)
  {
    unsigned long start_millis = light_data[light_index].start_millis;
    int light_state_key = GetLightStateKey(start_millis, current_millis);

    SetLightState(light_state_key, light_index);
  }
}

void StartLightCycle(int lightIndex, unsigned long new_start_millis)
{
  light_data[lightIndex].start_millis = new_start_millis;
}