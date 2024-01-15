// Viggo

//# INPUT #​
// ButtonStates: list, skrivas på formen ButtonStates = [boolean, boolean, ...]

bool ButtonStates[] = {true, false, false, false, true}; // testkod d.v.s station 1 och en fotgängare
//# OUTPUT #​
//Btn: int, in range 0-3
//Walk: boolean
int Btn;
boolean Walk;

void knappar() {
  int StatesLength = 5;
  Walk = ButtonStates[StatesLength - 1];
  for (int i = 0; i < StatesLength - 1; i++) {
    if (ButtonStates[i]) {
      Btn = i;
    }
  }
}
