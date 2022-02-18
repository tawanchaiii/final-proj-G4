void get_sw(void* parameter){
    while(1){
        for(int i=0;i<4;i++){
            sw[i].loop();
            if (sw[i].isPressed()){
                digitalWrite(led[i],LOW);
            }

            if (sw[i].isReleased()){
                digitalWrite(led[i],HIGH);
            }
        }
    }
}