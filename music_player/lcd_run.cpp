#include <pitches.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "lcd_run.h"

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

extern String songList[];

void setupLCD() {
  lcd.begin(16, 2);
  lcd.print("Music Player!");
  delay(500);
}

void showSongPlaying(int songNum) {
  lcd.clear();
  lcd.print(songList[songNum]);
}

void showControl(String command) {
  lcd.clear();
  lcd.print(command);
}

void enactControl(String command) {
  if(command == "VOL-")
  {

  }
  else if(command == "VOL+")
  {
    
  }
  else if(command == "PLAYPAUSE")
  {

  }
  else if(command == "SKIPBACK")
  {

  }
  else if(command == "SKIPFOR")
  {

  }
  else if(command == "UP")
  {

  }
  else if(command == "DOWN")
  {

  }
  else if(command == "ONOFF")
  {
    
  }
}