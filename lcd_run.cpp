#include <pitches.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "lcd_run.h"
#include "songs.h"

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);


void setupLCD() {
  lcd.begin(16, 2);
  lcd.print("Music Player!    Music Player!");
  delay(500);
}

extern String songList[];

unsigned long lastMoveTime = 0;

void scrollOptions() {
  lcd.setCursor(0, 1);
  lcd.print("Click a number to play a song!");
  lcd.setCursor(0, 0);
  lcd.print("Music Player!    Music Player!");

  long delay = 400L * 1000; //delay in milliseconds goes first, multiplied by 1000 to get microseconds. don't forget adding the "L" to force multiplication in long. 
  unsigned long now = micros();

  for(int i = 0; i < 40; i++) //for a 16x2 LCD display, it appears that 40 characters are the max that can be scrolled.
  {
    if(now - lastMoveTime >= delay)
    {
      lcd.scrollDisplayLeft();
      lastMoveTime = now;
    }
  }
}

extern String songList[];

void showSongPlaying(int songNum) {
  lcd.clear();
  lcd.print(songList[songNum]);
}

/*void showControl(String command) {
  lcd.clear();
  lcd.print(command);
}*/