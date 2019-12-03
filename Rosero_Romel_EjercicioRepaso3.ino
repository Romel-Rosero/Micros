/*        
 *         Universidad Técnica del Norte
 *   Facultad de Ingeniería en Ciencias Aplicadas
 * Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                       Fecha: 02/12/2019
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un programa que active 4 juegos de luces con 5 leds al ingresar datos por comunicación serial 
 * de la siguiente forma: ACBF-> Activa juego 1 ACGF -> Activa juego 2 ADBF -> Activa juego 3 ADBH -> Activa juego 4
 * 
 */

int i=0;
int led= 8;
int led_1= 9;
int led_2= 10;
int led_3= 11;
int led_4= 12;
String combinacion;
//char numero;

void setup() {
  Serial.begin(9600);                               //Inicia la comunicación serial
  Serial.println("Sistema On");
  Serial.println(" ");
  Serial.println("Ingrese un dato como los mostrados a continuacion, para encender el juego de luces:"); 
  Serial.println("ACBF -> Activa juego 1"); 
  Serial.println("ACGF -> Activa juego 2");
  Serial.println("ADBF -> Activa juego 3");
  Serial.println("ADBH -> Activa juego 4");
  Serial.println(" ");
  pinMode(led,OUTPUT);                              //pines de salida para los leds
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(led_4,OUTPUT);
  }

void loop() {
 //  ACBF
  if (Serial.available() >0){
    combinacion = Serial.readString();          //lee la palabra o combinación ingresada
    Serial.println(combinacion);
    if(combinacion == "ACBF"){                  //Si es igual a ACBF se encienden los leds: led,led_2, led_4 
      digitalWrite(led,HIGH);                   
      digitalWrite(led_2,HIGH);
      digitalWrite(led_4,HIGH);
      Serial.println("Juego 1 activado");     //Mensaje de confirmación juego 1 activado
      Serial.println(" ");
      delay(300);
    }
    //ACGF
    if(combinacion == "ACGF"){                //Si es igual a ACGF se apagan los leds: led, led_2, led_4 y se encienden los nuevos: led_1, led_3
      digitalWrite(led,LOW);
      digitalWrite(led_1,HIGH);
      digitalWrite(led_2,LOW);
      digitalWrite(led_3,HIGH);
      digitalWrite(led_4,LOW);
      Serial.println("Juego 2 activado");     //Mensaje de confirmación juego 2 activado
      Serial.println(" ");
      delay(300);
    }
    //ADBF
    if(combinacion == "ADBF"){               //Si es igual a ADBF se apagan los leds: led_3, led_4 y se encienden los nuevos: led, led_1, led_2
      digitalWrite(led,HIGH);
      digitalWrite(led_1,HIGH);
      digitalWrite(led_2,HIGH);
      digitalWrite(led_3,LOW);
      digitalWrite(led_4,LOW);
      Serial.println("Juego 3 activado");     //Mensaje de confirmación juego 3 activado
      Serial.println(" ");
      delay(300);
    }
     //ADBH
    if(combinacion == "ADBH"){                //Si es igual a ADBH se apagan los leds: led, led_1 y se encienden los nuevos: led_2, led_3, led_4
      digitalWrite(led,LOW);
      digitalWrite(led_1,LOW);
      digitalWrite(led_2,HIGH);
      digitalWrite(led_3,HIGH);
      digitalWrite(led_4,HIGH);
      Serial.println("Juego 4 activado");   //Mensaje de confirmación juego 4 activado
      Serial.println(" ");
      delay(300);
  }
 }
}
