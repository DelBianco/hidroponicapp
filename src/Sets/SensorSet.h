#ifndef SENSOR_SET_H
#define SENSOR_SET_H

#include <Sensor.h>
#include <list>
#include <ArduinoJson.h>

class SensorSet {
    private:
        std::list<Sensor*> sensors;
    public:
        size_t jsonSize;
        void add(Sensor* sensor);
        void setup();
        void update();
        void dump();
        DynamicJsonDocument toJson();
};

#endif
