#include <Arduino.h>
#include <IRremote.hpp>
#include "irmodule.h"
#include "songs.h"
#include "lcd_run.h"

#define IR_RECEIVE_PIN 2

int buttonNum = -1;
String buttonPress = "";

bool numSignalReceived = false;
bool commandSignalReceived = false;

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
    int command = IrReceiver.decodedIRData.command;
    IrReceiver.resume();
    switch (command)
    {
      case 22:
        buttonNum = 0;
        numSignalReceived = true;
        break;
      case 12:
        buttonNum = 1;
        numSignalReceived = true;
        break;
      case 24:
        buttonNum = 2;
        numSignalReceived = true;
        break;
      case 94:
        buttonNum = 3;
        numSignalReceived = true;
        break;
      case 8:
        buttonNum = 4;
        numSignalReceived = true;
        break;
      case 28:
        buttonNum = 5;
        numSignalReceived = true;
        break;
      case 90:
        buttonNum = 6;
        numSignalReceived = true;
        break;
      case 66:
        buttonNum = 7;
        numSignalReceived = true;
        break;
      case 82:
        buttonNum = 8;
        numSignalReceived = true;
        break;
      case 74: 
        buttonNum = 9;
        numSignalReceived = true;
        break;

      case 21:
        buttonPress = "VOL-";
        commandSignalReceived = true;
        break;
      case 70:
        buttonPress = "VOL+";
        commandSignalReceived = true;
        break;
      case 64:
        buttonPress = "PLAYPAUSE";
        commandSignalReceived = true;
        break;
      case 69:
        buttonPress = "ONOFF";
        commandSignalReceived = true;
        break;
      case 9:
        buttonPress = "UP";
        commandSignalReceived = true;
        break;
      case 7:
        buttonPress = "DOWN";
        commandSignalReceived = true;
        break;
      case 68:
        buttonPress = "SKIPBACK";
        commandSignalReceived = true;
        break;
      case 67:
        buttonPress = "SKIPFOR";
        commandSignalReceived = true;
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
  else
  {
    numSignalReceived = false;
    commandSignalReceived = false;
  }
} 
