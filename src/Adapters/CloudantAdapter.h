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
    unsigned long int tokenExpiresIn;
    unsigned long int tokenExpiration;
    unsigned long int currentTime;
    unsigned long int lastPublish;
    SensorSet* sensorSet;
    HTTPClient httpClient;
    bool isTokenExpired();
    void authenticate();
public:
    void connect();
    void publish(SensorSet sensorSet);
    bool shouldPublish();
};

#endif