void sound_buzzer(){
    while(1){
        digitalWrite(buzzer,HIGH);
        delay(1000);
        digitalWrite(buzzer,LOW);
        delay(5000);
    }
}