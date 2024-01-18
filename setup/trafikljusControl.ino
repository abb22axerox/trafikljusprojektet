// Daniel

// #include <iostream>
#include "variables.h"

using namespace std;

// // INPUT
// int Btn;        // Knapp: int, inom intervallet 1-4
// bool Walk;      // Gå: boolean
// int Turn;       // Sväng: int, inom intervallet 0-2
// int TurnAdjuster[4][3] = {{2, 4, 3}, {4, 3, 1}, {1, 2, 4}, {3, 1, 2}};

// // OUTPUT
// int Light_instructions[2];  // Ljusinstruktioner: [2, 4]

void Traffic_System(int* first, int* second) {
    if (Walk) {
        *first = Btn + 3;
        *second = -1;
//        cout << "Walk: Light_instructions sent if:0" << endl;
    } else {
        if (Turn >= 0 && Turn <= 2) {
            *first = Btn;
            *second = TurnAdjuster[Btn][Turn]; // Justera för att Btn är inom intervallet 1-4
            // cout << "Car: Light_instructions sent id:" << Btn << endl;
        } else {
            // cout << "Insufficient turn" << endl;
        }
    }
}

// int FakeCrontroll() {
//     // Exempel på användning
//     Btn = 2;
//     Walk = false;
//     Turn = 1;
//     Traffic_System();

//     return 0;
// }
// // < OM DU VILL TESTA DENNA KOD ANVÄND DEN NEDANFÖR >

// // INPUT
// int Btn;        // Knapp: int, inom intervallet 1-4
// bool Walk;      // Gå: boolean
// int Turn;       // Sväng: int, inom intervallet 0-2
// int TurnAdjuster[4][3] = {{2, 4, 3}, {4, 3, 1}, {1, 2, 4}, {3, 1, 2}};

// // OUTPUT
// int Light_instructions[2];  // Ljusinstruktioner: [2, 4]

// void Traffic_System() {
//     if (Walk) {
//         Light_instructions[0] = Btn + 3;
//         Light_instructions[1] = 0;  // Gångtrafikljus är inte relevant här
//         Serial.print("Walk: Light_instructions sent if:0\n");
//     } else {
//         if (Turn >= 0 && Turn <= 2) {
//             Light_instructions[0] = Btn;
//             Light_instructions[1] = TurnAdjuster[Btn - 1][Turn];  // Justera för att Btn är inom intervallet 1-4
//             Serial.print("Car: Light_instructions sent id:");S
//             Serial.println(Btn);
//         } else {
//             Serial.println("Insufficient turn");
//         }
//     }
// }

// void setup() {
//     // Ditt setup-kod här
//     Serial.begin(9600);
// }

// void loop() {
//     // Ditt huvudloop-kod här
//     Btn = 2;
//     Walk = false;
//     Turn = 1;
//     Traffic_System();

//     // Lägg till eventuell annan kod för att hantera loop-logik här
//     delay(1000); // Ett exempel på en fördröjning på 1 sekund
// }
