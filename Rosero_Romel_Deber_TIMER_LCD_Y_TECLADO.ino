/*        
 *         Universidad Técnica del Norte
 *   Facultad de Ingeniería en Ciencias Aplicadas
 * Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                       Fecha: 14/01/2020
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un programa que mediante teclado matricial (consultar) ingrese el tiempo en 
 * segundos de una cuenta regresiva. Esta cuenta, decrece cada 1 segundo mediante timer.
 * 
 */

#include <LiquidCrystal.h>
#include <MsTimer2.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
char boton;
String dato;
int numero = 0;
int i = 0;


//CODIGO TECLADO MATRICIAL
#include <Keypad.h>   
const byte fil = 4;   
const byte col = 4;    
char keys[fil][col] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinFil[fil] = {11, 10, 9, 8};
byte pinCol[col] = {7, 6, 5, 4};
Keypad teclado = Keypad(makeKeymap(keys), pinFil, pinCol, fil, col); 
//TERMINA CODIGO TECLADO MATRICIAL

void setup() {
  MsTimer2::set(1000, lectura);
  MsTimer2::start();
  lcd.begin(16, 2);
  lcd.print("INGRESE NUMERO");
  lcd.setCursor(0, 1);
}

void loop() {
  boton = teclado.getKey();
  if (boton) {
    if (boton == 'A' || boton == 'B' || boton == 'D' || boton == '#' || boton == '*') {
      i = 1 - i;
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(9, 1);
      lcd.print("       ");
      lcd.setCursor(0, 0);
      lcd.print("CUENTA REGRESIVA");
    }
    else if (boton == 'C') {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("REINICIO");
      delay(1500);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("INGRESAR NUMERO");
      lcd.setCursor(0, 1);
      boton=(' ');
      dato=(" ");
      i=0;
      numero=0;
    }
    else {
      lcd.print(boton);
      dato = dato + boton;
    }
    numero = dato.toInt();
  }
}
void lectura() {
  if (i == 1 ) {
    if (numero > 0) {
      lcd.setCursor(9, 1);
      lcd.print("      ");
      lcd.setCursor(9, 1);
      lcd.print(numero);
      numero--;
    }
    else if (numero == 0) {
      lcd.setCursor(9, 1);
      lcd.print("    ");
      lcd.setCursor(9, 1);
      lcd.print(numero);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("TERMINA CONTEO");
    }
  }
}
 
