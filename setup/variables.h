#ifndef VARIABLES_H
#define VARIABLES_H

int Btn;
bool Walk;
void knappar();
void finalExecution_loop();
int Turn;
bool ButtonStates[];
void LightState();
void display_setup();
void display_loop();
int waitingLightsLength = 0;
int** WaitingLights = nullptr;
void addToQue();
int* getLongestWaiter();
extern int TurnAdjuster[][3];
int Light_instructions[];
void pot_loop();
#endif // VARIABLES_H