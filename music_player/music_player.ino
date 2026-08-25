#include "irmodule.h"
#include "lcd_run.h"
#include "songs.h"
#define BUZZER_PIN 9 

extern int buttonNum;
extern String buttonPress; 

extern bool musicPlaying;

int lastButtonNum = -1;

void setup() {
  // put your setup code here, to run once:
  setupIR();
  setupLCD();
}

void loop() {
  // put your main code here, to run repeatedly:
  runIR();
  if(buttonNum > -1)
  {
    if(buttonNum != lastButtonNum && musicPlaying == false)
    {
      lastButtonNum = buttonNum;
      showSongPlaying(buttonNum);
    }
    if(musicPlaying == false)
    {
      startMusic(buttonNum);
    }
    updateMusic();
  }
  else if(buttonPress != "")
  {
    showControl(buttonPress);
    enactControl(buttonPress);
    buttonPress = "";
  } 
}
