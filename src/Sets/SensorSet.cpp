#include "SensorSet.h"

void SensorSet::add(Sensor* sensor) {
    sensors.push_back(sensor);
    jsonSize += sensor->jsonSize;
}

void SensorSet::dump() {
    for (std::list<Sensor*>::iterator it=sensors.begin(); it != sensors.end(); ++it) {
        (*it)->dump();
    }
}

void SensorSet::setup() {
    for (std::list<Sensor*>::iterator it = sensors.begin(); it != sensors.end(); ++it) {
        (*it)->setup();
    }
}

void SensorSet::update() {
    for (std::list<Sensor*>::iterator it=sensors.begin(); it != sensors.end(); ++it) {
        (*it)->update();
    }
}

DynamicJsonDocument SensorSet::toJson() {
    DynamicJsonDocument json(jsonSize);
    for (std::list<Sensor*>::iterator it=sensors.begin(); it != sensors.end(); ++it) {
        json[(*it)->getKey()] = (*it)->toJson();
    }
    return json;
}