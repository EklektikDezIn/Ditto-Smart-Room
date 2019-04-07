#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
bool button = true;
int i = 0;
 
void setup() 
{ 
  pinMode(7, INPUT_PULLUP); 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 

void loop() {
   // check if joystick button is pressed
   if(digitalRead(7)){
    button = false;
   }

  delay(20);
  
  // if boolean switch is false and joystick button is pressed
  // flip switch
  if(!digitalRead(7) && button == false && i%2 == 1){
    button = true; i++;
    myservo.attach(9);
    myservo.write(150);
    delay(1500);
    myservo.detach();
   }
   // if boolean switch is false and joystick button is pressed
   // flip switch
   if(!digitalRead(7) && button == false && i%2 == 0){
    button = true; i++;
    myservo.attach(9);
    myservo.write(75);
    delay(1500);
    myservo.detach();
    
   }
  // if boolean switch and joystick button states are different
  // do nothing

}

