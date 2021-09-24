#ifndef PUBLISH_ADAPTER_H
#define PUBLISH_ADAPTER_H

#include <Sets/SensorSet.h>

class PublishAdapter {
private:
    SensorSet* sensorSet;
public:
    virtual void connect() = 0;
    virtual void publish(SensorSet sensorSet) = 0;
};

#endif