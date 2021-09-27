#include "EnvironmentTemperature.h"

EnvironmentTemperature::EnvironmentTemperature(): Sensor("environment-temperature", "Temperatura Ambiente", "ºC") {}

void EnvironmentTemperature::setup() {
    dht.setup(ENV_DHTPIN, DHTesp::DHT11);
}

void EnvironmentTemperature::update() {
    delay(dht.getMinimumSamplingPeriod());
    value = dht.getTemperature();
}