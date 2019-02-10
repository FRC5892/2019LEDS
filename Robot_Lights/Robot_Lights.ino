#include <FastLED.h>
 
//#define DATA_PIN 6 not using this because each strip has it's own defined in fastled.addleds
#define NUM_LEDS 64
 
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<NEOPIXEL,1>(leds, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL,1>(leds, NUM_LEDS);  
}

void loop() {
  auton();  
}

void auton() {
  leds[0, 64] = CRGB::Blue;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}