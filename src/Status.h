#ifndef STATUS_H
#define STATUS_H

#include <Arduino.h>
#include "vendor/LedController/WS2812Controller.h"

class Status {
  public:
    int currentStatus;
    WS2812Controller led;

    void Setup();
    void Measuring();
    void Publishing();
    void Connecting();
    void Calibrating();
    void NeedCalibration();
    void UnableToConnect();
    void UnableToPublish();
    void GenericError();

    void handle();
};

#endif