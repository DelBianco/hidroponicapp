#ifndef WATER_TDS_H
#define WATER_TDS_H

#include <Sensor.h>
#include <env.h>
#include <Sensors/Temperature.h>
#include "vendor/GravityTDS.h"

class WaterTds : public Sensor {
    public:
        WaterTds();
        GravityTDS tds;
        virtual void setup();
        virtual void update();
        virtual void setTemperatureSensor(Temperature *sensor);
        Temperature *temperatureSensor;
};

#endif