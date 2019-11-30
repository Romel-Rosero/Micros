/*        
 *         Universidad Técnica del Norte
 *   Facultad de Ingeniería en Ciencias Aplicadas
 * Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                       Fecha: 29/11/2019
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un programa que por comunicación serial se ingrese el límite de lectura del conversor análogo digital (0-1024) 
 * si el valor del conversor supera dicho valor, se enciende un led.
 * 
 */

float dato = 0;                                 //valor del A-D
int menor = 0;
int mayor = 0;
int led = 8;

void setup () {
  Serial.begin(9600);                           //Inicia la comunicacion serial a 9600
  Serial.println("Sistema On");
  pinMode(led, OUTPUT);                         //pin de salida para el led
}
void loop() {

  if (Serial.available() > 0) {                 //envío y recibo de datos
    Serial.print("Ingrese el valor menor");     //ingreso del valor menor
    Serial.println(' ');
    delay (700);
    menor = Serial.parseInt();
    Serial.println(' ');
    delay (700);
    Serial.print("Ingrese el valor mayor");     //ingreso del valor mayor
    Serial.println(' ');
    delay (700);
    mayor = Serial.parseInt();
    Serial.println(' ');
    delay (700);

    dato = analogRead(0);                     
    if ((menor > dato) || (mayor < dato)) {
      Serial.println("Sale de los limites");    //Si el valor ingresado es mayor al dato el resultado será sale de los límites
      delay (200);
      digitalWrite(led, HIGH);
    }
    else {
      Serial.println("No sale de los limites");  //Si el valor ingresado es menor al dato el resultado será no sale de los límites 
      delay (200);
      digitalWrite(led, LOW);
    }
  }
}
