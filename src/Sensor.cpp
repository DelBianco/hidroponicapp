#include "Sensor.h"

Sensor::Sensor(const char* sensorName, const char* sensorUnit) {
    name = sensorName;
    unit = sensorUnit;
}

const char* Sensor::getName() {return name;}
void Sensor::setName(const char* n) {name = n;}

const char* Sensor::getUnit() {return unit;}
void Sensor::setUnit(const char* u) {unit = u;}

float Sensor::getValue() {return value;}
void Sensor::setValue(float v) {value = v;}

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