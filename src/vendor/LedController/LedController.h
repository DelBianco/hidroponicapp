#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H


class LedController {
    public:
        void setup(int RedPin, int GreenPin, int BluePin);
        void setRGB(int red, int green, int blue);
        void blink();
        void pulse();
        void setFromPWM(int channel, int value);
        int applyFunction(float value);
    private:
        int pins[3];
        int currentCollor[3] = {255, 255, 255};
};

#endif