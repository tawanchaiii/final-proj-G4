void microswitch()
{
    while (1)
    {
        limitSwitch.loop(); // MUST call the loop() function first

        if (limitSwitch.isPressed())
            Serial.println("The limit switch: UNTOUCHED -> TOUCHED");

        if (limitSwitch.isReleased())
            Serial.println("The limit switch: TOUCHED -> UNTOUCHED");

        int state = limitSwitch.getState();
        /*if (state == HIGH)
            Serial.println("The limit switch: UNTOUCHED");
        else
            Serial.println("The limit switch: TOUCHED");
        */
    }
}