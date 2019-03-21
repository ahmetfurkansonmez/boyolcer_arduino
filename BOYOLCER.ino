#include <LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);
int trig=7;
int echo=8;
int sure=0;
int mesafe1=0;
int mesafe2=0;
int sonuc=0;
int bttnSenk=9;
int bttnOlc=10;


void setup() 
{
  
  LCD.begin(16,2);
  LCD.clear();
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(bttnSenk,INPUT);
  pinMode(bttnOlc,INPUT);  
  Serial.begin(9600);
  

}

void loop() 
{
    if(digitalRead(bttnSenk)==LOW)
  {
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);
  sure= pulseIn(echo,HIGH);
  mesafe1=(sure/2)/(29.1);
  LCD.clear();
  LCD.print("SENKRONIZE :");
  LCD.print(mesafe1);
  LCD.print(" cm");
  delay(1000);
  }
      if(digitalRead(bttnOlc)==LOW)
  {
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);
  sure= pulseIn(echo,HIGH);
  mesafe2=(sure/2)/(29.1);
  sonuc=(mesafe1-mesafe2)+5;
  LCD.clear();
  LCD.print("BOYUNUZ :");
  LCD.print(sonuc);
  LCD.print(" cm");
  delay(1000);
  }


}
