#include "WaterTds.h"

WaterTds::WaterTds(): Sensor("water-tds", "Solidos totais na água", "ppm") {}

void WaterTds::setup() {}

void WaterTds::update() {
    value = 30 + 10*cos(millis()/100000) + (random(1000) / 1000);
}
