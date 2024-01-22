// Andreas
#include "variables.h"
//# INPUT #​
// TurnValue: int , i intervallet 0-1023

// villkor: om under 350 är det en 0, om 350 > x < 650 är det en 1, och om det är x >= 650 är det en 2

//# OUTPUT #​
// Turn: int, i intervallet 0-2
int TurnValue;

void pot_loop() {
  // huvudkod som körs upprepade gånger:
  TurnValue = analogRead(A0); // Läs in värdet från den analoga pin A0
  
  // Logik för att kartlägga värdena
  if (TurnValue < 350) {
    Turn = 0;
  } 
  else if (TurnValue > 350 && TurnValue < 650) {
    Turn = 1;
  } 
  else {
    Turn = 2;
  }
  // // Skriv ut resultatet till den seriella monitorn
  // Serial.print("TurnValue: ");
  // Serial.print(TurnValue);
  // Serial.print(" - Turn: ");
  // Serial.println(Turn);

  // delay(1000); // Valfri fördröjning för att sänka frekvensen av utskrifterna, justera vid behov
}
