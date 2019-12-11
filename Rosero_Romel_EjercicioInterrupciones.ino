/*        
 *                                        Universidad Técnica del Norte
 *                                 Facultad de Ingeniería en Ciencias Aplicadas
 *                             Carrera de Ingeniería en Electrónica y Redes de Comunicación
 * 
 * Nombre: Romel Rosero                                                 Fecha: 10/12/2019
 * Asignatura: Sistemas Microprocesados
 * 
 * Realizar un ejercicio en el cual tenga las etapas de: (i)Ingreso de datos y (ii) ordenamiento (i)Al ingresar la palabra solo pueden ser números 
 * por comunicación serial. (ii) Una vez ingresados los números, ordenarlos de menor a mayor e imprimirlo por comunicación serial.
 * 
 */


String dato;
String cant;
int i = 0;
int modos = 0;
int seleccion = 0;
int cambio;
int vaux;                       //variable auxiliar

void setup() {
  attachInterrupt(0, on, LOW);
  attachInterrupt(1, on1, LOW);
  Serial.begin(9600);             //Inicia la comunicacion serial a 9600
  Serial.println("SISTEMA ON");
  Serial.println(" ");
  Serial.println("BIENVENIDO");
  Serial.println("A continuacion, presione el boton 1 para iniciar con el programa");
}
void loop() {
  if (seleccion == 1 && modos == 1) {
    if (Serial.available() > 0) {
      dato = Serial.readString();
      Serial.println(" ");
      Serial.println("Numeros ingresados correctamente");
      Serial.println("Presione el boton 1 para proceder a ordenar los numeros");
    }
  }
  else if (modos == 2 && dato != "") {      
    int num[dato.length()];                 //vector que procedera a guardar el dato
    for (i = 0; i < dato.length(); i++) {   
      cant = dato.substring(i, (i + 1));   
      num[i] = cant.toInt();                //datos convertidos en enteros y guardados
    }
    do {                                    //Ordenar los números
      cambio = 0;
      for (i = 0; i < dato.length(); i++) {
        if (num[i] > num[i + 1]) {          //Compara los números entre posiciones
          cambio = 1;
          vaux = num[i];
          num[i] = num[i + 1];
          num[i + 1] = vaux;
        }
      }
    }
    while (cambio);
    for (i = 0; i < dato.length(); i++) {       //número ordenado
      Serial.print(num[i]);
    }
    Serial.println(" ");
    dato = "";
  }
}
void on() {
  switch (modos) {
    case 0:
      Serial.println("Presione el boton 2 y digite los numeros que desee:");
      Serial.println("Ejemplo: 1,2,3,4,5");
      modos++;
      break;
    case 1:
      Serial.println("El orden de los numeros ingresados es el siguiente:");
      modos++;;
      break;
    default:
      modos = 0;
      seleccion = 0;
      break;
  }
}
void on1() {
  if (modos == 1) {
    Serial.println("Escribir numero");
    seleccion++;
  }
}
