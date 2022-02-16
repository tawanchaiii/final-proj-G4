void PIR_READ(void* parameter)
{
    while (1)
    {
        int val = digitalRead(pir);
        Serial.print("val = ");
        Serial.println(val);
        delay(100);
    }
}