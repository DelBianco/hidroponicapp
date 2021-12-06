#include "WS2812Controller.h"

void WS2812Controller::setup(int LedPin) {
  pixels = Adafruit_NeoPixel(1, 21, NEO_GRB + NEO_KHZ800);
  pixels.begin();
}

void WS2812Controller::setRGB(int red, int green, int blue) {
  currentCollor[0] = red;
  currentCollor[1] = green;
  currentCollor[2] = blue;
  pixels.setPixelColor(0, pixels.Color(currentCollor[0],currentCollor[1],currentCollor[2]));
  pixels.show();
}

void WS2812Controller::pulse() {
  for(int brightness = 255; brightness >= 0; brightness--) {
    pixels.setPixelColor(
      0, 
      (brightness*currentCollor[0]/255) , 
      (brightness*currentCollor[1]/255), 
      (brightness*currentCollor[2]/255)
    );
    pixels.show();
    delay(10);
  }

  for(int brightness = 0; brightness <= 255; brightness++) {
    pixels.setPixelColor(
      0, 
      (brightness*currentCollor[0]/255), 
      (brightness*currentCollor[1]/255), 
      (brightness*currentCollor[2]/255)
    );
    pixels.show();
    delay(10);
  }
}
