
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 
#define ONE_WIRE_BUS 13
int lcdColumns = 16;
int lcdRows = 2;
int buzzer = 0;
int PIR = 18;
int val = 0;
ezButton limitSwitch(4); 
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
    pinMode(buzzer, OUTPUT);
    pinMode(PIR, INPUT);
    Wire.begin();
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    limitSwitch.setDebounceTime(50);
    sensors.begin();
    digitalWrite(buzzer, 0);
    //scanner_lcd();
    //show_lcd();
    //PIR_READ();
    //microswitch();
    //temp_print();
    
}

void loop()
{
    int sensorValue = digitalRead(0);
    Serial.println(sensorValue);
    delay(500);       
}