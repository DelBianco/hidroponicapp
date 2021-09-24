#include "Temperature.h"

Temperature::Temperature(): Sensor("Temperature", "ºC") {
    ourWire = OneWire(ENV_DS18B20);
    TemperatureSensor = DallasTemperature(&ourWire);
}

void Temperature::setup() {
    TemperatureSensor.begin();
}

void Temperature::update() {
    TemperatureSensor.requestTemperatures();
    value = TemperatureSensor.getTempCByIndex(0);
}
