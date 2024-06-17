#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22  // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27 for a 16x2 LCD

int lightPin = A0;
int lightValue = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  int lightValue = analogRead(lightPin);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humidade: ");
  lcd.print(humidity);
  lcd.print(" %");
  
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  if (temperature > 50) {
    lcd.setCursor(0,1);
    lcd.print("Rua: Perigosa");
  } else {
    lcd.setCursor(0,1);
    lcd.print("Rua: Segura  ");
  }

  delay(2000);  
}
