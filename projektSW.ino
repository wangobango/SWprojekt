#include <Arduino.h>
#include "../../../../usr/share/arduino/hardware/arduino/cores/arduino/HardwareSerial.h"
#include <string.h>

const int ledPin = 13;

int enablePin = 11;
int enablePin2 = 6;
int in1Pin = 10;
int in2Pin = 9;
int int3Pin = 8;
int int4Pin = 7;

char c;
int speed = 255;
boolean reverse = true;

void setup() {
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(int3Pin, OUTPUT);
    pinMode(int4Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(enablePin2, OUTPUT);
}

void loop() {
    delay(50);
//    if(Serial.available()){
//        c = (char) Serial.read();
//        if(c == '2'){
//            Serial.println("DUPA");
//        }
//    }

//    char c = Serial.read();
//    data += c;
//
//    Serial.print(data);

//    if(Serial.available()){
//        Serial.println("CONNECTION STARTED!");
//        n = Serial.read() - '0';
//        if(n == 0){
//            digitalWrite(13,HIGH);
//            delay(1000);
//            digitalWrite(13,LOW); delay(1000);
//            Serial.println("DUPA RECIVED!");
//        }
//    }
//BT communication
    if (Serial.available()) {
        c = Serial.read();
        if(strcmp(c,"D")){
            setMotorA(speed,reverse);
            setMotorB(0,reverse);
        } else if(strcmp(c,"C")){
            setMotorA(0,reverse);
            setMotorB(speed,reverse);
        } else if(strcmp(c,"A")){
            setMotorA(speed,reverse);
            setMotorB(speed,reverse);
        } else if(strcmp(c,"E")){
            setMotorA(speed,!reverse);
            setMotorB(speed,!reverse);
        }
        Serial.println(c);
    }

//STEROWANIE SILNIKIEM
//    setMotor(speed, reverse);
}

void setMotorA(int speed, boolean reverse)
{
    analogWrite(enablePin, speed);
    digitalWrite(in1Pin, reverse);
    digitalWrite(in2Pin, !reverse);
}

void setMotorB(int speed, boolean reverse)
{
    analogWrite(enablePin2, speed);
    digitalWrite(in3Pin, reverse);
    digitalWrite(in4Pin, !reverse);
}