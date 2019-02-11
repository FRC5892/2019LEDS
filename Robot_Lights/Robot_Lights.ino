#include <FastLED.h>
 
//#define DATA_PIN 6 not using this because each strip has it's own defined in fastled.addleds
#define NUM_LEDS_Elevator 64
int i; 
CRGB ledsElevator[NUM_LEDS_Elevator];
void setup() {
  //LED Code
  FastLED.addLeds<NEOPIXEL,1>(ledsElevator, NUM_LEDS_Elevator);
  FastLED.addLeds<NEOPIXEL,2>(ledsElevator, NUM_LEDS_Elevator);
  //Serial Code
  Serial.begin(9600);
    
}

void loop() {
  int i = Serial.read();  
}

void switchPattern() {
  switch (i) {
    case 1: //switches when i is 1
      auton(); //calls auton function
      break;
    case 2: //switches when i is 2
      teleop(); //calls teleop funcion
      break;
    default:
      noInstructions();
      break;
  }
}

void auton() {
  ledsElevator[0, 64] = CRGB::Green;
  FastLED.show();
  delay(500);
  ledsElevator[0, 64] = CRGB::Black;
  FastLED.show();
  delay(500);
}

void teleop() {
  ledsElevator[0, 64] = CRGB::Orange;
  FastLED.show();
  delay(500);
  ledsElevator[0, 64] = CRGB::Black;
  FastLED.show();
  delay(500);
}

void noInstructions() {
  ledsElevator[0, 64] = CRGB::Blue;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  ledsElevator[0, 64] = CRGB::Black;
  FastLED.show();
  delay(500);
}
