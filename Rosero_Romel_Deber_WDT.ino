/*        
 *         Universidad Técnica del Norte
 *   Facultad de Ingeniería en Ciencias Aplicadas
 * Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                       Fecha: 04/02/2020
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un programa que mediante comunicación serial ingrese el tiempo de reset del arduino de la siguiente forma: 
 * A-> 1 s B-> 2s C-> 4s D-> 8s 
 * Hay que tener en cuenta que el sistema puede ser re configurado la veces necesarias(interrupciones) 
 * 
 */

#include <avr/wdt.h>                          //libreria wdt
#include <TimerOne.h>                         //libreria timer1 

int i=0;
char tiempo;
void setup() {
 attachInterrupt (0,activacion,LOW);
 Serial.begin(9600);
 Serial.println("RESET");
}
void loop() {  
}
void activacion(){
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
   Serial.println("Seleccione el tiempo de RESET:");
   Serial.println("Recuerde que el tiempo de reset empieza a partir del segundo 20");
   Serial.println("A para 1S");
   Serial.println("B para 2S");
   Serial.println("C para 4S");
   Serial.println("D para 8S");
}
void conteo(){
  tipos();
  }    
void tipos (){
switch(tiempo){
    case 'A' :
      i++;
      Serial.println(i);
      if(i==20){
       wdt_enable(WDTO_1S);
       }
    break;
    case 'B':
      i++;
      Serial.println(i);
      if(i==20){
      wdt_enable(WDTO_2S);
       }
    break;
    case 'C':
      i++;
      Serial.println(i);
      if(i==20){
      wdt_enable(WDTO_4S);
       }
    break;
    case 'D':
      i++;
      Serial.println(i);
      if(i==20){
       wdt_enable(WDTO_8S);
       }
    break;
  }
}
  void serialEvent(){ 
  if (Serial.available()>0){ 
    tiempo=Serial.read(); 
}
  }
