// Viggo

//# INPUT #​
// ButtonStates: list, skrivas på formen ButtonStates = [boolean, boolean, ...]

bool ButtonStates[] = {true, false, false, false, true}; // testkod d.v.s station 1 och en fotgängare
//# OUTPUT #​
//Btn: int, in range 1-4
//Walk: boolean
int StatesLength = 5;
int Btn;
boolean Walk = ButtonStates[StatesLength - 1];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < StatesLength - 1; i++) {
    if (ButtonStates[i]) {
      Btn = i;
      Btn= Btn+1;
    }
  }
  Serial.begin(9600);
  Serial.println(Btn);
  Serial.println(Walk);
}

void loop() {
  // put your main code here, to run repeatedly:
}
