#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP32Servo.h>
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
int buzzer = 25;
void setup()
{
    Serial.begin(115200);
    pinMode(pir,INPUT);
    pinMode(track_in,INPUT);
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
    xTaskCreatePinnedToCore(get_sw, "get_sw", 1024*32, NULL, 1,NULL, 1); 
    //xTaskCreatePinnedToCore(PIR_READ, "PIR_READ", 1024*32, NULL, 1,NULL, 0); 
    //xTaskCreatePinnedToCore(show_lcd, "show_lcd", 1024*32, NULL, 1,NULL, 0); 
    xTaskCreatePinnedToCore(count_people_in, "count_people_in", 1024*32, NULL, 1,NULL, 1); 
    //xTaskCreatePinnedToCore(drive_servo, "drive_servo", 1024*32, NULL, 1,NULL, 0); 
    //count_people_in();
    

}
void loop(){
  
    //Serial.println(digitalRead(26));
    //delay(500);        
}