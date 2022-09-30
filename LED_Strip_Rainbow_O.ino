#include <FastLED.h>

#define LED_PIN 11
#define NUM_LEDS 300
CRGB leds[NUM_LEDS];

int pinNumber = 11;
int numOfLeds = 300;

// sets the current colour
int colourValueRed = 0;
int colourValueGreen = 0;
int colourValueBlue = 0;

// used to control timing
int startTime = 0;
int elapsedTime = 0;
int intervalTime = 2000;
int delayTime = 0;
int delayValue = 50;

void setup()
{
  // LED strip is declared
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop()
{
  // resets all of the variables
  startTime = millis();
  elapsedTime = 0;
  delayTime = elapsedTime + delayValue;
  // starting colour is red
  colourValueRed = 250;
  colourValueGreen = 0;
  colourValueBlue = 0;

  // makes the LEDs go from red to green
  while (elapsedTime < intervalTime) {
    // delays the main loop, to increase performance
    while (elapsedTime < delayTime) {
      elapsedTime = millis() - startTime;
    }
    delayTime = elapsedTime + delayValue;
    // creates the new colour based on the current time (goes from red to green)
    colourValueRed = 250 - elapsedTime / (intervalTime / 250);
    colourValueGreen = elapsedTime / (intervalTime / 250);
    colourValueBlue = 0;
    // sets all of the LEDs to the new colour
    for (int i = 0; i < numOfLeds; i++) {
      leds[i] = CRGB(colourValueRed, colourValueGreen, colourValueBlue);
    }
    FastLED.show();
  }
  // resets the variables
  startTime = millis();
  elapsedTime = 0;
  delayTime = elapsedTime + delayValue;
  // makes the LEDs go from green to blue
  while (elapsedTime < intervalTime) {
    // delays the main loop, to increase performance
    while (elapsedTime < delayTime) {
      elapsedTime = millis() - startTime;
    }
    delayTime = elapsedTime + delayValue;
    // creates the new colour based on the current time (goes from green to blue)
    colourValueRed = 0;
    colourValueGreen = 250 - elapsedTime / (intervalTime / 250);
    colourValueBlue = elapsedTime / (intervalTime / 250);
    // sets all of the LEDs to the new colour
    for (int i = 0; i < numOfLeds; i++) {
      leds[i] = CRGB(colourValueRed, colourValueGreen, colourValueBlue);
    }
    FastLED.show();
  }
  // resets the variables
  startTime = millis();
  elapsedTime = 0;
  delayTime = elapsedTime + delayValue;
  // makes the LEDs go from blue to red
  while (elapsedTime < intervalTime) {
    // delays the main loop, to increase performance
    while (elapsedTime < delayTime) {
      elapsedTime = millis() - startTime;
    }
    delayTime = elapsedTime + delayValue;
    // creates the new colour based on the current time (goes from blue to red)
    colourValueRed = elapsedTime / (intervalTime / 250);
    colourValueGreen = 0;
    colourValueBlue = 250 - elapsedTime / (intervalTime / 250);
    // sets all of the LEDs to the new colour
    for (int i = 0; i < numOfLeds; i++) {
      leds[i] = CRGB(colourValueRed, colourValueGreen, colourValueBlue);
    }
    FastLED.show();
  }
}
