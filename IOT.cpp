
int Load = A1;
int PIR = A0;
int pirState = 2;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2); 


void setup(){
  lcd.init();                    
  lcd.backlight();
  pinMode(Load, OUTPUT);
  pinMode(pirState, OUTPUT);
  Serial.begin(9600);
  pinMode(PIR, INPUT);
}

void loop(){
  int value = digitalRead(PIR);
  if(value == HIGH){
    coi_bao();
  }else{
    lcd.clear();
    digitalWrite(pirState,LOW);
    delay(1000);
  }
}

void coi_bao(){
  lcd.setCursor(3,0);
  lcd.print("Phat hien");
  lcd.setCursor(0,1);
  lcd.print("Tran Cong Minh !");
  digitalWrite(Load,HIGH);
  digitalWrite(pirState,HIGH);
  delay(1500);
  digitalWrite(Load,LOW);
  digitalWrite(pirState,LOW);
  delay(1000);
}
