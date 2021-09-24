#include "Humidity.h"

Humidity::Humidity(): Sensor("Humidity", "%") {}

void Humidity::setup() {
    dht.setup(ENV_DHTPIN, DHTesp::DHT11);
}

void Humidity::update() {
    delay(dht.getMinimumSamplingPeriod());
    value = dht.getHumidity();
}
