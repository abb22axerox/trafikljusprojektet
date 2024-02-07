#ifndef VARIABLES_H
#define VARIABLES_H

int Btn = 0;
int prevBtn = 0; // flagga för Btn, undvika att köra koden flera gånger
int displayBtn = 0; // flagga för display
bool Walk;
void knappar_loop();
void finalExecution_loop();
int Turn;
void StartLightCycle();
void display_setup();
void display_loop();
int waitingLightsLength = 0;
int** WaitingLights = nullptr;
void addToQue();
int* getLongestWaiter();
extern int TurnAdjuster[][3];
void pot_loop();
void Traffic_System(int* first, int* second);
bool button_state_0 = false;
bool button_state_1 = false;
bool button_state_2 = false;
bool button_state_3 = false;
bool button_state_4 = false;
#endif // VARIABLES_H
