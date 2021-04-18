#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int soil;
int moisture;
int pumppin = 8;
LiquidCrystal_I2C lcd(0x27,20,4);
void setup()
{
  lcd.begin();
  pinMode(pumppin, OUTPUT);
}

void loop()
{
      soil = analogRead(A0);
      moisture = map(soil,275,890,100,0);
      lcd.setCursor(2,0);
      lcd.print("Smart Irrigation");
      if(moisture<60)
      {
        digitalWrite(pumppin, HIGH);
        lcd.setCursor(0,1);
        lcd.print("Moisture = ");
        lcd.print(moisture);
        lcd.print("%");
        lcd.setCursor(0,2);
        lcd.print("Pump ON");
        else
        {
          digitalWrite(pumppin, LOW);
          lcd.setCursor(0,1);
          lcd.print("Moisture = ");
          lcd.print(moisture);
          lcd.print("%");
          lcd.setCursor(0,2);
          lcd.print("Pump OFF");
        }
      }
      
      delay(1000);
      lcd.clear();
}
