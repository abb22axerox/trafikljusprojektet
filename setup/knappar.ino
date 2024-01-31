#include "variables.h"
// Viggo

//# INPUT #​
// bool ButtonStates[] = {true, false, false, false, true}; // testkod d.v.s station 1 och en fotgängare
//# OUTPUT #​
//Btn: int, in range 0-3
//Walk: boolean

void knappar_loop() {
  int StatesLength = 5; // Längden av ButtonStates
  Walk = button_state_4; // Walk är längden-1 vilket ger det sista elementet alltså index 4
  if(button_state_0){
    Btn = 0;
  } else if(button_state_1){
    Btn = 1;
  } else if(button_state_2){
    Btn = 2;
  } else if(button_state_3){
    Btn = 3;
  }
}
