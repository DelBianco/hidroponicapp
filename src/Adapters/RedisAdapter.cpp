#include "RedisAdapter.h"

void RedisAdapter::connect()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ENV_WIFI_SSID, ENV_WIFI_PASSWORD);
    
    Serial.println("Connecting to the WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(250);
    }

    Serial.print("Connected to WiFi: ");
    Serial.println(WiFi.localIP());
    
    if (!redisConn.connect(ENV_REDIS_ADDR, ENV_REDIS_PORT))
    {
        Serial.println("Failed to connect to the Redis server!");
        return;
    }

    gRedis = new Redis(redisConn);
    auto connRet = gRedis->authenticate(ENV_REDIS_PASSWORD);
    if (connRet == RedisSuccess) {
        Serial.println("Connected to the Redis server at " + (String)ENV_REDIS_ADDR );
    } else {
        Serial.println("Failed to authenticate to the Redis server! Errno: " + (String)connRet );
        return;
    }
}

void RedisAdapter::publish(SensorSet sensorSet) 
{
    auto startTime = millis();
    if (!lastPost || startTime - lastPost > ENV_POST_FREQUENCY * 1000)
    {
        doc["wifi-rssi"] = WiFi.RSSI();
        doc["uptime-ms"] = startTime;
        String jsonStr;
        serializeJson(doc, jsonStr);
        Serial.println("Sending JSON payload: " + jsonStr);

        auto listeners = gRedis->publish("arduino-redis:jsonpub", jsonStr.c_str());
        Serial.println("Published to " + (String)listeners + " listeners");

        doc.clear();
        lastPost = millis();
    }
}
