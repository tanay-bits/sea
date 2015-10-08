
#include <Stepper.h>
#include <Encoder.h>
Encoder myEnc(2, 3);
const int dis = 3600;  
int count = 0;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(7200,8,9,10,11);            

void setup() {
  // set the rpm:
  myStepper.setSpeed(5);
  // initialize the serial port:
//  Serial.begin(115200);
}

int oldPosition  = 0;
//int motion = 1;

void loop() {


  while(count < abs(dis)){
      myStepper.step(1);
      count++;
      int newPosition = myEnc.read();
      if(abs(newPosition) - abs(oldPosition) > 4){
        delay(2000);
        oldPosition = newPosition;
      }
//      Serial.println(myEnc.read());
//      delay(500);
  }
  
//  else{
//      count = 0;
//      motion = -motion;
//  }
// 
  
}

