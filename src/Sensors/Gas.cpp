#include "Gas.h"

Gas::Gas(): Sensor("environment-gas", "Gas CO2", "PPM") {
    MQ135 = MQUnifiedsensor("ESP 32 Devkit V1", 3.3, 12, ENV_MQ135_PIN, "MQ-135");
}

void Gas::setup() {
    // PPM =  a*ratio^b
    MQ135.setRegressionMethod(1);

    // Configurate the equation values to get NH4 concentration
    MQ135.setA(ENV_CALIBRATION_AMPLITUDE);
    MQ135.setB(ENV_CALIBRATION_EXPO);
    MQ135.init();

    Serial.println("Calibrating Gas Sensor please wait.");
    float calcR0 = 0;
    for(int i = 1; i<=10; i ++) {
        MQ135.update();
        calcR0 += MQ135.calibrate(ENV_RATIO_MQ135_CLEAN_AIR);
    }
    MQ135.setR0(calcR0/10);
    if(isinf(calcR0)) {
        Serial.println("Warning: Conection issue founded, R0 is infite (Open circuit detected) please check your wiring and supply"); 
    }

    if(calcR0 == 0) {
        Serial.println("Warning: Conection issue founded, R0 is zero (Analog pin with short circuit to ground) please check your wiring and supply");
    }
    Serial.println("Done Calibrating");
}

void Gas::update() {
    MQ135.update();
    value = MQ135.readSensor();
}
