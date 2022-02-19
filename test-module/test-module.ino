
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP32Servo.h>
 
#define ONE_WIRE_BUS 18
int lcdColumns = 16;
int lcdRows = 2;
int buzzer = 25;
int PIR = 5;
int val = 0;
Servo myservo; 
ezButton limitSwitch(4); 
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
    pinMode(buzzer, OUTPUT);
    pinMode(PIR, INPUT);
    pinMode(18,INPUT);
    pinMode(34,INPUT);
    pinMode(26,INPUT);
    Wire.begin();
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    limitSwitch.setDebounceTime(50);
    sensors.begin();
    myservo.attach(23); 
    //scanner_lcd();
    //show_lcd();
    // PIR_READ();
    //microswitch();
    // temp_print();
    sound_buzzer();
    // drive_servo();
    
}

void loop()
{
//  Serial.println(digitalRead(26));
    // delay(200);
}