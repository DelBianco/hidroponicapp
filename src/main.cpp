#include <ArduinoJson.h>
#include <PublishAdapter.h>
#include <Builders/SensorSetBuilder.h>
#include <Sets/SensorSet.h>
#include <Adapters/CloudantAdapter.h>


SensorSet sensorSet;
CloudantAdapter publisher;

void setup() {
  Serial.begin(115200);
  while (!Serial) continue;
  publisher.connect();
  sensorSet = SensorSetBuilder::build();
  sensorSet.setup();
}

void loop() {
  sensorSet.update();
  publisher.publish(sensorSet);
  Serial.println("----");
  delay(8000);
}
