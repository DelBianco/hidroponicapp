#ifndef WATER_TDS_H
#define WATER_TDS_H

#include <Sensor.h>
#include <env.h>

class WaterTds : public Sensor {
    public:
        WaterTds();
        virtual void setup();
        virtual void update();
};

#endif