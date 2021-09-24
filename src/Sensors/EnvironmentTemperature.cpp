#include "EnvironmentTemperature.h"

EnvironmentTemperature::EnvironmentTemperature(): Sensor("Environment Temperature", "ºC") {}

void EnvironmentTemperature::setup() {
    dht.setup(ENV_DHTPIN, DHTesp::DHT11);
}

void EnvironmentTemperature::update() {
    delay(dht.getMinimumSamplingPeriod());
    value = dht.getTemperature();
}