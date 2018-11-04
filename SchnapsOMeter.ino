int mq3_analogPin = 0;

#include <Adafruit_NeoPixel.h>

#define PIN 9
int theScore;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  int theScoreHelp = constrain(analogRead(mq3_analogPin), 600,1023);
  theScore=map(theScoreHelp,600,1023,0,59);
  colorWipe(strip.Color(0, 0, 55), 5); // Blue
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<theScore; i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
  for(uint16_t i=theScore; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, 0);
      strip.show();
  }  
}


