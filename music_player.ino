#include "irmodule.h"
#include "lcd_run.h"
#include "songs.h"

extern int buttonNum;
extern String buttonPress; 

extern bool commandSignalReceived;
extern bool numSignalReceived;

extern bool home;

void setup() 
{
  setupIR();
  setupLCD();
}

void loop() 
{
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
  }
}
