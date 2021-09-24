#ifndef GAS_H
#define GAS_H

#include <Sensor.h>
#include <MQUnifiedsensor.h>
#include <env.h>

class Gas : public Sensor {
    public:
        MQUnifiedsensor MQ135;
        Gas();
        virtual void setup();
        virtual void update();
};

#endif