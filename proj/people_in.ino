void count_people_in(void* parameter)
{
    while (1)
    {
        if(0){
            lcd.setCursor(0,0);
            lcd.print("People max");
            lcd.setCursor(0,1);
            lcd.print("Please wait");
        }
     
       
        else {
            lcd.setCursor(0, 0);
            lcd.print("Welcome to");
            lcd.setCursor(0, 1);
            lcd.print("theater");
            int chk = 0;
            if(get_temp()> 27){
                lcd.clear();
                chk = 1;
                int a = millis();
                int b = millis();
                while(a-b < 8000)
                {
                    sensors.requestTemperatures();
                    lcd.setCursor(0,0);
                    lcd.print(get_temp());
                    if(get_temp() > 36)
                    {
                        lcd.clear();
                        lcd.print("HOT");
                        chk = 0;
                        vTaskDelay(1500 / portTICK_PERIOD_MS);
                        break;
                    }
                    if(get_temp() < 27)
                    {
                        lcd.clear();
                        lcd.print("Not human");
                        chk = 0;
                        vTaskDelay(1500 / portTICK_PERIOD_MS);
                        break;
                    }
                    a = millis();
                }
            } 
            
            if(chk)
            {
                lcd.clear(); 
                lcd.setCursor(0, 0);
                digitalWrite(buzzer,HIGH);
                lcd.print("Pass Welcome");
                vTaskDelay(2000 / portTICK_PERIOD_MS);
                digitalWrite(buzzer,LOW);
                lcd.clear(); 
                //Serial.println("Servo should drive");   
                myservo.write(180);
                vTaskDelay(500 / portTICK_PERIOD_MS);
                myservo.write(90);
                int diff_time = millis(); 
                int time = millis();       
                lcd.setCursor(0, 0);   
                lcd.print("Wait to tracking");
                while(time - diff_time < 5000)
                {
                    if(digitalRead(pir_in) == HIGH)
                    {
                        lcd.clear();
                        lcd.print("Getting in");
                        vTaskDelay(2000 / portTICK_PERIOD_MS);
                        qpeople_in++;
                        break;
                    }
                        time = millis();
                }
                lcd.clear();
                myservo.write(0);   
            
                Serial.print("People in = ");
                Serial.println(qpeople_in);
                vTaskDelay(500 / portTICK_PERIOD_MS);
            }
            myservo.write(90);
        }
    } 
}

void count_people_out(void* parameter)
{
    while (1)
    {
        if (digitalRead(pir_out) == HIGH)
        {
            qpeople_out++;
            vTaskDelay(2000 / portTICK_PERIOD_MS);
            Serial.print("Out = ");
            Serial.println(qpeople_out);
        }
       

    } 
}