void get_sw(void* parameter){
    while(1){
        for(int i=0;i<4;i++){
            sw[i].loop();
            if (sw[i].isPressed()){
                Serial.println("The sw0: UNTOUCHED -> TOUCHED");
                digitalWrite(led[i],LOW);
            }

            if (sw[i].isReleased()){
                Serial.println("The sw0: TOUCHED -> UNTOUCHED");
                digitalWrite(led[i],HIGH);
            }
        }
    }
}