#include "FastLED.h"

const int numberOfLeds = 100;
CRGB leds[numberOfLeds];
bool goUp = true;

int maxBrightness = 180;
int minBrightness = 40;
int delayTime = 30;

void setup() { 
  FastLED.addLeds<NEOPIXEL, 8>(leds, numberOfLeds);
}



void loop() { 
  static uint8_t hue = 0; // 0 = red
  static uint8_t brightness = 0;
  static uint8_t saturation = 255;

  
  for (int i = 0; i < 50; i++) {
    if (goUp) {
      leds[i] = CHSV(hue, 255, brightness); 
      if (brightness == maxBrightness) {
        goUp = false;  
      }
    }
    else {
      goUp = false;
      leds[i] = CHSV(hue, 255, brightness); 
      if(brightness == minBrightness) {
        goUp = true;
      }
    }
    
   FastLED.show();
  }

   for (int i = 50; i < 100; i++) {
    if (goUp) {
      leds[i] = CHSV(hue+50, 255, brightness); 
      if (brightness == maxBrightness) {
        goUp = false;  
      }
    }
    else {
      goUp = false;
      leds[i] = CHSV(hue+50, 255, brightness); 
      if(brightness == minBrightness) {
        goUp = true;
      }
    }
    
   FastLED.show();
  }

  
  if (goUp) {
     brightness++;  
   }
    else {
     brightness--;
   }
//  delay(delayTime);
}
