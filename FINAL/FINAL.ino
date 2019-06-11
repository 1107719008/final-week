/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_C5,NOTE_G4,NOTE_F4,NOTE_D4,NOTE_A4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_C4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_AS4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_G4
  ,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_F4,NOTE_C5,NOTE_A4,NOTE_G4,NOTE_C5,NOTE_G4,NOTE_F4,NOTE_D4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_C4, NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_C4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_AS4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_F4
  };
int melod[] = {
   NOTE_G4,NOTE_E5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_F5, NOTE_A4, NOTE_A4, NOTE_E5, NOTE_D5,NOTE_D5, NOTE_G4, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5,
NOTE_G5, NOTE_F5, NOTE_E5, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5,
NOTE_A5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_G5, NOTE_C5,
NOTE_C5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5,
NOTE_C5, NOTE_A5, NOTE_A5, NOTE_C5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_B5, NOTE_C5, NOTE_G5 ,
NOTE_A5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_B5
  };
// note durations: 4 = quarter note, 8 = eighth note, etc.:
float noteDurations[] = {
 4,4,4,4,1.5,4,2,2,2,4,4,1.5,4,1 ,4,4,2,2,4,4,2,2,4,4,2,4,4,4,4,1,4,4,4,4,1.5,4,2,2,2,4,4,2,4,4,1,2,2,2,4,4,2,2,4,4,2,4,4,4,4,1};
float noteDurationn[]={
  4,4,1,4,4,1,4,4,0.5,4,4,1,2,1,4,4,0.5,4,4,1,4,4,1,4,4,0.5,
  2,2,2,2,1,4,4,0.5,
  1,2,2,2,2,0.75,1,
  4,4,2,2,2,2,2,2,0.75,1,
  4,4,1,2,2,2,2,2,2,2,1,
  2,2,2,2,2,2,2,1,4,4,1
};

int latchPin = 8;

int clockPin = 12;

int dataPin = 11;
const int button=7;
int play=0;
int state=0;
byte colDataMatrix[8] = { B01111111,

B10111111,

B11011111,

B11101111,

B11110111,

B11111011,

B11111101,

B11111110

};

byte rowDataMatrix[8] = {

B00111100,

B01000010,

B10100101,

B10000001,
B10011001,
B10100101,



B01000010,

B00111100


};
byte rowDataMatrix1[8] = {
B00111100,

B01000010,

B10100101,

B10000001,

B10100101,

B10011001,

B01000010,

B00111100

};

// 定義顯示器顯示的時間 (延遲時間), 預設 1ms

int delay_time = 1;
void setup() {
   
  Serial.begin(9600);
    pinMode(button,INPUT);

pinMode(latchPin,OUTPUT);

pinMode(clockPin,OUTPUT);

pinMode(dataPin,OUTPUT);

  // iterate over the notes of the melody:
 
}



void loop() {
  
 state=digitalRead(button);
 Serial.println(state);
 if(state==HIGH){play=!play;}
if(play==0){
  

  for (int thisNote = 0; thisNote < 60; thisNote++) {
    
    state=digitalRead(button);
 Serial.println(state);
 if(state==HIGH){play=!play;}
 if(play!=0){break;}
 digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B01111111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B00111100);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B10111111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B01000010);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11011111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B10100101);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11101111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B10000001);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11110111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B10100101);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11111011);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B10011001);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11111101);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B01000010);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11111110);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B00111100);  //row
  digitalWrite(latchPin, 1);



    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(4, melody[thisNote], noteDuration);
   /* for(int i = 0; i < 8 ; i++){
  //byte colData = colDataMatrix[i];

digitalWrite(latchPin,LOW);

// pickDigit(i);

shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix1[i]);

//shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

digitalWrite(latchPin,HIGH);

delay(1);}
*/
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.0;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(4);
  
  }




  
}
else if(play==1){
 for (int thisNote = 0; thisNote < 73; thisNote++) {
    state=digitalRead(button);
 Serial.println(state);
 if(state==HIGH){play=!play;}
  if(play!=1){break;}
 
     digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B01111111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B00111100);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B10111111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B01000010);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11011111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B10100101);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11101111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST,B10100101);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11110111);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B10100101);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11111011);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B10011001);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11111101);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B01000010);  //row
  digitalWrite(latchPin, 1);

  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, B11111110);  //mask(col)
  shiftOut(dataPin, clockPin, MSBFIRST, B00111100);  //row
  digitalWrite(latchPin, 1);
    
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurationn[thisNote];
    tone(4, melod[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.0;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(4);
    
/*for(int i = 0; i < 8 ; i++){

//byte colData = colDataMatrix[i];

digitalWrite(latchPin,LOW);

// pickDigit(i);

shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);

//shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

digitalWrite(latchPin,HIGH);

delay(delay_time);
}
*/
 }
}
}
void pickDigit(int x) {

byte rowByte = 1 << x;

shiftOut(dataPin, clockPin, MSBFIRST, rowByte);

}
