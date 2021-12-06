#include "LedController.h"
#include <math.h>
#include "Arduino.h"

const int freq = 5000;
const int resolution = 8;

void LedController::setup(int RedPin, int GreenPin, int BluePin) {
  
  pins[0] = RedPin;
  pins[1] = GreenPin;
  pins[2] =  BluePin;

  pinMode(4, OUTPUT);
  digitalWrite(4,HIGH);
  for (int i = 0; i <= 2; i++) {
    ledcSetup(i, freq, resolution);
    ledcAttachPin(pins[i], i);
    ledcWrite(i, 255);
  }
}

void LedController::setRGB(int red, int green, int blue) {
  currentCollor[0] = red;
  currentCollor[1] = green;
  currentCollor[2] = blue;
}

void LedController::blink() {
  for (int i = 0; i <= 2; i++) {
    setFromPWM(i, currentCollor[i]);
  }
  delay(500);
  for (int i = 0; i <= 2; i++) {
    setFromPWM(i, 0);
  }
   delay(500);
}

void LedController::pulse() {
   // increase
  for(int dutyCycle = 80; dutyCycle <= 255; dutyCycle++) {
    for (int i = 0; i <= 2; i++) {
      int color = (int) currentCollor[i] * dutyCycle/255;
      setFromPWM(i, applyFunction(color));
    }
    delay(10);
  }

  // decrease
  for(int dutyCycle = 255; dutyCycle >= 80; dutyCycle--) {
    for (int i = 0; i <= 2; i++) {
      int color = (int) currentCollor[i] * dutyCycle/255;
      setFromPWM(i, applyFunction(color));
    }
    delay(10);
  }  
}

void LedController::setFromPWM(int channel, int value) {
  ledcWrite(channel, 255 - value);
}

int LedController::applyFunction(float value) {
  return (int) (255 * pow(value, 4) / pow(255, 4)) ;
}