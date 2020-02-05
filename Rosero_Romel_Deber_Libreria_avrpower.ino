/*        
 *         Universidad Técnica del Norte
 *   Facultad de Ingeniería en Ciencias Aplicadas
 * Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                       Fecha: 04/02/2020
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un programa que cada 5 segundos el sistema desactiva el conversor análogo digital,
 * cada 8 segundos la comunicación serial y cada 12 segundos un desactivación total.
 * 
 */

#include <avr/power.h>
#include<avr/sleep.h>
#include <EEPROM.h>
#include <LowPower.h>
#include <avr/wdt.h>
#include <MsTimer2.h>
#include <TimerOne.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int valor = EEPROM.read(0);
int LCD = 7;
int cont = 0;
int valor1;


void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(contar);
  power_all_enable();
  lcd.begin(16, 2);
  valor = 0;
}

void loop() {
  Serial.println(valor);
  lcd.setCursor(6, 1);
  lcd.print("Tiempo:" + String(cont));
  valor1 = analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print(valor1);
}
void contar() {
  cont++;
}

void apagar() {
  if (cont == 5) {                 
    valor = valor + 1;
    lcd.setCursor(0, 0);
    lcd.print("CAD Apagado");
    power_adc_disable();
  }
}

  
