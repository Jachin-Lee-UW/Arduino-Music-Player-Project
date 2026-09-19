#include "lcd_run.h"
#include "songs.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

void setupLCD() 
{
  lcd.begin(16, 2);
  lcd.print("Music Player!    Music Player!");
  delay(500);
}

unsigned long lastMoveTime = 0;
long scrollDelay = 400L * 1000; //delay in milliseconds goes first, multiplied by 1000 to get microseconds. don't forget adding the "L" to force multiplication in long. 

void scrollOptions() 
{
  lcd.setCursor(0, 1);
  lcd.print("Click a number to play a song!");
  lcd.setCursor(0, 0);
  lcd.print("Music Player!    Music Player!");

  unsigned long now = micros();

  for(int i = 0; i < 40; i++)       //for a 16x2 LCD display, it appears that 40 characters are the max that can be scrolled. 
  {                                 //setting the bounds of the loop to 40 allows for continuous scrolling w/out text overlap.
    if(now - lastMoveTime >= scrollDelay)
    {
      lcd.scrollDisplayLeft();
      lastMoveTime = now;
    }
  }
}

extern String songList[];

void showSongPlaying(int songNum) 
{
  lcd.clear();
  lcd.print(songList[songNum]);
}