// Viggo
//# INPUT #​
// Light_instructions: [2,4] de som ska bli gröna
#include "variables.h"

void addToQue(int firstLight, int secondLight)
{
  int* newInstructions; // definiera de nya instruktionerna
  int** newArray = new int*[waitingLightsLength + 1];

  for (int i = 0; i < waitingLightsLength; i++) {
    newArray[i] = WaitingLights[i]; // lägg till alla element från WaitingLights till newArray
  }
  newInstructions = new int[2];
  newInstructions[1] = secondLight;
  newInstructions[0] = firstLight;
  
  newArray[waitingLightsLength] = newInstructions; // lägg till det nya elementet
  
  delete[] WaitingLights; // rensa minnet
  WaitingLights = newArray; // uppdatera minnespekaren till att visa till newArray

  waitingLightsLength++; // öka WaitingLights storlek
}

int* getLongestWaiter() {
  if (waitingLightsLength == 0) {
    return nullptr; // om det inte finns någon som väntar
  }

  int* longestWaiter = WaitingLights[0]; // sätt longestWaiter till första elementet

  int** newArray = new int*[waitingLightsLength - 1]; // uppdatera minnet så att den inte får memory leaks

  for (int i = 1; i < waitingLightsLength; ++i) {
    newArray[i - 1] = WaitingLights[i]; // lägg tillbaka elementen
  }

  delete[] WaitingLights; // Ta bort den tidigare listan från minnet
  WaitingLights = newArray; // Uppdatera minnespekaren

  waitingLightsLength--; // Minska köstorleken

  return longestWaiter;
}