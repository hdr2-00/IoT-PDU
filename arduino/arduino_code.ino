#include <ACS712.h>
#include <ZMPT101B.h>
#define SENSITIVITY 220.0f
// Define relay control pins
const int RelayLoad1 = 2 ; //D1
const int RelayLoad2 = 3 ;//D2
const int RelayLoad3 = 4 ;//D5
const int RelayLoad4 = 5 ;  //D6
const int MainRelay  = 2 ;
const int SecondaryRelay = 3;
const int MainIndicator = 4;
const int SecondaryIndicator =5;
const int CurrentSensor1 = A0;
const int CurrentSensor2 = A1;
const int CurrentSensor3 = A2;
const int CurrentSensor4 = A3;
const int VoltageSensor = A4;
boolean LoadState1 = HIGH; // Initially off (adjust as needed)
boolean LoadState2 = HIGH; // Initially off (adjust as needed)
boolean LoadState3 = HIGH;
boolean LoadState4 = HIGH;
boolean MainState = LOW;
boolean SecondaryState = LOW;
bool mainPowerAvailable = false;
bool secPowerAvailable = false;

const int transferDelay = 3;
ACS712 obj1(CurrentSensor1, 5.0, 1023, 185);
ACS712 obj2(CurrentSensor2, 5.0, 1023, 185);
ACS712 obj3(CurrentSensor3, 5.0, 1023, 185);
ACS712 obj4(CurrentSensor4, 5.0, 1023, 185);

ZMPT101B vltg(A4, 50.0);
 int PowerSource = 1 ;
 const int relaypins[] = {2, 3, 4, 5}; 
  int  NUM_RELAYS = 4;
  


void setup() {
  Serial.begin(115200);
  // Configure relay control pins as outputs
  pinMode(MainIndicator, INPUT_PULLUP);
  pinMode(SecondaryIndicator, INPUT_PULLUP);
  pinMode(MainRelay, OUTPUT);
  pinMode(SecondaryRelay, OUTPUT);
  pinMode(RelayLoad1, OUTPUT);
  pinMode(RelayLoad2, OUTPUT);
  pinMode(RelayLoad3, OUTPUT);
  pinMode(RelayLoad4, OUTPUT);
  
  

  // Set initial relay states (optional)
  digitalWrite(MainRelay, LOW);
  digitalWrite(SecondaryRelay, LOW);
  digitalWrite(RelayLoad1, LoadState1);
  digitalWrite(RelayLoad2, LoadState2);
  digitalWrite(RelayLoad3, LoadState3);
  digitalWrite(RelayLoad4, LoadState4);
  vltg.setSensitivity(SENSITIVITY);
    obj1. autoMidPoint(50,1);
  obj2. autoMidPoint(50,1);
  obj3. autoMidPoint(50,1);
   obj4. autoMidPoint(50,1);

  
}

void loop() {


 
  digitalWrite(MainRelay, LOW);
  float crnt1 = obj1.mA_AC(50,1);
  float crnt2 = obj2.mA_AC(50,1);
  float crnt3 = obj3.mA_AC(50,1);
  float crnt4 = obj4.mA_AC(50,1);
  float voltage = vltg.getRmsVoltage();
  
  Serial.print(String(crnt1/(2*1000)));
  Serial.print(",");
  Serial.print(String(crnt2/(2*1000)));
  Serial.print(",");
  Serial.print(String(crnt3/(2*1000)));
  Serial.print(",");
  Serial.print(String(crnt4/(2*1000)));
  Serial.print(",");
  Serial.print(String(voltage*4));
  Serial.print(",");
  Serial.print(String(PowerSource)) ;//+";");
  Serial.println(";");
}
void transferToGenerator() {
  digitalWrite(MainRelay, LOW);
  digitalWrite(SecondaryRelay, LOW);
  PowerSource = 2 ;
  
  // Implement additional logic for handling generator startup (e.g., delay)
}

void transferToMains() {
  digitalWrite(MainRelay, LOW);
  digitalWrite(SecondaryRelay, LOW);
  PowerSource = 1 ;
}
