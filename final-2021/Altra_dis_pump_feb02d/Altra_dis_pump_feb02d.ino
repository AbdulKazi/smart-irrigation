#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int pumppin = 8;
int trigpin = 6;
int echopin = 7;
int distance;
long duration;
void setup()
{
  lcd.begin();
  pinMode(pumppin, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

}

void loop()
{
   digitalWrite(trigpin, LOW);
   delayMicroseconds(20);
   digitalWrite(trigpin, HIGH);
   delayMicroseconds(100);
   digitalWrite(trigpin, LOW);
   duration = pulseIn(echopin, HIGH);
   distance = duration*0.034/2;
   lcd.setCursor(2,0);
   lcd.print("Smart Irrigation");
   if(distance>9)
   {
      digitalWrite(pumppin,HIGH);
      lcd.setCursor(0,1);
      lcd.print("L=");
      lcd.print(distance);
      lcd.print("cm");
      lcd.setCursor(0,2);
      lcd.print("Pump On");
   }
   else
   {
      digitalWrite(pumppin,LOW);
      lcd.setCursor(0,1);
      lcd.print("L=");
      lcd.print(distance);
      lcd.print("cm");
      lcd.setCursor(0,2);
      lcd.print("Pump OFF");
   }
   
   delay(1000);
   lcd.clear();
   
}
