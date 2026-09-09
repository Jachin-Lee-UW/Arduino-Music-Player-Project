#include "irmodule.h"
#include "lcd_run.h"
#include "songs.h"
#define BUZZER_PIN 9 

extern int buttonNum;
extern String buttonPress; 

extern bool commandSignalReceived;
extern bool numSignalReceived;

void setup() {
  setupIR();
  setupLCD();
}

void loop() {
  runIR();
  if(numSignalReceived) 
  {
    showSongPlaying(buttonNum);
    startMusic(buttonNum);
  }
  updateMusic();

  if(commandSignalReceived)
  {
    enactControl(buttonPress);
    showControl(buttonPress);
  }
}
