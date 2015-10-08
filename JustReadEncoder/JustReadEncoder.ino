
//#include <Stepper.h>
#include <Encoder.h>
Encoder myEnc(2, 3);
// initialize the stepper library on pins 8 through 11:
//Stepper myStepper(7200,8,9,10,11);            

void setup() {
  // set the rpm:
//  myStepper.setSpeed(5);
  // initialize the serial port:
  Serial.begin(9600);
  Serial.println("Display relative rotation");
}

int oldPosition  = 0;
int diff = 0;

void loop() {

  int newPosition = myEnc.read();
  diff = newPosition - oldPosition;
  if(abs(diff) > 0){
    Serial.println(diff);
    oldPosition = newPosition;
  }  
      

//      delay(500);
  
}

