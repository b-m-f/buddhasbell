#include "FastLED.h"

const int numberOfLeds = 50;
CRGB leds[numberOfLeds];
bool goUp = true;

int maxBrightness = 180;
int minBrightness = 50;
int delayTime = 30;

void setup() { FastLED.addLeds<NEOPIXEL, 8>(leds, numberOfLeds); }



void loop() { 
  static uint8_t hue = 200; // 0 = red
  static uint8_t brightness = 0;
//  for (int i = 0; i < numberOfLeds; i++) {

     if (goUp) {
//      leds[i] = CHSV(hue, 255, brightness++); 
      FastLED.showColor(CHSV(hue, 255, brightness++));
    if (brightness == maxBrightness) {
      goUp = false;  
    }
  }
  else {
    goUp = false;
//    leds[i] = CHSV(hue, 255, brightness--); 
      FastLED.showColor(CHSV(hue, 255, brightness--));
    if(brightness == minBrightness) {
      goUp = true;
    }
  }
//  FastLED.show();
  
//  }
  delay(delayTime);
  
}
