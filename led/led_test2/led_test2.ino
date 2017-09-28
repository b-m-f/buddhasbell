#include "FastLED.h"

const int numberOfLeds = 32;
CRGB leds[numberOfLeds];
bool goUp = true;
bool goUp2 = false;
const int firstStrip = 13;
//19 long
const int secondStrip = 32;

const int maxBrightness = 180;
const int minBrightness = 50;
const int delayTime = 30;

void setup() {
  FastLED.addLeds<NEOPIXEL, 2>(leds, numberOfLeds);
}

void loop() {
  static uint8_t hue = 0; // 0 = red
  static uint8_t brightness1 = 0;
  static uint8_t brightness2 = 255;
  for (int i = 0; i < firstStrip; i++) {
    if (goUp) {
      leds[i] = CHSV(hue, 255, brightness1++);
      if (brightness1 == maxBrightness) {
        goUp = false;
      }
    }
    else {
      goUp = false;
      leds[i] = CHSV(hue, 255, brightness1--);
      if (brightness1 == minBrightness) {
        goUp = true;
      }
    }
  }
  
  for (int i = firstStrip; i < secondStrip; i++) {
    if (goUp2) {
      leds[i] = CHSV(hue, 255, brightness2++);
      if (brightness2 == maxBrightness) {
        goUp2 = false;
      }
    }
    else {
      goUp2 = false;
      leds[i] = CHSV(hue, 255, brightness2--);
      if (brightness2 == minBrightness) {
        goUp2 = true;
      }
    }
    FastLED.show();
  }
  delay(delayTime);
}
