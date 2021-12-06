#ifndef WS2812CONTROLLER_H
#define WS2812CONTROLLER_H

#include <Adafruit_NeoPixel.h>


class WS2812Controller {
    public:
        void setup(int LedPin);
        void setRGB(int red, int green, int blue);
        void pulse();
    private:
        Adafruit_NeoPixel pixels;
        int pins[3];
        int currentCollor[3] = {255, 255, 255};
};

#endif