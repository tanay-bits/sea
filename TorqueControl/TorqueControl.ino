
#include <Stepper.h>
#include <Encoder.h>
Encoder myEnc(2, 3);
//const int stepsMove = 900;  // change this to fit the number of steps per revolution
                                     // for your motor
//int count = 0;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(7200,8,9,10,11);            

void setup() {
  // set the rpm:
  myStepper.setSpeed(5);
  // initialize the serial port:
  Serial.begin(9600);
}

//int oldPosition  = 0;
const int ref = 10;

void loop() {

  int newPosition = myEnc.read();
  int error = ref - newPosition;
//  if(newPosition >2){
  if(error > 1){
      myStepper.step(2);
//      count++;
//      int newPosition = myEnc.read();
//      if(abs(newPosition) - abs(oldPosition) > 10){
//        delay(2000);
//        oldPosition = newPosition;
//      }
//      count = abs(stepsMove);
//      delay(500);
  }
  else if(error < -1){
    myStepper.step(-2);
  }
  
        Serial.println(error);

//  }
}

