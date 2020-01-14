/*        
 *         Universidad Técnica del Norte
 *   Facultad de Ingeniería en Ciencias Aplicadas
 * Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                       Fecha: 14/01/2020
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un programa que ingrese una palabra por comunicación serial y genere una 
 * rotación de caracteres en la LCD.
 * 
 */

#include <LiquidCrystal.h>
#include <MsTimer2.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
String palabra;
String dato;
int rotacion = 0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    dato = Serial.readString();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    for (rotacion=0; rotacion<dato.length()-1; rotacion++) {
      palabra=palabra+dato.substring(rotacion, rotacion+1);
    }
    lcd.print(palabra);
    delay(1500);
    for (rotacion=0; rotacion<palabra.length(); rotacion++) {
      lcd.scrollDisplayLeft();
      delay(800);
    }
    for (rotacion=0; rotacion<16+palabra.length(); rotacion++) {
      lcd.scrollDisplayRight();
      delay(800);
    }
    for (rotacion=0; rotacion<16; rotacion++) {
      lcd.scrollDisplayLeft();
      delay(800);
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("INGRESE PALABRA");
  palabra = (" ");
  dato = (" ");
  lcd.print("                ");
  lcd.setCursor(0, 0);
}
