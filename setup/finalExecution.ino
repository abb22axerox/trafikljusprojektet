// Viggo

#include "variables.h"

//# INPUT #​
// funktion LightState(index:int)
// index är mellan 0-7 vilket innebär att om index är över 3 så är det gångtrafikljus
// WaitingLights: listor med Light_instructions listor exempelvis WaitingLights = [[[2,4],[0]​],...]

//# OUTPUT #​
// ingen output, ändrar via parametrar i LightState()

// -Vid test, inkludera detta-
//--------------------------------
// void LightState(int index) {
//   Serial.print("Grönt vid:");
//   Serial.println(index);
// }
//--------------------------------
void finalExecution_loop() {
  delay(5000);
  int* LightsToActivate;
  
  LightsToActivate = getLongestWaiter();

  if (LightsToActivate != nullptr) {
    int length = 0;
    while (LightsToActivate[length] != -1) {
      length++;
    }

    for (int i = 0; i < length; i++) {
      LightState(LightsToActivate[i]);
    }
  }
}