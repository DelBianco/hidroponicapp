#ifndef SENSOR_SET_BUILDER_H
#define SENSOR_SET_BUILDER_H

#include <Sensor.h>
#include <Sets/SensorSet.h>

class SensorSetBuilder {
public:
    static SensorSet build();
    static SensorSet mock();
};

#endif