//# INPUT #​
//Btn, Walk, Turn, G_traffic:Array, C_Traffic:Array, TurnAdjuster:Array

//# OUTPUT #​
//Light_instructions: [​
//[trafikljus namn för grön],​
//[trafikljusnamn för röd]​
//]

void setup() {
  // put your setup code here, to run once:

}

void loop() {
// function traffic (Btn, Walk, Turn, G_traffic:Array, C_Traffic:Array, TurnAdjuster:Array)

// OUTPUT = [[],[]]

// if Walk == true:
//     active_light = G_traffic[Btn -1]
//     OUTPUT[0][active_light] # Turns Green
// else:  

//  for G_light in G_traffic:
//     OUTPUT[1][ G_light [0]]# Turns every G_light Red
//     active_light = C_traffic[Btn - 1]
//     OUTPUT[1][ C_light [0]] # Turns every G_light Red
//     OUTPUT[0][ active_light] # Turns Green
//     endpoint = TurnAdjuster[Btn][Turn] # Ger oss stationen den åker till
//     OUTPUT[0][endpoint]# Turn Endpoint green to allow traffic circulation
//   return OUTPUT
  
//   OUTPUT = traffic (Btn, Walk, Turn, G_traffic, C_Traffic) #include <iostream>
#include <string>

// Function prototype
void traffic(bool Btn, bool Walk, int Turn, const std::string G_traffic[], const std::string C_traffic[], const std::string TurnAdjuster[][3], std::string OUTPUT[][1]);

int main() {
    // Sample input values
    bool Btn = true;
    bool Walk = true;
    int Turn = 0;
    std::string G_traffic[] = {"Green1", "Green2", "Green3"};
    std::string C_traffic[] = {"Red1", "Red2", "Red3"};
    std::string TurnAdjuster[][3] = {{"Station1", "Station2", "Station3"},
                                     {"Station4", "Station5", "Station6"}};

    // Call the traffic function
    std::string OUTPUT[2][1];
    traffic(Btn, Walk, Turn, G_traffic, C_traffic, TurnAdjuster, OUTPUT);

    // Display the results
    std::cout << "Light_instructions: [" << std::endl;
    std::cout << "[" << OUTPUT[0][0] << "]," << std::endl;
    std::cout << "[" << OUTPUT[1][0] << "]" << std::endl;
    std::cout << "]" << std::endl;

    return 0;
}

void traffic(bool Btn, bool Walk, int Turn, const std::string G_traffic[], const std::string C_traffic[], const std::string TurnAdjuster[][3], std::string OUTPUT[][1]) {
    if (Walk) {
        int active_light = Btn ? 0 : 1;
        OUTPUT[0][0] = G_traffic[active_light]; // Turns Green
    } else {
        for (int i = 0; i < 3; ++i) {
            OUTPUT[1][0] = G_traffic[i]; // Turns every G_light Red
            int active_light = Btn ? i : i;
            OUTPUT[1][0] = C_traffic[i]; // Turns every G_light Red
            OUTPUT[0][0] = C_traffic[active_light]; // Turns Green
            std::string endpoint = TurnAdjuster[Btn ? 0 : 1][Turn]; // Gets the station it travels to
            OUTPUT[0][0] = endpoint; // Turn Endpoint green to allow traffic circulation
        }
    }
}


}
