#ifndef VARIABLES_H
#define VARIABLES_H

int Btn;
bool Walk;
void knappar();
void finalExecution_loop();
int Turn;
bool ButtonStates[];
void LightState();
int TurnAdjuster[];
void display_setup();
void display_loop();
int waitingLightsLength = 0;
int** WaitingLights = nullptr;
void addToQue();
int* getLongestWaiter();
#endif // VARIABLES_H