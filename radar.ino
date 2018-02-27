/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


#include <Servo.h>
#include "pitches.h"

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int trig=6;
int echo=7;
int duration=0;
int dist=0;
int limit = 5000;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

unsigned long cMillis;
unsigned long prevMillis = 0;
unsigned long prevMillis2 = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
   // delay(pauseBetweenNotes);

   cMillis = millis();
   //after pauseBetweenNotes, stop the tone playing:
   if (cMillis - prevMillis >= pauseBetweenNotes)
    {
      noTone(8);
      prevMillis = cMillis;
    }
  }

   // initialize the LED pin as an output:
 // pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {

    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
   // digitalWrite(ledPin, HIGH);
    use_sensor();
    move_servo();
    Serial.println(duration);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    //stop_servo_audio();
  }
  
   
}

void play_sound()
{unsigned cMillis2 = millis();
 tone(8, NOTE_A6, 300);
 cMillis2 = millis();
   //after pauseBetweenNotes, stop the tone playing:
   if (cMillis2 - prevMillis2 >= 20)
    {
      noTone(8);
      prevMillis2 = cMillis2;
    }  
}

void use_sensor()
{
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  //delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration=pulseIn(echo, HIGH);
  dist=duration/2/29;

  if (dist <= limit)
      play_sound();
}

void move_servo(){
  
  unsigned long cMillis3 = millis();
  unsigned long prevMillis3 = 0;
  unsigned long cMillis4 = millis();
  unsigned long prevMillis4 = 0;

  
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
                                          // in steps of 1 degree
         /* if (cMillis3 - prevMillis3 >= 20)
          {
            myservo.write(pos);                   // tell servo to go to position in variable 'pos'
            prevMillis3 = cMillis3;
          }  
          */

          myservo.write(pos);
          delay(15);                            // waits 15ms for the servo to reach the position
    }
    
    for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
  
        /* if (cMillis4 - prevMillis4 >= 20)
          {
            myservo.write(pos);                   // tell servo to go to position in variable 'pos'
            prevMillis4 = cMillis4;
          } */
        myservo.write(pos);
          delay(15);    
       }
}

