#ifndef CLOUDANT_ADAPTER_H
#define CLOUDANT_ADAPTER_H

#include <PublishAdapter.h>
#include <ArduinoJson.h>
#include <Sets/SensorSet.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <env.h>

class CloudantAdapter : public PublishAdapter {
private:
    const char* authToken;
    SensorSet* sensorSet;
    HTTPClient httpClient;
public:
    void connect();
    void publish(SensorSet sensorSet);
};

#endif