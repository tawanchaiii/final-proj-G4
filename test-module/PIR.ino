void PIR_READ()
{
    while (1)
    {
        val = digitalRead(5);
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
}