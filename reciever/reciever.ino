#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but RH_ASK.h needs it to compile
#include "pitches.h"
#include "songs.h"

#define SPEAKER_PIN 11

RH_ASK driver;

void setup() {
  Serial.begin(9600);
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

void play_song(int num_notes, int melody[], int noteDurations[], int tempo) {
  for (int i = 0; i < num_notes; i++){
    int duration = 0;
    // calculate the duration of each note
    if (noteDurations[i] > 0) {
      duration = tempo / noteDurations[i];
    }
    // if it's a negative number, means dotted note
    // increases the duration by half for dotted notes
    else if (noteDurations[i] < 0) {
      duration = tempo / abs(noteDurations[i]) * 1.5;
    }
    tone(SPEAKER_PIN, melody[i], duration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SPEAKER_PIN);
  }
}

void loop() {
  uint8_t buf[1];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen) && buf[0] == 'a') { // Non-blocking
    Serial.println("Playing song");  
    play_song(hpLength,hp,hpDurations,hpTempo);
    Serial.println("Finished playing song");
  }
  else {
    // Use Idle mode, allowing the Arduino to still receive data while sleeping
    LowPower.idle(SLEEP_1S, ADC_OFF, TIMER2_ON, TIMER1_ON, TIMER0_ON, SPI_ON);
  }
}