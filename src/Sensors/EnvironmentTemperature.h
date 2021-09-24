#ifndef ENVIRONMENTTEMPERATURE_H
#define ENVIRONMENTTEMPERATURE_H

#include <Sensor.h>
#include <DHTesp.h>
#include <env.h>

class EnvironmentTemperature : public Sensor {
    public:
        DHTesp dht;
        EnvironmentTemperature();
        virtual void setup();
        virtual void update();
};

#endif