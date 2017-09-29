#include "FastLED.h"

const int ledNumber = 290;
CRGB leds[ledNumber];

bool goUp = true;

const int maxBrightness = 180;
const int minBrightness = 50;

const int delayTime = 30;

void setup() {
  FastLED.addLeds<NEOPIXEL, 2>(leds, ledNumber);
}
void loop() {
  static uint8_t hue = 0;
  static uint8_t brightness = 0;
  delay(10);
  if (goUp) {
    FastLED.showColor(CHSV(hue, 255, brightness++));
    if (brightness == maxBrightness) {
      goUp = false;
    }
  }
  else {
    goUp = false;
    FastLED.showColor(CHSV(hue, 255, brightness--));
    if (brightness == minBrightness) {
      goUp = true;
    }
  }
  delay(delayTime);
}
