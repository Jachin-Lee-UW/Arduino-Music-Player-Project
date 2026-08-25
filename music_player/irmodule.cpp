#include <Arduino.h>
#include <IRremote.hpp>
#include "irmodule.h"
#include "songs.h"
#include "lcd_run.h"

#define IR_RECEIVE_PIN 2

int buttonNum = -1;
String buttonPress = "";

void setupIR() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("Receiver setup complete!");
}

void runIR() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    Serial.println("registered!");
    IrReceiver.printIRResultShort(&Serial);
    int command = IrReceiver.decodedIRData.command;
    IrReceiver.resume();
    Serial.print(" command: ");
    Serial.println(command);
    buttonNum = -1;
    buttonPress = "";
    switch (command)
    {
      case 22:
        buttonNum = 0;
        break;
      case 12:
        buttonNum = 1;
        break;
      case 24:
        buttonNum = 2;
        break;
      case 94:
        buttonNum = 3;
        break;
      case 8:
        buttonNum = 4;
        break;
      case 28:
        buttonNum = 5;
        break;
      case 90:
        buttonNum = 6;
        break;
      case 66:
        buttonNum = 7;
        break;
      case 82:
        buttonNum = 8;
        break;
      case 74: 
        buttonNum = 9;
        break;

      case 21:
        buttonPress = "VOL-";
        break;
      case 70:
        buttonPress = "VOL+";
        break;
      case 64:
        buttonPress = "PLAYPAUSE";
        break;
      case 69:
        buttonPress = "ONOFF";
        break;
      case 9:
        buttonPress = "UP";
        break;
      case 7:
        buttonPress = "DOWN";
        break;
      case 68:
        buttonPress = "SKIPBACK";
        break;
      case 67:
        buttonPress = "SKIPFOR";
        break;
    }
    if(buttonNum >= 0)
    {
      Serial.println(buttonNum);
    }
    if(buttonPress != "")
    {
      Serial.println(buttonPress);
    }
  }
} 
