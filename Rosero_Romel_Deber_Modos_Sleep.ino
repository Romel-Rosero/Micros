/*        
 *         Universidad Técnica del Norte
 *   Facultad de Ingeniería en Ciencias Aplicadas
 * Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                       Fecha: 04/02/2020
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un ejercicio que cada 2 segundos el sistema se encuentre activado y cada 10 segundos 
 * el sistema baje su consumo de corriente. 
 * Envíe mensajes de comunicación serial para mostrar el resultado. 
 * 
 */

#include<avr/power.h>
#include<avr/sleep.h>
#include<TimerOne.h>
int tiempo=0;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(valor);
  set_sleep_mode(SLEEP_MODE_IDLE);  //Modo Sleep de Microntrolador (SLEEP_MODE_IDLE)              
}
void loop() {
  if (tiempo == 2) {
    Serial.println("INICIO");
    Serial.println(tiempo);
  }
  if (tiempo == 10) {
    Serial.println("DESCANSO");
    sleep_mode();               //Ingresa al modo sleep
    sleep_enable();             //Habilitar la configuración
  }if(tiempo==10){
    sleep_disable();
    tiempo=0;
  }
}
void valor() {
  tiempo++;
}
