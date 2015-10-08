
#include <Stepper.h>
#include <Encoder.h>
Encoder myEnc(2, 3);
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(7200,8,9,10,11);            

void setup() {
  // set the rpm:
  myStepper.setSpeed(5);
  // initialize the serial port:
//  Serial.begin(115200);
}

int oldPosition  = 0;
int motion = 300;
int diff = 0;

void loop() {

  int newPosition = myEnc.read();
  diff = abs(newPosition) - abs(oldPosition);
  if(diff > 0){
        myStepper.step(motion);
        oldPosition = newPosition;
      }
  
      
      
      
//      Serial.println(myEnc.read());
//      delay(500);
  
}

