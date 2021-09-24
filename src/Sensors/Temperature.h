#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <Sensor.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <env.h>

class Temperature : public Sensor {
    public:
        OneWire ourWire;
        DallasTemperature TemperatureSensor;
        Temperature();
        virtual void setup();
        virtual void update();
};

#endif