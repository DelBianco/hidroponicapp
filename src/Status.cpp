#include "Status.h"

#define MEASURING 0
#define PUBLISHING 1
#define CONNECTING 2
#define CALIBRATING 3
#define NEED_CALIBRATION 4
#define UNABLE_TO_CONNECT 5
#define UNABLE_TO_PUBLISH 6
#define GENERIC_ERROR 7


void Status::Setup() {
    led.setup(21);
}

void Status::Measuring() {
    currentStatus = MEASURING;
}

void Status::Publishing() {
   currentStatus = PUBLISHING;
}

void Status::Connecting() {

}

void Status::Calibrating() {

}

void Status::NeedCalibration() {

}

void Status::UnableToConnect() {

}

void Status::UnableToPublish() {

}

void Status::GenericError() {

}

void Status::handle() {
    switch (currentStatus)
    {
    case MEASURING:
        led.setRGB(255,210,0);
        Serial.println("[Status] Measuring");
        break;
    case PUBLISHING:
        led.setRGB(210,0,210);
        Serial.println("[Status] Publishing");
        break;
    case CONNECTING:
        /* code */
        break;
    case CALIBRATING:
        /* code */
        break;
    case NEED_CALIBRATION:
        /* code */
        break;
    case UNABLE_TO_CONNECT:
        /* code */
        break;
    case UNABLE_TO_PUBLISH:
        /* code */
        break;
    case GENERIC_ERROR:
        led.setRGB(210,0,0);
        Serial.println("[Status] Generic Error");
        break;
    default:
        led.setRGB(210,0,0);
        Serial.println("[Status] Status Unknown");
        break;
    }
    
    led.pulse();
}
