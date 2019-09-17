#include <Wire.h>
#include "rgb_lcd.h"

//Declaration des broches utilisés sur la carte arduino
#define pin_rx A0
#define pin_ry A1
#define pin_sw A2
#define pin_led 2

rgb_lcd lcd;

//declaration des variables pour l'Axe X, Y et le retour bouton
int sw, ry, rx;

//declartion de la gamme de couleur de fond pour l'écran LCD
const int colorR = 127;
const int colorG = 127;
const int colorB = 127;

void setup() {
  Serial.begin(9600);
  
  //Initialisation de la LED
  pinMode(pin_led, OUTPUT);
  digitalWrite(pin_led, LOW);

  //Initialisation de l'écran LCD
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  delay(1000);
}

void loop() {

  //Lecture des informations du joystick
  rx=analogRead(pin_rx);
  ry=analogRead(pin_ry);
  sw=analogRead(pin_sw);

  //Affichage des valeurs X, Y et retour bouton sur le moniteur Serie en decimale et Hexadecimale
  Serial.print("rx = ");
  Serial.print(rx);
  Serial.print(" 0x");
  Serial.print(rx,HEX);
  Serial.print("   ry = ");
  Serial.print(ry);
  Serial.print(" 0x");
  Serial.print(ry,HEX);
  if(sw>0)
  {
    Serial.println("   sw = 1 0x1");
    digitalWrite(pin_led, LOW);
  }
  else
  {
    Serial.println("   sw = 1 0x0");
    digitalWrite(pin_led, HIGH);
  }
//  Serial.print("   sw = ");
//  Serial.print(sw);
//  Serial.print(" 0x");
//  Serial.println(sw,HEX);

  //Affichage des valeurs X sur l'ecran LCD en decimale et Hexadecimale
  lcd.setCursor(0, 0);
  lcd.print("Rx=");
  lcd.setCursor(3, 0);
  lcd.print(rx);
  lcd.setCursor(8, 0);
  lcd.print("0x");
  lcd.setCursor(10, 0);
  lcd.print(rx,HEX);
  //efface 3 caracteres lorsque la valeur X est inferieur à 10
  if(rx<10)
  {
    lcd.setCursor(4, 0);
    lcd.setCursor(11, 0);
    lcd.print("   ");
  }
  //efface 2 caracteres lorsque la valeur X est inferieur à 10
  if(rx<100)
  {
    lcd.setCursor(5, 0);
    lcd.setCursor(12, 0);
    lcd.print("  ");
  }
  //efface 1 caracteres lorsque la valeur X est inferieur à 10
  if(rx<1000)
  {
    lcd.setCursor(6, 0);
    lcd.setCursor(13, 0);
    lcd.print(" ");
  }

  //Affichage des valeurs Y sur l'ecran LCD en decimale et Hexadecimale
  lcd.setCursor(0, 1);
  lcd.print("Ry=");
  lcd.setCursor(3, 1);
  lcd.print(ry);
  lcd.setCursor(8, 1);
  lcd.print("0x");
  lcd.setCursor(10, 1);
  lcd.print(ry,HEX);
  //efface 3 caracteres lorsque la valeur Y est inferieur à 10
  if(ry<10)
  {
    lcd.setCursor(4, 1);
    lcd.setCursor(11, 1);
    lcd.print("   ");
  }
  //efface 2 caracteres lorsque la valeur Y est inferieur à 10
  if(ry<100)
  {
    lcd.setCursor(5, 1);
    lcd.setCursor(12, 1);
    lcd.print("  ");
  }
  //efface 1 caracteres lorsque la valeur Y est inferieur à 10
  if(ry<1000)
  {
    lcd.setCursor(6, 1);
    lcd.setCursor(13, 1);
    lcd.print(" ");
  }
  
}
