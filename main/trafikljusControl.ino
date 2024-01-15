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
function traffic (Btn, Walk, Turn, G_traffic:Array, C_Traffic:Array, TurnAdjuster:Array)

OUTPUT = [[],[]]

if Walk == true:
    active_light = G_traffic[Btn -1]
    OUTPUT[0][active_light] # Turns Green
else:  

 for G_light in G_traffic:
    OUTPUT[1][ G_light [0]]# Turns every G_light Red
    active_light = C_traffic[Btn - 1]
    OUTPUT[1][ C_light [0]] # Turns every G_light Red
    OUTPUT[0][ active_light] # Turns Green
    endpoint = TurnAdjuster[Btn][Turn] # Ger oss stationen den åker till
    OUTPUT[0][endpoint]# Turn Endpoint green to allow traffic circulation
  return OUTPUT
  
  OUTPUT = traffic (Btn, Walk, Turn, G_traffic, C_Traffic) 
}
