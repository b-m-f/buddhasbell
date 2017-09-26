#include "FastLED.h"

const int numberOfLeds = 256;
CRGB leds[numberOfLeds];
byte count = 0;
int delayTime = 1000;


void setup() { 
  FastLED.addLeds<NEOPIXEL, 8>(leds, numberOfLeds); 
  Serial.begin(9600);
  }
void loop() { 
//  static uint8_t hue = 0;
//
//  for (byte off = 8; off >= 0; off--) {
//    int offset = count - off + 4;
//    if (offset < 0) {
//      offset += 255;
//    }
//    Serial.print(offset);
//    leds[offset] = CHSV(hue, 255, 30);
//    Serial.print("\n");
//    
//    FastLED.show(); 
//  }
//  leds[count-4] = CHSV(hue, 255, 0);
//  FastLED.show();
//  delay(delayTime);
//  count++;
//  Serial.print(count);
}
