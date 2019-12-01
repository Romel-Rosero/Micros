/*        
 *         Universidad Técnica del Norte
 *   Facultad de Ingeniería en Ciencias Aplicadas
 * Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                       Fecha: 30/11/2019
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un programa que el número ingresado por comunicación serial se refleje en código binario hasta 8 bits con leds. 
 * Ejemplo: número ingresado 5 -> sistema con leds 00000101
 * 
 */
 
int led = 9;     
int led_1= 8;
int led_2= 7;
int led_3= 6;
int led_4= 5;
int led_5= 4;
int led_6= 3;
int led_7= 2;
int vector_leds[8] = {9, 8, 7, 6, 5, 4, 3, 2};        //vector leds
int numero;
String dato;
int valor1;
int valor2;

void setup() {
  Serial.begin(9600);                               //Inicia la comunicación serial
  Serial.println("Sistema On");
  Serial.println(" ");
  Serial.println("Ingrese un numero del (0 al 255) para obtener su binario correspondiente:");
  pinMode(led, OUTPUT);                             //pines de salida para los leds
  pinMode(led_1, OUTPUT);                           
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {                 
    dato = Serial.readStringUntil("\n");
    valor1 = dato.toInt();                          //Cambia el valor del dato en entero
    delay(200);
  }
    
  if (valor1 > 0 && valor1 < 256) {                   //Verifica si el número ingresado está entre 0 y 256
    valor2 = valor1;                                
    for (numero = 0; numero < 8; numero++) {                  
      if ((valor2 % 2) == 1) {                          //Transformación a binario
        digitalWrite(vector_leds[numero], HIGH);
      } else {
        digitalWrite(vector_leds[numero], LOW);
      }
      valor2 = (valor2 / 2);
    }
  }
  else {
    for (numero = 0; numero < 8; numero++) {
      digitalWrite(vector_leds[numero], LOW);
    }
    valor1 = 0;
  }  
}
