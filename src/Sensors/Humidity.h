#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <Sensor.h>
#include <DHTesp.h>
#include <env.h>

class Humidity : public Sensor {
    public:
        DHTesp dht;
        Humidity();
        virtual void setup();
        virtual void update();
};

#endif