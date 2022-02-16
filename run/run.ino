#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP32Servo.h>
int led[4] = {13,12,14,27};
ezButton sw[] = {
	ezButton(15), 
	ezButton(2), 
	ezButton(0), 
	ezButton(4)
};

int pir = 5;

Servo myservo; 
void setup()
{
    Serial.begin(115200);
    pinMode(pir,INPUT);
    for(int i=0;i<4;i++){
        pinMode(led[i],OUTPUT);
        digitalWrite(led[i],HIGH);
        sw[i].setDebounceTime(100);
    }
    Servo myservo; 
    myservo.attach(18); 
    xTaskCreatePinnedToCore(get_sw, "get_sw", 1024*32, NULL, 1,NULL, 1); // stable
    xTaskCreatePinnedToCore(PIR_READ, "PIR_READ", 1024*32, NULL, 1,NULL, 1); // stable

}
void loop(){
    
}