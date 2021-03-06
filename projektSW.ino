#include <Arduino.h>
#include "../../../../usr/share/arduino/hardware/arduino/cores/arduino/HardwareSerial.h"
#include <string.h>

const int ledPin = 13;

int enablePin = 11;
int enablePin2 = 6;
int in1Pin = 10;
int in2Pin = 9;
int in3Pin = 8;
int in4Pin = 7;

int trigPin = 4;
int echoPin = 5;

char c;
int speedA = 0;
int speedB = 0;
boolean reverse = false;

int counter = 0;

void setup() {
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(in3Pin, OUTPUT);
    pinMode(in4Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(enablePin2, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    delay(50);
//    setMotorA(speed,reverse);
//    setMotorB(speed,reverse);
//BT communication
    range(5, 10);
    if (Serial.available()) {
        c = Serial.read();
        if (c == 'D') {
            speedA = 230;
            speedB = 230;
            setMotorA(speedA, reverse);
            setMotorB(speedB, reverse);
        } else if (c == 'C') {
            speedA -= 30;
            setMotorA(speedA, reverse);
            setMotorB(speedB, reverse);
        } else if (c == 'A') {
            speedB -= 30;
            setMotorA(speedA, reverse);
            setMotorB(speedB, reverse);
        } else if (c == 'E') {
            speedA = 230;
            speedB = 230;
            setMotorA(speedA, ! reverse);
            setMotorB(speedB, ! reverse);
        } else if (c == 'B') {
            speedB = 0;
            speedA = 0;
            setMotorA(0, reverse);
            setMotorB(0, reverse);
        }
    }
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

void stop(){
    speedA = 0;
    speedB = 0;
    analogWrite(enablePin,0);
    analogWrite(enablePin2,0);
}

int measureDistance() {
    long czas, dystans;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    czas = pulseIn(echoPin, HIGH);
    dystans = czas / 58;

    return dystans;
}
void range(int a, int b) {
    int howFar = measureDistance();
    if(counter == 200){
        Serial.println(howFar);
        counter = 0;
    }
    counter++;
    if ((howFar > a) && (howFar < b)) {
        stop();
    } else if (howFar > b && howFar < 100 ) {
        speedA = 230;
        speedB = 230;
        setMotorA(speedA,reverse);
        setMotorB(speedB,reverse);
    }
}