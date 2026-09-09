#include <Arduino.h>
#include <IRremote.hpp>
#include "irmodule.h"
#include "songs.h"
#include "lcd_run.h"

#define IR_RECEIVE_PIN 2

int buttonNum = -1;         //the number of the button last pressed on the IR remote
String buttonPress = "";    //the command of the button last pressed on the IR remote

bool numSignalReceived = false;      //whether or not a numerical button command has been receieved 
bool commandSignalReceived = false;  //whether or not a non-numerical button command has been receieved

void setupIR() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("Receiver setup complete!");
}

void runIR() {
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
