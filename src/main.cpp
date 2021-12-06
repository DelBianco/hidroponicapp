#include <ArduinoJson.h>
#include <PublishAdapter.h>
#include <Builders/SensorSetBuilder.h>
#include <Sets/SensorSet.h>
#include <Adapters/CloudantAdapter.h>
#include <Status.h>
#include <vendor/LedController/WS2812Controller.h>

TaskHandle_t MeasureTask;
TaskHandle_t StatusTask;

SensorSet sensorSet;
CloudantAdapter publisher;
Status status;

void Measure( void * pvParameters ){
  for (;;) {
    status.Measuring();
    sensorSet.update();
    if(publisher.shouldPublish()) {
      status.Publishing();
      publisher.publish(sensorSet);
      delay(3000);
    }
  } 
}

void StatusHandler( void * pvParameters ){
  for (;;) {
    status.handle();
  }
}


void setup() {
  Serial.begin(115200);
  while (!Serial) continue;
  status.Setup();
  publisher.connect();
  sensorSet = SensorSetBuilder::build();
  sensorSet.setup();
  
  xTaskCreatePinnedToCore(Measure, "MeasureTask", 10000, NULL, 1, &MeasureTask, 0);
  delay(500);
  xTaskCreatePinnedToCore(StatusHandler,  "StatusTask",  10000, NULL, 1, &StatusTask,  1);
  delay(500);
}

void loop() {
  
}