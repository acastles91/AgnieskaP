#include <Arduino.h>
#include "esp_task_wdt.h"

//Pinout

#define EN    23
#define STEP1 22
#define DIR1  21
#define STEP2 32
#define DIR2  33
#define SPEED 350 


float gearRatio = 15.3;
int schneke = 48;
float microsteps = 800;
float correction1 = 0.406;
float correction2 = 1.4942;

const int channel1 = 1;
const int channel2 = 2;

//Motors with planetary gears
//const int freq1 = (microsteps * gearRatio) / 7;
//const int freq2 = (microsteps * gearRatio) / 75;

const int freq1 = (microsteps) / 7;
const int freq2 = (microsteps) / 75;

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


//PWM

ledcSetup(channel1, freq1, resolution);
ledcSetup(channel2, freq2, resolution);

ledcAttachPin(STEP1, channel1);
ledcAttachPin(STEP2, channel2);

ledcWrite(channel1, 127);
ledcWrite(channel2, 127);

}



void loop() {  

//Pin toggling

//    digitalWrite(STEP1, HIGH);
//    delayMicroseconds(30);
//    digitalWrite(STEP1, LOW);
//    delayMicroseconds(30);

}