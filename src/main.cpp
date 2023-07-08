#include <Arduino.h>
#include "esp_task_wdt.h"
#include <ESP_FlexyStepper.h>

//Pinout

#define EN    23
#define STEP1 22
#define DIR1  21
#define STEP2 32
#define DIR2  33
#define SPEED 350 

ESP_FlexyStepper stepper1;
ESP_FlexyStepper stepper2;

int gearRatio = 15.3;

void setup() {
esp_task_wdt_init(30, false);
Serial.begin(115200);

pinMode(EN, OUTPUT);
pinMode(STEP1, OUTPUT);
pinMode(DIR1, OUTPUT);
pinMode(STEP2, OUTPUT);
pinMode(DIR2, OUTPUT);

stepper1.connectToPins(STEP1, DIR1);
stepper2.connectToPins(STEP2, DIR2);

//digitalWrite(EN, LOW);
//digitalWrite(DIR1, HIGH);
//digitalWrite(DIR2, HIGH);

stepper1.setStepsPerRevolution(200 * gearRatio);
stepper2.setStepsPerRevolution(200 * gearRatio);

stepper1.setSpeedInRevolutionsPerSecond(1);
stepper2.setSpeedInRevolutionsPerSecond(1 / 60);
//stepper1.setSpeedInStepsPerSecond(200 * gearRatio);
stepper1.setAccelerationInStepsPerSecondPerSecond(1000);
//stepper2.setSpeedInStepsPerSecond((200 * gearRatio) / 60);
stepper2.setAccelerationInStepsPerSecondPerSecond(1000);

stepper1.startAsService();
stepper2.startAsService();

}



void loop() {  

stepper1.startJogging(-1);
stepper2.startJogging(1);





//    digitalWrite(STEP1, HIGH);
//    digitalWrite(STEP2, HIGH);
//    delayMicroseconds(SPEED);
//    digitalWrite(STEP1, LOW);
//    digitalWrite(STEP2, LOW);
//    delayMicroseconds(SPEED);
}