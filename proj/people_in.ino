void count_people_in(void* parameter)
{
    while (1)
    {
        lcd.setCursor(0, 0);
        lcd.print("Welcome to");
        lcd.setCursor(0, 1);
        lcd.print("theater");
        if (digitalRead(pir) == HIGH)
        {
            lcd.clear(); 
            sensors.requestTemperatures();
            lcd.setCursor(0, 0);
            digitalWrite(buzzer,HIGH);
            lcd.print(sensors.getTempCByIndex(0));
            lcd.print(" Celcius");
            vTaskDelay(2000 / portTICK_PERIOD_MS);
            digitalWrite(buzzer,LOW);
            lcd.clear(); 
            lcd.print("Welcome viewer");
            //Serial.println("Servo should drive");   
            myservo.write(180);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            myservo.write(90);
            int diff_time = millis(); 
            int time = millis();       
            lcd.setCursor(0, 0);   
            lcd.print("Wait to tracking");
            while( time - diff_time < 5000)
            {
                if(digitalRead(track_in) == HIGH)
                {
                    lcd.print("Getting in");
                    qpeople_in++;
                    break;
                }
                    time = millis();
            }
            lcd.clear();
            
            myservo.write(0);   
           
            Serial.print("People in = ");
            Serial.println(qpeople_in);
            //delay(4000);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
        }
        myservo.write(90);
        //delay(200);
        //Serial.println("Finish");
    } 
}

void count_people_out(void* parameter)
{
    while (1)
    {
        if (digitalRead(track_out) == HIGH)
        {
            qpeople_out++;
        }
    } 
}