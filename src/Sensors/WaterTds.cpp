#include "WaterTds.h"

WaterTds::WaterTds(): Sensor("water-tds", "Solidos totais na água", "ppm") {
    tds = GravityTDS(ENV_TDSPIN, 3.3, 4096.0);
}

void WaterTds::setTemperatureSensor(Temperature *sensor) {
    temperatureSensor = sensor;
}

void WaterTds::setup() {
    tds.begin();
}

void WaterTds::update() {
    tds.setTemperature(temperatureSensor->getValue());
    tds.update();
    value = tds.getTdsValue();
}
