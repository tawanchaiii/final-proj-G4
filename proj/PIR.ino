void PIR_READ(void* parameter)
{
    while (1)
    {
        int val = digitalRead(pir_in);
        Serial.print("val = ");
        Serial.print(val);
        Serial.print(" ");
        delay(100);
    }
}