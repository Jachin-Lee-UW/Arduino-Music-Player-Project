#ifndef SONGS_H
#define SONGS_H

#include <Arduino.h>

void playMusic(int);
void startMusic(int);
void startNote(int);
void updateMusic();
void enactControl(String command);

#endif