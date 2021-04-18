#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);
int pumppin = 8;

void setup() 
{
  lcd.begin();
  dht.begin();
  pinMode(pumppin, OUTPUT);
}

void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(2,0);
  lcd.print("Smart Irrigation");
  if(t>23){
      digitalWrite(pumppin, HIGH);
      lcd.setCursor(0,2);
      lcd.print("H=");
      lcd.print(h);
      lcd.print("%");
      lcd.setCursor(11,2);
      lcd.print("T=");
      lcd.print(t);
      lcd.print((char)223);
      lcd.print("C");
      lcd.setCursor(0,2);
      lcd.print("Pump ON");
  else
  {
      digitalWrite(pumppin, LOW);
      lcd.setCursor(0,2);
      lcd.print("H=");
      lcd.print(h);
      lcd.print("%");
      lcd.setCursor(11,2);
      lcd.print("T=");
      lcd.print(t);
      lcd.print((char)223);
      lcd.print("C");
      lcd.setCursor(0,2);
      lcd.print("Pump OFF");
   }
  }
  delay(1000);
  lcd.clear();
}
