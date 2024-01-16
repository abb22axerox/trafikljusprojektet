#include "variables.h"
// Viggo

//# INPUT #​
// ButtonStates: list, skrivas på formen ButtonStates = [boolean, boolean, ...]

bool ButtonStates[] = {true, false, false, false, true}; // testkod d.v.s station 1 och en fotgängare
//# OUTPUT #​
//Btn: int, in range 0-3
//Walk: boolean

void knappar() {
  int StatesLength = 5; // Längden av ButtonStates
  Walk = ButtonStates[StatesLength - 1]; // Walk är längden-1 vilket ger det sista elementet alltså index 4
  for (int i = 0; i < StatesLength - 1; i++) {
    if (ButtonStates[i]) {
      Btn = i;
    }
  }
}
