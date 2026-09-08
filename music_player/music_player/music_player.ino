#include "irmodule.h"
#include "lcd_run.h"
#include "songs.h"
#define BUZZER_PIN 9 

extern int buttonNum;
extern String buttonPress; 

extern bool commandSignalReceived;
extern bool numSignalReceived;

void setup() {
  // put your setup code here, to run once:
  setupIR();
  setupLCD();
}

void loop() {
  // put your main code here, to run repeatedly:
  runIR();
  if(numSignalReceived) //problem
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
