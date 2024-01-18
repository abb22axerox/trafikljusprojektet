#ifndef VARIABLES_H
#define VARIABLES_H

int Btn;
bool Walk;
void knappar();
void finalExecution_loop();
int Turn;
bool* ButtonStates;
void LightState();
void display_setup();
void display_loop();
int waitingLightsLength = 0;
int** WaitingLights = nullptr;
void addToQue();
int* getLongestWaiter();
extern int TurnAdjuster[][3];
void pot_loop();
void Traffic_System(int* first, int* second);
#endif // VARIABLES_H
