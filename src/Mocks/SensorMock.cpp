#include "SensorMock.h"

SensorMock::SensorMock(): Sensor("Sensor Mock", "ua") {}

void SensorMock::setup() {
    Serial.println("Setting Up Mock");
}

void SensorMock::update() {
    value = random(4096)/4096.0;
}