#include <pitches.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "lcd_run.h"
#include "songs.h"

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

void setupLCD() {
  lcd.begin(16, 2);
  lcd.print("Music Player!");
  delay(500);
}

void scrollOptions() {

}

extern String songList[];

void showSongPlaying(int songNum) {
  lcd.clear();
  lcd.print(songList[songNum]);
}

void showControl(String command) {
  lcd.clear();
  lcd.print(command);
}