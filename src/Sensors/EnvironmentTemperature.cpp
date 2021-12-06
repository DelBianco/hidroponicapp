#include "EnvironmentTemperature.h"

EnvironmentTemperature::EnvironmentTemperature(): Sensor("environment-temperature", "Temperatura Ambiente", "ºC") {}

void EnvironmentTemperature::setup() {
    dht.setup(ENV_DHTPIN, DHTesp::DHT11);
}

void EnvironmentTemperature::update() {
    value = dht.getTemperature();
}