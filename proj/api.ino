void WiFi_Connect(){
    WiFi.disconnect();
    WiFi.begin(ssid,password);
    while(WiFi.status() != WL_CONNECTED){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        Serial.println("Connecting WiFi...");
        lcd.clear();
        lcd.setCursor(0, 0);  
        lcd.print("Connecting WIFI");
        lcd.setCursor(0, 1);  
        lcd.print(".");
        lcd.print(".");
        lcd.print(".");
    }
    lcd.clear();
    Serial.println("Connected Finish");
    Serial.print("IP = ");
    Serial.println(WiFi.localIP());
}

void _post(void* parameter){
    while(1){
        if(WiFi.status() == WL_CONNECTED){
            String chair;
            int tled[4];
            HTTPClient http;
            http.begin(url_post);
            http.addHeader("Content-Type","application/json");
            for(int i=0;i<4;i++){
                tled[i] = digitalRead(led[i]);
            }
            chair = String(String(tled[0]) + " " + String(tled[1]) + " " + String(tled[2]) + " " + String(tled[3]));
            Serial.println(chair);
            JSONPost["people_in"] = (int)qpeople_in;
            JSONPost["people_out"] = (int)qpeople_in;
            JSONPost["chair_status"] = chair;
            serializeJson(JSONPost,str);
            int httpCode = http.POST(str);
            if(httpCode == HTTP_CODE_OK){
                String payload = http.getString();
                Serial.println(httpCode);
                Serial.println(payload);
            }
            else{
                Serial.println(httpCode);
                Serial.println("ERROR on POST Request");
            }
        }
        else 
            WiFi_Connect();
        vTaskDelay(4000 / portTICK_PERIOD_MS);
    }
}
int _get(){
    if(WiFi.status() == WL_CONNECTED){
        HTTPClient http;
        http.begin(url_get);
        int httpCode = http.GET();
        if(httpCode == HTTP_CODE_OK){
            String payload = http.getString();
            DeserializationError err = deserializeJson(JSONGet,payload);
            if(err){
                Serial.print(F("deserializeJson() failed with code "));
                Serial.println(err.c_str());
                return -1;
            }
            else{
                Serial.println((int)JSONGet["current_people"]);
                return (int)JSONGet["current_people"];
            }
        }
        else{
            Serial.println(httpCode);
            Serial.println("ERROR on GET Request");
        }
    }
    else {
        WiFi_Connect();
    }
}

int door(){
    if(WiFi.status() == WL_CONNECTED){
        HTTPClient http;
        http.begin(url_door);
        int httpCode = http.GET();
        if(httpCode == HTTP_CODE_OK){
            String payload = http.getString();
            DeserializationError err = deserializeJson(JSONGet,payload);
            if(err){
                Serial.print(F("deserializeJson() failed with code "));
                Serial.println(err.c_str());
                return -1;
            }
            else{
                Serial.print("Door = ");
                Serial.println((int)JSONGet["current_people"]);
                return (int)JSONGet["current_people"];
            }
        }
        else{
            Serial.println(httpCode);
            Serial.println("ERROR on GET Request");
        }
    }
    else {
        WiFi_Connect();
    }

}
