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

float gearRatio = 15.3;
int schneke = 48;
float microsteps = 800;
float correction1 = 0.406;
float correction2 = 1.4942;


//PWM
const int channel1 = 1;
const int channel2 = 2;

const int freq1 = (microsteps * gearRatio) / 7;
const int freq2 = (microsteps * gearRatio) / 75;

const int resolution = 8;


void setup() {

esp_task_wdt_init(30, false);
Serial.begin(115200);

pinMode(EN, OUTPUT);
pinMode(STEP1, OUTPUT);
pinMode(DIR1, OUTPUT);
pinMode(STEP2, OUTPUT);
pinMode(DIR2, OUTPUT);

digitalWrite(EN, LOW);
digitalWrite(DIR1, LOW);
digitalWrite(DIR2, LOW);

//stepper1.connectToPins(STEP1, DIR1);
//stepper2.connectToPins(STEP2, DIR2); //red
//
////digitalWrite(EN, LOW);
////digitalWrite(DIR1, HIGH);
////digitalWrite(DIR2, HIGH);
//
//float value1 = ((1) * gearRatio / correction1);
//float value2 = ((1) * gearRatio / correction2);
//
//stepper1.setStepsPerRevolution(microsteps);
//stepper2.setStepsPerRevolution(microsteps); //red
//
//stepper1.setSpeedInRevolutionsPerSecond(value1 / 5.0);
//stepper2.setSpeedInRevolutionsPerSecond(value2 / 75.0); //red
//
////stepper2.setSpeedInStepsPerSecond(192);
//
//stepper1.setAccelerationInStepsPerSecondPerSecond(value1  * 10 * microsteps);
//stepper2.setAccelerationInStepsPerSecondPerSecond(value2 * 10 * microsteps);
//
//
//
////stepper1.startAsService();
////stepper2.startAsService();

//PWM

ledcSetup(channel1, freq1, resolution);
ledcSetup(channel2, freq2, resolution);

ledcAttachPin(STEP1, channel1);
ledcAttachPin(STEP2, channel2);

ledcWrite(channel1, 127);
ledcWrite(channel2, 127);

}



void loop() {  

//stepper1.startJogging(1);
//stepper2.startJogging(1);



//Pin toggling


//    digitalWrite(STEP1, HIGH);
//    delayMicroseconds(30);
//    digitalWrite(STEP1, LOW);
//    delayMicroseconds(30);

}