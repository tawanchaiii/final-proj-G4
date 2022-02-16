void show_lcd(void* parameter){
    while(1){
        lcd.setCursor(0, 0);
        lcd.print("Hello, World!");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Hello, World!");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        lcd.clear(); 
    }
}