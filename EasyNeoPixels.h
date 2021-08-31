
/*
  EasyNeoPixels.h - Library for making neopixels more approachable. With added RGBW support.
  Created by Evelyn Masso, April 9, 2017.
  Modified by: Monty Perrotti, August 30, 2021.
*/

#pragma once

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel easyNeoPixels;

void setupEasyNeoPixels(int pin, int num, bool isRGBW) {
  
  if (isRGBW) {
    easyNeoPixels = Adafruit_NeoPixel(num, pin, NEO_RGBW + NEO_KHZ800);
    easyNeoPixels.begin();
    return;
  }
  easyNeoPixels = Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);
  easyNeoPixels.begin();
}

// set the nth neopixel to a particular brightness of white
// meant to be used with val as HIGH or LOW
void writeEasyNeoPixel(int num, int val) {
  easyNeoPixels.setPixelColor(num, easyNeoPixels.Color(val*255,val*255,val*255));
  easyNeoPixels.show();
}

// set the nth neopixel to a particular rgb color
void writeEasyNeoPixel(int num, int r, int g, int b) {
  easyNeoPixels.setPixelColor(num, easyNeoPixels.Color(r,g,b));
  easyNeoPixels.show();
}
