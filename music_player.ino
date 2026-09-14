#include "irmodule.h"
#include "lcd_run.h"
#include "songs.h"
#define BUZZER_PIN 9 

extern int buttonNum;
extern String buttonPress; 

extern bool commandSignalReceived;
extern bool numSignalReceived;

extern bool home;

void setup() {
  setupIR();
  setupLCD();
}

void loop() {
  if(home)
  {
    scrollOptions();
  }
  runIR();
  if(numSignalReceived) 
  {
    showSongPlaying(buttonNum);
    startMusic(buttonNum);
    home = false;
  }
  updateMusic();

  if(commandSignalReceived)
  {
    enactControl(buttonPress);
    //showControl(buttonPress);
  }
}
