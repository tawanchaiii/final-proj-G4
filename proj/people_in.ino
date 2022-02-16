void count_people_in(void* parameter)
{
    while (1)
    {
        int temp = 35;
        if (digitalRead(pir) == HIGH)
        {
            lcd.setCursor(0, 0);
            digitalWrite(buzzer,HIGH);
            lcd.print("35 Degree.");
            vTaskDelay(2000 / portTICK_PERIOD_MS);
            digitalWrite(buzzer,LOW);
            lcd.clear(); 
            Serial.println("Servo should drive");   
            myservo.write(180);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            myservo.write(90);
            int diff_time = millis(); 
            int time = millis();          
            while( time - diff_time < 5000)
            {
                if(digitalRead(track_in) == HIGH)
                {
                    Serial.println("Track detected");
                    //POST("/pp/in");
                    break;
                }
                    time = millis();
                    Serial.print("In While loop ");
                    Serial.println(time - diff_time);
            }
            myservo.write(0);
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
            //POST("/pp/out");
        }
    } 
}