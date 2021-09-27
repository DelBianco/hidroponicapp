#include "WaterPh.h"

WaterPh::WaterPh(): Sensor("water-ph", "Ph da Água", "ua") {}

void WaterPh::setup() {}

void WaterPh::update() {
    value = 7 + 2*sin(millis()/100000) + (random(1000) / 1000);
}
