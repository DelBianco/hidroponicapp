#ifndef REDIS_ADAPTER_H
#define REDIS_ADAPTER_H

#include <PublishAdapter.h>
#include <Redis.h>
#include <ArduinoJson.h>
#include <Sets/SensorSet.h>
#include <WiFiClient.h>
#include <WiFi.h>
#include <env.h>

class RedisAdapter : public PublishAdapter {
private:
    SensorSet* sensorSet;
    WiFiClient redisConn;
    Redis *gRedis = nullptr;
    StaticJsonDocument<2048> doc;
    unsigned long lastPost = 0;
public:
    void connect();
    void publish(SensorSet sensorSet);
};

#endif