void temp_print()
{
    while (1)
    {
        Serial.print(" Requesting temperatures...");
        sensors.requestTemperatures(); // Send the command to get temperatures
        Serial.println("DONE");
        Serial.print("Temperature for Device 1 is: ");
        Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
    }
}