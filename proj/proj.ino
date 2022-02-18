#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP32Servo.h>
#include <HTTPClient.h>
#include <string.h>
#include <esp_task_wdt.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#define ONE_WIRE_BUS 18
const char* ssid = "Champ SE";
const char* password = "qazwsxedc123";
const char* url_post = "https://ecourse.cpe.ku.ac.th/exceed04/api/hardware_in_out";
const char* url_get = "https://ecourse.cpe.ku.ac.th/exceed04/api/hardware";
// const char* url_get = "http://127.0.0.1:8080/hardware";
// const char* url_post = "http://127.0.0.1:8080/hardware_in_out";
String op;
char str[100];
const int _size = 2*JSON_OBJECT_SIZE(4);
StaticJsonDocument<_size> JSONPost;
StaticJsonDocument<_size> JSONGet;
int led[4] = {13,12,14,27};
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo; 
ezButton sw[] = {
	ezButton(15), 
	ezButton(2), 
	ezButton(0), 
	ezButton(4)
};

int pir = 5;
int track_in  = 26;
int track_out = 34;
int buzzer = 25;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int qpeople_in = 0;
int qpeople_out = 0;
void setup()
{
    Serial.begin(115200);
    pinMode(pir,INPUT);
    pinMode(track_in,INPUT);
    pinMode(track_out,INPUT);
    
    pinMode(buzzer,OUTPUT);
    for(int i=0;i<4;i++){
        pinMode(led[i],OUTPUT);
        digitalWrite(led[i],HIGH);
        sw[i].setDebounceTime(100);
    }
    myservo.attach(23); 
    lcd.init();
    lcd.backlight();
    myservo.write(90);
    WiFi_Connect();
    xTaskCreatePinnedToCore(get_sw, "get_sw", 1024*32, NULL, 1,NULL, 1); 
    //xTaskCreatePinnedToCore(temp_print, "temp_print", 1024*32, NULL, 1,NULL, 1); 
    //xTaskCreatePinnedToCore(PIR_READ, "PIR_READ", 1024*32, NULL, 1,NULL, 0); 
    //xTaskCreatePinnedToCore(show_lcd, "show_lcd", 1024*32, NULL, 1,NULL, 0); 
    xTaskCreatePinnedToCore(count_people_in, "count_people_in", 1024*32, NULL, 1,NULL, 1); 
    xTaskCreatePinnedToCore(_post, "_post", 1024*32, NULL, 1,NULL, 1); 
    //xTaskCreatePinnedToCore(drive_servo, "drive_servo", 1024*32, NULL, 1,NULL, 0); 
    //count_people_in();
    

}
void loop(){
    //Serial.print("This is value ");
    //Serial.println(_get());
    
}

