#include "songs.h"
#include "pitches.h"
#include "lcd_run.h"
#include <Arduino.h>
#include <avr/pgmspace.h>

#define BUZZER_PIN 9

//the song class creates objects which represent each song 
class Song 
{
  private: 
    int* melodyArr;
    uint8_t* durationArr; 
    int size;
  public:
    Song(int* melodyArr, uint8_t* durationArr, int songSize)
    { 
      this->melodyArr = melodyArr; 
      this->durationArr = durationArr;
      size = songSize; 
    }
  int getSize()
  { 
    return size; 
  }
  int getNote(int index)
  { 
    return pgm_read_word(&melodyArr[index]); 
  }
  uint8_t getDur(int index)
  { 
    return pgm_read_byte(&durationArr[index]);
  }
  bool retTrue()
  {
    if(size > 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

//arrays storing melody (frequency) and duration information for each song. stored in PROGMEM to save space.
const int HARRY_POTTER_MELODY[] PROGMEM =
{
  REST, NOTE_D4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_C5, 
  NOTE_A4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_F4, NOTE_GS4,
  NOTE_D4, 
  NOTE_D4,
  
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_B4,
  NOTE_G4,
  NOTE_AS4,
   
  NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_AS4,
  NOTE_DS5, NOTE_D5,
  NOTE_CS5, NOTE_A4,
  NOTE_AS4, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_D4,
  NOTE_D5, 
  REST, NOTE_AS4,  
  
  NOTE_D5, NOTE_AS4,
  NOTE_D5, NOTE_AS4,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_AS4,
  NOTE_G4
};

const uint8_t HARRY_POTTER_DURATION[] PROGMEM =
{
  2, 4,
  4, 8, 4,
  2, 4,
  2, 
  2,
  4, 8, 4,
  2, 4,
  1, 
  4,
  
  4, 8, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1,
  4,
   
  2, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1, 
  4, 4,  
  
  2, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1
};

const int ASSASSINS_CREED_MELODY[] PROGMEM = 
{
  NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4,
  NOTE_D4, NOTE_F4, NOTE_G4, NOTE_F4,
  NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5,
  
  NOTE_A5, NOTE_A5, NOTE_D6,
  NOTE_A5, NOTE_A5, NOTE_AS5,
  NOTE_A5, NOTE_G5, NOTE_A5,
  NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_E5,
  
  NOTE_A5, NOTE_AS5, NOTE_A5,
  NOTE_A5, NOTE_D6, NOTE_A5,
  NOTE_AS5, NOTE_F6, NOTE_D6,
  NOTE_D6, NOTE_A5, NOTE_F5, NOTE_E5,
  
  NOTE_D4
};

const uint8_t ASSASSINS_CREED_DURATION[] PROGMEM = 
{
  3, 3, 3, 3,
  3, 3, 3, 3,
  3, 3, 3, 3,
  3, 3, 3, 3,

  2, 4, 2,
  2, 3, 2,
  2, 3, 2,
  2, 2, 6, 6, 2,

  3, 2, 2,
  3, 2, 2,
  3, 2, 2,
  3, 3, 6, 6,
  
  1
};

const int MARIO_BROS_MELODY[] PROGMEM = 
{
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  
  REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST,
  
  REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  REST, 
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
  
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
  
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  REST,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
};

const uint8_t MARIO_BROS_DURATION[] PROGMEM 
{
  8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4, 
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4, 8, 8, 4,
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4,8, 8, 4,
  
  
  4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4,
  2, 2,
  
  4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4,
  2, 2,
  
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  
  8, 4, 8, 8, 8, 8, 8,
  1, 
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8, 4,
  4, 4, 4, 4, 
  4, 8, 4, 4,
  
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4, 8, 8, 4,
  
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4, 8, 8, 4,
  
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2,
  
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8, 8,
  1,
  
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8, 4,
  4, 4, 4, 4, 
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2
}; 

const int PACMAN_MELODY[] PROGMEM =
{
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5,
  NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_C5,
  NOTE_C6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_G6, NOTE_E6,
  
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_B5,
  NOTE_FS5, NOTE_DS5, NOTE_DS5, NOTE_E5, NOTE_F5,
  NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_B5
};

const uint8_t PACMAN_DURATION[] PROGMEM =
{
  16, 16, 16, 16,
  32, 16, 8, 16,
  16, 16, 16, 32, 16, 8,
  
  16, 16, 16, 16, 32,
  16, 8, 32, 32, 32,
  32, 32, 32, 32, 32, 16, 8
};

const int PIRATES_OF_CARIBBEAN_MELODY[] PROGMEM = 
{
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
  
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_D5, NOTE_E5, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
  NOTE_C5, NOTE_A4, NOTE_B4, REST,
  
  NOTE_A4, NOTE_A4,
  //Repeat of first part
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
  
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_D5, NOTE_E5, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
  NOTE_C5, NOTE_A4, NOTE_B4, REST,
  //End of Repeat
  
  NOTE_E5, REST, REST, NOTE_F5, REST, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
  NOTE_D5, REST, REST, NOTE_C5, REST, REST,
  NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4,
  
  NOTE_E5, REST, REST, NOTE_F5, REST, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
  NOTE_D5, REST, REST, NOTE_C5, REST, REST,
  NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4
};

const uint8_t PIRATES_OF_CARIBBEAN_DURATION[] PROGMEM =
{
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  4, 8, 4, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 4,
  
  4, 8,
  //Repeat of First Part
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  4, 8, 4, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 4,
  //End of Repeat
  
  4, 8, 4, 4, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8, 4,
  4, 8, 4, 4, 8, 4,
  8, 8, 8, 8, 8, 2,
  
  4, 8, 4, 4, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8, 4,
  4, 8, 4, 4, 8, 4,
  8, 8, 8, 8, 8, 2
};

const int GODFATHER_MELODY[] PROGMEM =
{
  REST, REST, REST, REST, NOTE_E4, NOTE_A4, NOTE_C5,
  
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_E4, NOTE_E4, NOTE_A4, NOTE_C5,
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E4, NOTE_DS4,

  NOTE_D4, NOTE_D4, NOTE_F4, NOTE_GS4,
  NOTE_B4, NOTE_D4, NOTE_F4, NOTE_GS4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_GS4,

  NOTE_A4, REST, NOTE_A4, NOTE_A4, NOTE_GS4,
  NOTE_G4, NOTE_B4, NOTE_A4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_DS4,

  NOTE_E4, REST, NOTE_E4, NOTE_A4, NOTE_C5,

  //repeat
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_E4, NOTE_E4, NOTE_A4, NOTE_C5,
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E4, NOTE_DS4,

  NOTE_D4, NOTE_D4, NOTE_F4, NOTE_GS4,
  NOTE_B4, NOTE_D4, NOTE_F4, NOTE_GS4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_GS4,

  NOTE_A4, REST, NOTE_A4, NOTE_A4, NOTE_GS4,
  NOTE_G4, NOTE_B4, NOTE_A4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_DS4,

  NOTE_E4
};

const uint8_t GODFATHER_DURATION[] PROGMEM =
{
  4, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  2, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,

  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,

  2, 8, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8, 8,

  2, 8, 8, 8, 8,

  //repeats
  8, 8, 8, 8, 8, 8, 8, 8,
  2, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,

  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,

  2, 8, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8, 8,

  2
};

const int HALO2_MELODY[] PROGMEM =
{
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E5,
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS5,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A5,

  NOTE_A4, NOTE_A5, NOTE_A4, NOTE_A5, NOTE_G5, NOTE_FS5,
  
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E5,
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS5,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5,
  NOTE_A5, NOTE_A4, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_FS5,

  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E5,
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS5,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5,
  NOTE_A5, NOTE_A4, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_FS5,

  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E5
};

const uint8_t HALO2_DURATION[] PROGMEM = 
{
  8, 8, 8, 1,
  8, 8, 8, 1,
  8, 8, 8, 1,
  8, 8, 8, 3,

  8, 8, 8, 8, 8, 8,

  8, 8, 8, 3,
  8, 8, 8, 3,
  8, 8, 8, 3,
  8, 8, 8, 8, 8, 8,

  8, 8, 8, 3,
  8, 8, 8, 3,
  8, 8, 8, 3,
  8, 8, 8, 8, 8, 8,

  8, 8, 8, 1
};

const int PINK_PANTHER_MELODY[] PROGMEM =
{
  REST, REST, REST, NOTE_DS4, 
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
  NOTE_E4, REST, REST, NOTE_DS4,
  
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_E5,
  NOTE_DS5,   
  NOTE_D5, REST, REST, NOTE_DS4, 
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
  
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
  NOTE_E4, REST,
  REST, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4,   
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4
};

const uint8_t PINK_PANTHER_DURATION[] PROGMEM =
{
  2, 4, 8, 8, 
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,   
  2, 16, 16, 16, 16, 
  2, 4, 8, 4,
  
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,
  1,   
  2, 4, 8, 8, 
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,   
  
  2, 16, 16, 16, 16, 
  4, 4,
  4, 8, 8, 8, 8, 8, 8,
  16, 8, 16, 8, 16, 8, 16, 8,   
  16, 16, 16, 16, 16, 2
};

//initialization of songs
//song order: harry potter (0), assassin's creed (1), mario bros (2), pacman (3), pirates of the caribbean (4), the godfather (5), halo 2 (6).
//modify with your favorite songs! check out the HiBit "buzzer" repo--it contains the melody/duration arrays I've used. up to 10 songs can be added.

Song HARRY_POTTER(HARRY_POTTER_MELODY, HARRY_POTTER_DURATION, sizeof(HARRY_POTTER_MELODY) / sizeof(int));
Song ASSASSINS_CREED(ASSASSINS_CREED_MELODY, ASSASSINS_CREED_DURATION, sizeof(ASSASSINS_CREED_MELODY) / sizeof(int));
Song MARIO_BROS(MARIO_BROS_MELODY, MARIO_BROS_DURATION, sizeof(MARIO_BROS_MELODY) / sizeof(int));
Song PACMAN(PACMAN_MELODY, PACMAN_DURATION, sizeof(PACMAN_MELODY) / sizeof(int));
Song PIRATES_OF_CARIBBEAN(PIRATES_OF_CARIBBEAN_MELODY, PIRATES_OF_CARIBBEAN_DURATION, sizeof(PIRATES_OF_CARIBBEAN_MELODY) / sizeof(int));
Song GODFATHER(GODFATHER_MELODY, GODFATHER_DURATION, sizeof(GODFATHER_MELODY) / sizeof(int));
Song HALO2(HALO2_MELODY, HALO2_DURATION, sizeof(HALO2_MELOFY) / sizeof(int));
Song PINK_PANTHER(PINK_PANTHER_MELODY, PINK_PANTHER_DURATION, sizeof(PINK_PANTHER_MELODY) / sizeof(int));

Song songs[] = {HARRY_POTTER, ASSASSINS_CREED, MARIO_BROS, PACMAN, PIRATES_OF_CARIBBEAN, GODFATHER, HALO2, PINK_PANTHER};
String songList[] = {"Harry Potter", "Assassins Creed", "Mario Bros", "Pacman", "Pirates of Caribbean", "Godfather", "Halo 2", "Pink Panther"};

uint8_t songsNum = 5; //the total number of songs in songs[]; will be used for the UP/DOWN functionality in enactCommand()

bool musicPlaying;  //whether or not a song should be playing right now
bool notePlaying;   //whether or not an individual not should be playing right now
bool buzzerState;   //whether or not the buzzer is HIGH or LOW (frequency)
int note = 0;       //index of note in the song

unsigned long noteStartTime = 0;  //when the the note was started
unsigned long lastToggleTime = 0; //when the buzzer was last toggled from HIGH to LOW or vice versa

unsigned long noteDur = 0;     //the duration of the note
unsigned long halfPeriod = 0;  //the duration that the buzzer should be set HIGH or LOW for a given note
unsigned long noteRest = 0;    //the time when the buzzer should be LOW in between notes

int size;       //the number of notes in a song
int songIndex;  //the index of the song in songList[]

int notePitch = 0;           //the frequency of a specific note
uint8_t rawNoteDur = 0;      //what kind of note that specific note is (half note, quarter note, eighth note, etc.)

void startMusic(int selection) 
{
  pinMode(BUZZER_PIN, OUTPUT);
  musicPlaying = true;
  note = 0;
  songIndex = selection;

  size = songs[selection].getSize();

  startNote(selection);
}


void startNote(int selection) 
{
  notePitch = songs[selection].getNote(note);
  rawNoteDur = songs[selection].getDur(note);

  if(notePitch == REST)
  {
    halfPeriod = 0;
  }
  else
  {
    halfPeriod = 500000UL / notePitch; //frequency at which buzzer is toggled high/low
  }

  noteDur = 1000000UL / rawNoteDur; //calculating duration in microseconds of individual note
  noteRest = 1.3 * noteDur;

  noteStartTime = micros();
  lastToggleTime = noteStartTime; 

  buzzerState = false;
  notePlaying = true;

  digitalWrite(BUZZER_PIN, LOW);
}

void updateMusic() 
{
  if(!musicPlaying)
    return;

  unsigned long now = micros();
  
  if(now - noteStartTime >= noteRest) //when it's time for next note, this code gets executed 
  {
    note++;
    if(note >= size) 
    {
      musicPlaying = false;
      digitalWrite(BUZZER_PIN, LOW);
      return;
    }
    startNote(songIndex);
  }
  else if(now - noteStartTime >= noteDur) //determines when the rest should occur
  {
    notePlaying = false;
    digitalWrite(BUZZER_PIN, LOW);
    return;
  }

  if (notePitch == REST)
  {
    digitalWrite(BUZZER_PIN, LOW);
    return;
  } 
  else if(now - lastToggleTime >= halfPeriod && notePlaying) //toggling the buzzer HIGH/LOW to generate specific frequency of note
  {
    lastToggleTime = now;
    buzzerState = !buzzerState;
    digitalWrite(BUZZER_PIN, buzzerState);
  }
}

bool home = true;               //whether or not the LCD display is on the home screen (i.e. not displaying a song name)
unsigned long durationSum = 0;  //must be unsigned long for the while loop to functions properly
unsigned long skipDur = 2000;   //how much to skip ahead/backward in millis 

void enactControl(String command) 
{
  if(command == "VOL-") //DAC converter/digtial potentiometer necessary for this
  {

  }
  else if(command == "VOL+") //DAC converter/digtial potentiometer necessary for this
  {
    
  }
  else if(command == "PLAYPAUSE") //stops/resumes the music
  {
    musicPlaying = !musicPlaying;
    if(musicPlaying)
    {
      Serial.print("playing!");
    }
    else
    {
      Serial.print("not playing!");
    }
  }
  else if(command == "SKIPBACK")
  {
    while(durationSum < skipDur * 1000) //milliseconds to be skipped on left, multiplied by 1000 to get duration in microseconds
    {
      durationSum += 1.3*(1000000UL / songs[songIndex].getDur(note));
      note--;
    }
    durationSum = 0;

    if(note < 0)
    {
      note = 0;
    }
  }
  else if(command == "SKIPFOR")
  {
    while(durationSum < skipDur * 1000) //milliseconds to be skipped on left, multiplied by 1000 to get duration in microseconds
    {
      durationSum += 1.3*(1000000UL / songs[songIndex].getDur(note));
      note++;
    }
    durationSum = 0;

    if(note >= size) //preventing note from going out of song duration array bounds
    {
      musicPlaying = false;
      digitalWrite(BUZZER_PIN, LOW);
      return;
    }
  }
  else if(command == "UP") //play the song one index above the current song in songs[]
  {
    if(songIndex < songsNum)
    {
      musicPlaying = false;
      songIndex++;
      startMusic(songIndex); 
      showSongPlaying(songIndex);
    }
  }
  else if(command == "DOWN") //play the song one index below the current song in songs[]
  {
    if(songIndex > 0)
    {
      musicPlaying = false;
      songIndex--;
      startMusic(songIndex); 
      showSongPlaying(songIndex);
    }
  }
  else if(command == "ONOFF")
  {
    home = true; 
    musicPlaying = false;
  }
}
