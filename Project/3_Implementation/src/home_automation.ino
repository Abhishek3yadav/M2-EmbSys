#include <LiquidCrystal.h>

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int R = 10;
int D7_pin = 4;
int D6_pin = 5;
int D5_pin = 6;
int D4_pin =  7;
int EN_pin = 11;
int RS_pin = 12;

LiquidCrystal lcd(RS_pin, EN_pin, D4_pin, D5_pin, D6_pin, D7_pin);


void setup() {
Serial.begin(9600);
pinMode(10,OUTPUT);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 

  lcd.print("Temp = ");
  lcd.print(T);   
  lcd.print(" F");
  
  delay(500);            
  lcd.clear();
  if(T >= 100 && T<= 200) 
 digitalWrite(R, HIGH) ;
else if (T >= 0 && T< 100) 
 digitalWrite(R, LOW) ;
 
}
