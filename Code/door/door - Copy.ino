#include <Servo.h>
#include <Wire.h>
#include <Stepper.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
LiquidCrystal_I2C lcd(0x27, 16, 2);
bool pbutton = true;
bool lights = true;
int counter = 0;

void setup()
{
  Serial.begin(9600);
  stepper.setSpeed(70);
  lcd.init();       // initialize the lcd
  lcd.backlight();  // turn on backlight
  lcd.clear();      // clear the display
  lcd.print("DITTO");
}

void loop() {
  if (Serial.available() > 0) {
    int letter = Serial.read();
    Serial.write((char)letter);
    //if (lights == false) {
    // if(myservo.read()<50||myservo.read()>145){
    //   lights = true;
    //   myservo.detach();

    // }
    //}

    if (letter == 'p') {
      lights = false;
      myservo.attach(7);
      if (pbutton) {
        myservo.write(65);
      }
      else {
        myservo.write(135);
      }
      pbutton = !pbutton;
    }
    if (letter == 'k') {
      for (int i = 0; i < 95; i++) {
        stepper.step(11);
      }
    }
    if (letter == 's')
    {
      lcd.clear();
      while (Serial.available() > 0) {
        // display each character to the LCD
        
      Serial.write("here");
        lcd.print((char)Serial.read());
      }
    }
  }
}
