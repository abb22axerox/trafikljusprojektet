// Viggo
//# INPUT #​
// Light_instructions: [2,4] de som ska bli gröna
#include "variables.h"

unsigned long lastActivationMillis;
unsigned long difference_in_millis = 0;

void addToQue(int firstLight, int secondLight) {
  if (prevBtn != Btn) {
    lastActivationMillis = millis();
    Serial.print("firstLight:");
    Serial.println(firstLight);
    StartLightCycle(firstLight, lastActivationMillis);
    if (secondLight >= 0 && secondLight < 8) {
      StartLightCycle(secondLight, lastActivationMillis);
      Serial.print("secondLight:");
      Serial.println(secondLight);
    }
    prevBtn = Btn;
  } else if (difference_in_millis > 8000){
    prevBtn = -1;
    Btn = -1; // då stämmer likheten än vilket leder till att om Btn ändrar värde nu så körs en ny cycle och om igen
  }
  difference_in_millis = millis() - lastActivationMillis; // kör om cycle direkt efter hitta ett sätt att identifiera om knappen redan körde nyss, problem nu station 2 återupprepas
  // int* newInstructions; // definiera de nya instruktionerna
  // int** newArray = new int*[waitingLightsLength + 1];

  // for (int i = 0; i < waitingLightsLength; i++) {
  //   newArray[i] = WaitingLights[i]; // lägg till alla element från WaitingLights till newArray
  // }
  // newInstructions = new int[2];
  // newInstructions[1] = secondLight;
  // newInstructions[0] = firstLight;

  // newArray[waitingLightsLength] = newInstructions; // lägg till det nya elementet

  // delete[] WaitingLights; // rensa minnet
  // WaitingLights = newArray; // uppdatera minnespekaren till att visa till newArray

  // waitingLightsLength++; // öka WaitingLights storlek
}

// int* getLongestWaiter() {
//   if (waitingLightsLength == 0) {
//     return nullptr; // om det inte finns någon som väntar
//   }

//   int* longestWaiter = WaitingLights[0]; // sätt longestWaiter till första elementet

//   int** newArray = new int*[waitingLightsLength - 1]; // uppdatera minnet så att den inte får memory leaks

//   for (int i = 1; i < waitingLightsLength; ++i) {
//     newArray[i - 1] = WaitingLights[i]; // lägg tillbaka elementen
//   }

//   delete[] WaitingLights; // Ta bort den tidigare listan från minnet
//   WaitingLights = newArray; // Uppdatera minnespekaren

//   waitingLightsLength--; // Minska köstorleken

//   return longestWaiter;
// }