#include "CloudantAdapter.h"

StaticJsonDocument<2048> authResponse;

String CLOUDANT_SERVER = (String) ENV_CLOUDANT_SERVER;
String CLOUDANT_AUTH_ENDPOINT = (String) ENV_CLOUDANT_AUTH_ENDPOINT;
String CLOUDANT_API_KEY = (String) ENV_CLOUDANT_API_KEY;
String CLOUDANT_AUTH_GRANT_TYPE = (String) ENV_CLOUDANT_AUTH_GRANT_TYPE;
String CLOUDANT_DATABASE = (String) ENV_CLOUDANT_DATABASE;
unsigned long int timeOffset = 0;
unsigned long int now;

void CloudantAdapter::connect()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ENV_WIFI_SSID, ENV_WIFI_PASSWORD);
    
    Serial.println("[Cloudant] Connecting to the WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(250);
    }
    Serial.println("[Cloudant] WiFi Ok!");
    authenticate();
    Serial.println("[Cloudant] Publishing");
}

void CloudantAdapter::publish(SensorSet sensorSet) 
{
    if (isTokenExpired()) {
        Serial.println("[Cloudant] Token expired");
        authenticate();
        if(authToken == NULL) {
            Serial.println("[Cloudant] Unable to authenticate");
            return;
        }
    }
    now = (currentTime - timeOffset + millis());

    String jsonPayload;
    DynamicJsonDocument payload(sensorSet.jsonSize + 128);
    payload = sensorSet.toJson();
    payload["_id"] = (String)now;
    payload["timestamp"] = now;
    payload["wifi"]["RSSI"] = WiFi.RSSI();
    payload["wifi"]["SSID"] = WiFi.SSID();
    payload["esp32"]["HeapSize"] = ESP.getHeapSize();
    payload["esp32"]["FreeHeap"] = ESP.getFreeHeap();
    payload["esp32"]["MinFreeHeap"] = ESP.getMinFreeHeap();
    payload["esp32"]["MaxAllocHeap"] = ESP.getMaxAllocHeap();
    serializeJson(payload, jsonPayload);
    httpClient.begin(CLOUDANT_SERVER + CLOUDANT_DATABASE);
    httpClient.addHeader("Content-Type", "application/json");
    httpClient.addHeader("Authorization", "Bearer " + (String)authToken);
    int code = httpClient.POST(jsonPayload);
    if (code != 201) {
        Serial.print("[Cloudant] Unable to publish data: ");
        Serial.println(httpClient.getString());
    }
    httpClient.end();
    lastPublish = millis();
}

bool CloudantAdapter::isTokenExpired() {
    return (((millis()/1000ULL) - timeOffset) >= tokenExpiresIn);
}

void CloudantAdapter::authenticate() {
    Serial.println("[Cloudant] Authenticating");
    httpClient.begin(CLOUDANT_AUTH_ENDPOINT);
    httpClient.addHeader("Content-Type", "application/x-www-form-urlencoded");
    httpClient.addHeader("Accept", "application/json");
    if (httpClient.POST("grant_type=" + CLOUDANT_AUTH_GRANT_TYPE + "&apikey=" + CLOUDANT_API_KEY) != 200) {
        Serial.print("[Cloudant] Unable to authenticate : ");
        Serial.println(httpClient.getString());
        authToken = NULL;
        return ;
    }
    deserializeJson(authResponse, httpClient.getString());
    authToken = authResponse["access_token"];
    tokenExpiresIn = authResponse["expires_in"];
    tokenExpiration = authResponse["expiration"];
    currentTime = tokenExpiration - tokenExpiresIn;
    timeOffset = millis()/1000ULL;
    httpClient.end();
}

bool CloudantAdapter::shouldPublish() { 
    return !lastPublish || (millis() - lastPublish) > (ENV_POST_FREQUENCY * 1000);
}
