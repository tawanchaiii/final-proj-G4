void drive_servo()
{
    while (1)
    {
        myservo.write(0);   
        delay(1000);        
        myservo.write(90);  
        delay(1000);        
        myservo.write(180); 
        delay(1000);       
    }
}