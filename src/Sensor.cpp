#include "Sensor.h"

Sensor::Sensor(const char* sensorKey, const char* sensorName, const char* sensorUnit) {
    name = sensorName;
    unit = sensorUnit;
    key = sensorKey;
    cicleTime = millis()/1000ULL;
}

const char* Sensor::getName() {return name;}
void Sensor::setName(const char* n) {name = n;}

const char* Sensor::getUnit() {return unit;}
void Sensor::setUnit(const char* u) {unit = u;}

const char* Sensor::getKey() {return key;}
void Sensor::setKey(const char* k) {key = k;}

float Sensor::getValue() {return value;}
void Sensor::setValue(float v) {value = v;}

float Sensor::getIntegrationTime() {return integrationTime;}
void Sensor::setIntegrationTime(float i) {integrationTime = i;}

bool Sensor::isMeasuring() {
    if (integrationTime == 0) {
        return false;
    }
    if ((millis()/1000ULL - cicleTime) >= integrationTime) {
        cicleTime = millis()/1000ULL;
        return false;
    }
    return  true;
}

void Sensor::dump() {
    Serial.print("Sensor: ");
    Serial.print(name);
    Serial.print("\tUnit: ");
    Serial.print(unit);
    Serial.print("\tValue: ");
    Serial.println(value);
}

DynamicJsonDocument Sensor::toJson() {
    DynamicJsonDocument json(jsonSize);
    json["name"] = name;
    json["unit"] = unit;
    json["value"] = value;
    return json;
}