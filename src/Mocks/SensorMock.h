#ifndef SENSOR_MOCK_H
#define SENSOR_MOCK_H

#include <Sensor.h>

class SensorMock : public Sensor {
    public:
        SensorMock();
        virtual void setup();
        virtual void update();
};

#endif