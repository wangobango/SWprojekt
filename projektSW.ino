#include <Arduino.h>
#include "../../../../usr/share/arduino/hardware/arduino/cores/arduino/HardwareSerial.h"
#include <string.h>

const int ledPin = 13;
int n = 0;
int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int switchPin = 7;
int potPin = 0;
unsigned int resp;
String data;
char *buffor[255];
char c;

void setup() {
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
    n = 7;
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
}

void loop() {
    Serial.write(44);
    delay(50);
    if(Serial.available()){
        int a = Serial.parseInt();
        if(a == 44){
            Serial.println("DUPA");
        }
        Serial.flush();
    }

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
//    if (Serial.available()) {
//        c = Serial.read() - 48;
//        if (c >= 0 && c < 6) {
//            resp = analogRead(A0);
//            Serial.print("Odczyt z portu A");
//            Serial.print(c, DEC);
//            Serial.print(": ");
//            Serial.println(String(resp));
//
//        } else {
//            Serial.println("Podaj numer portu analogowe od 0 do 5");
//        }
//    }

//STEROWANIE SILNIKIEM
//    int speed = 255;
//    boolean reverse = true;
//    setMotor(speed, reverse);
}

void setMotor(int speed, boolean reverse)
{
    analogWrite(enablePin, speed);
    digitalWrite(in1Pin, reverse);
    digitalWrite(in2Pin, !reverse);
}