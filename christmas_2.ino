/*
  Arduino Christmas Songs
  
  Based on a project and code
  by Dipto Pratyaksa, updated on 31/3/13

  Modified for Christmas by Joshi,
  on Dec 17th, 2017.
*/

#include "pitches.h"
#define melodyPin 9

const int buttonpin=2;
volatile bool player=false;

void setup(void) {

  pinMode(9, OUTPUT); // Buzzer
  pinMode(13, OUTPUT); // Led indicator when singing a note
  pinMode(2, INPUT);
  attachInterrupt(0, pin_ISR, RISING);
  pinMode(8, OUTPUT); //leds do trenzinho
}

const int16_t silentNight[] PROGMEM = {
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_D5,2, NOTE_D5,4,
  NOTE_B4,-2,
  NOTE_C5,2, NOTE_C5,4,
  NOTE_G4,-2,
  NOTE_A4,2, NOTE_A4,4,
  NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_A4,2, NOTE_A4,4,
  NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_D5,2, NOTE_D5,4,
  NOTE_F5,-4, NOTE_D5,8, NOTE_B4,4,
  NOTE_C5,-2,
  NOTE_E5,-2,
  NOTE_C5,4, NOTE_G4,4, NOTE_E4,4,
  NOTE_G4,-4, NOTE_F4,8, NOTE_D4,4,
  NOTE_C4,-2,
};

const int16_t weWishYou[] PROGMEM = {
  NOTE_C5,4, 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4, 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2,
};

const int16_t jingleBells[] PROGMEM {
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,2,
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,2,
  NOTE_E5,4, NOTE_G5,4, NOTE_C5,4, NOTE_D5,4,
  NOTE_E5,-2, REST,8,
  NOTE_F5,4, NOTE_F5,4, NOTE_F5,-4, NOTE_F5,8,
  NOTE_F5,4, NOTE_E5,4, NOTE_E5,4, NOTE_E5,8, NOTE_E5,8,
  NOTE_E5,4, NOTE_D5,4, NOTE_D5,4, NOTE_E5,4,
  NOTE_D5,2, NOTE_G5,2,
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,2,
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,2,
  NOTE_E5,4, NOTE_G5,4, NOTE_C5,4, NOTE_D5,4,
  NOTE_E5,-2, REST,8,
  NOTE_F5,4, NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,
  NOTE_F5,4, NOTE_E5,4, NOTE_E5,4, NOTE_E5,8, NOTE_E5,8,
  NOTE_G5,4, NOTE_G5,4, NOTE_F5,4, NOTE_D5,4,
  NOTE_C5,-2
};

const int16_t santaClausIsComin[] PROGMEM {
  NOTE_G4,8,
  NOTE_E4,8, NOTE_F4,8, NOTE_G4,4, NOTE_G4,4, NOTE_G4,4,
  NOTE_A4,8, NOTE_B4,8, NOTE_C5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_E4,8, NOTE_F4,8, NOTE_G4,4, NOTE_G4,4, NOTE_G4,4,
  NOTE_A4,8, NOTE_G4,8, NOTE_F4,4, NOTE_F4,2,
  NOTE_E4,4, NOTE_G4,4, NOTE_C4,4, NOTE_E4,4,
  NOTE_D4,4, NOTE_F4,2, NOTE_B3,4,
  NOTE_C4,-2, REST,4,
  NOTE_G4,8,
  NOTE_E4,8, NOTE_F4,8, NOTE_G4,4, NOTE_G4,4, NOTE_G4,4,
  NOTE_A4,8, NOTE_B4,8, NOTE_C5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_E4,8, NOTE_F4,8, NOTE_G4,4, NOTE_G4,4, NOTE_G4,4,
  NOTE_A4,8, NOTE_G4,8, NOTE_F4,4, NOTE_F4,2,
  NOTE_E4,4, NOTE_G4,4, NOTE_C4,4, NOTE_E4,4,
  NOTE_D4,4, NOTE_F4,2, NOTE_D5,4,
  NOTE_C5,1
};

void loop() {
  while (player == true) {
    mediaplayer();
  };
  if (player == false) {
    digitalWrite(8, HIGH);
  }
}

void pin_ISR() {
  player = !player; 
}

void mediaplayer() {
  musicPlayer(silentNight, sizeof(silentNight) / sizeof(silentNight[0]) / 2, 130);
  delay(2000);
  musicPlayer(weWishYou, sizeof(weWishYou) / sizeof(weWishYou[0]) / 2, 160);
  delay(2000);
  musicPlayer(jingleBells, sizeof(jingleBells) / sizeof(jingleBells[0]) / 2, 180);
  delay(2000);
  musicPlayer(santaClausIsComin, sizeof(santaClausIsComin) / sizeof(santaClausIsComin[0]) / 2, 137);
  delay(2000);
}


void musicPlayer(int16_t melody[], uint16_t notes, uint8_t songTempo) {
  uint16_t wholenote = (60000 * 4) / songTempo;
  int8_t divider;
  uint16_t noteDuration;
  for (uint16_t i=0; i<notes*2; i+=2) {
    divider = pgm_read_word(&melody[i+1]);
    if (divider > 0) {
      noteDuration = wholenote / divider;
    } else {
      noteDuration = wholenote / abs(divider) * 1.5;
    }
    if (player == false) {
      return;
    }
    tone(melodyPin, pgm_read_word(&melody[i]), noteDuration * 0.9);
    digitalWrite(8, HIGH);
    delay(noteDuration);
    noTone(melodyPin);
    digitalWrite(8, LOW);
  }
}