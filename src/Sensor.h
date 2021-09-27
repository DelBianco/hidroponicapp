#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <ArduinoJson.h>

class Sensor {
  public:
    const char* name;
    const char* unit;
    const char* key;
    float value = 0.0;
    size_t jsonSize = 512;

    Sensor(const char* sensorKey, const char* sensorName, const char* sensorUnit);
    
    virtual void setup() = 0;
    virtual void update() = 0;

    DynamicJsonDocument toJson();
    void dump();
    
    const char* getName();
    void setName(const char* n);

    const char* getUnit();
    void setUnit(const char* u);
    
    const char* getKey();
    void setKey(const char* k);
    
    float getValue();
    void setValue(float v);
};

#endif