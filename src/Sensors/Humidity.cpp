#include "Humidity.h"

Humidity::Humidity(): Sensor("humidity", "Humidade do Ar", "%") {}

void Humidity::setup() {
    dht.setup(ENV_DHTPIN, DHTesp::DHT11);
}

void Humidity::update() {
    if(!isMeasuring()) {
        value = dht.getHumidity();
    }
}
