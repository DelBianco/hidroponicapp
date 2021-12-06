#include "SensorSetBuilder.h"
#include <Sensors/Temperature.h>
#include <Sensors/Gas.h>
#include <Sensors/Humidity.h>
#include <Sensors/EnvironmentTemperature.h>
#include <Sensors/WaterPh.h>
#include <Sensors/WaterTds.h>
#include <Mocks/SensorMock.h>


SensorSet SensorSetBuilder::build() {

    Temperature * WaterTemperatureSensor = new Temperature();
    Gas *  CO2ConcentrationSensor = new Gas();
    Humidity * HumiditySensor = new Humidity();
    EnvironmentTemperature * EnvironmentTemperatureSensor = new EnvironmentTemperature();
    WaterPh * WaterPhSensor = new WaterPh();
    WaterTds * WaterTdsSensor = new WaterTds();
    WaterTdsSensor->setTemperatureSensor(WaterTemperatureSensor);

    SensorSet sensorSet;

    sensorSet.add(WaterPhSensor);
    sensorSet.add(WaterTdsSensor);
    sensorSet.add(WaterTemperatureSensor);
    sensorSet.add(CO2ConcentrationSensor);
    sensorSet.add(HumiditySensor);
    sensorSet.add(EnvironmentTemperatureSensor);

    return sensorSet;
}

SensorSet SensorSetBuilder::mock() {

    SensorMock * WaterTemperatureSensor = new SensorMock();
    SensorMock * CO2ConcentrationSensor = new SensorMock();
    SensorMock * HumiditySensor = new SensorMock();
    SensorMock * EnvironmentTemperatureSensor = new SensorMock();
    
    SensorSet sensorSet;

    sensorSet.add(WaterTemperatureSensor);
    sensorSet.add(CO2ConcentrationSensor);
    sensorSet.add(HumiditySensor);
    sensorSet.add(EnvironmentTemperatureSensor);

    return sensorSet;
}