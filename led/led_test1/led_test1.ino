#include "FastLED.h"
CRGB leds[150];
void setup() { FastLED.addLeds<NEOPIXEL, 2>(leds, 150); }
void loop() { 
  static uint8_t hue = 0;
  FastLED.showColor(CHSV(hue++, 255, 255)); 
  delay(10);
}
