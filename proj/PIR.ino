/*void PIR_READ(void* parameter)
{
    while (1)
    {
        val = digitalRead(pir);
        Serial.print("val = ");
        Serial.println(val);
        if (val == 0)
        {
            digitalWrite(buzzer, HIGH);
        }
        else
        {
            digitalWrite(buzzer, LOW);
        }
        delay(100);
    }
}*/
void PIR_READ(void* parameter)
{
    while (1)
    {
        int val = digitalRead(pir);
        Serial.print("val = ");
        Serial.print(val);
        Serial.print(" ");
        Serial.println(digitalRead(track_in));
        delay(100);
    }
}