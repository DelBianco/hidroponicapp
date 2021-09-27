#ifndef WATER_PH_H
#define WATER_PH_H

#include <Sensor.h>
#include <env.h>

class WaterPh : public Sensor {
    public:
        WaterPh();
        virtual void setup();
        virtual void update();
};

#endif