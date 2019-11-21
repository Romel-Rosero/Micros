/*
   Universidad Tecnica del norte
          FICA-CIERCOM
    Integrantes:
        Almeida Axel
        Macas Christofer
         Rosero Romel
                Laboratorio 2
      Utilice como sensores de presencia a dos fotoceldas configuradas como entradas digitales.
      Si la fotocelda detecta negro envía una señal de 5 voltios, caso contario envía cero voltios.
      Realice un contador de ingreso y salida de personas al usar dos fotoceldas en su sencuencia de
      activación para detectar si la persona entra o sale.
      El contador debe ser hasta 50 visto en displays
      Si el sistema detecta ingreso, aumenta el contador y enciende un led de confirmación.
      Si se detecta que la persona sale, decrementa la cuenta y se enciende otro led de confirmación.
      Consulte sobre el uso de diagramas de flujo y bloques para representar el sistema y su funcionamiento.
      El informe no puede superar las 3 hojas, de preferencia imprima a ambos lados
*/
int f1 = 10;  //Fotoceldas
int f2 = 11;
int A = 2;   //Variables para el display
int B = 3;
int C = 4;
int D = 5;
int uni = 8; //Variables para encender el display
int dec = 9;
int uniS;
int decS;
int i = 0;   //Variable del contador
int cont = 0;
int j;
int led = 6; //Led de confirmacion
int led2 = 7;

void setup() {
  Serial.begin(9600); //Iniciamos la cominacion serial a 9600
  pinMode(A, OUTPUT); //Declaramos la variables de salida del display
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(uni, OUTPUT);
  pinMode(dec, OUTPUT);
  pinMode(f1, INPUT); //Declaramos las varables de las fotoceldas como entrada
  pinMode(f2, INPUT);
  Serial.print("Sistema on");
}

void loop() {
  if (digitalRead(f1) == HIGH && digitalRead(f2) == LOW) {
    delay(350);
    if(i<50){
    i = i + 1;
    digitalWrite(led, HIGH);
    delay(400);
    digitalWrite(led, LOW);
    Serial.println(i);
    
    }else{
      i=50;
    }
  }
  if (digitalRead(f1) == LOW && digitalRead(f2) == HIGH) {
    delay(350);
    if (i <= 0 ) {
      i = 0;
    } else {
      i = i - 1;
    }
    Serial.println(i);
    digitalWrite(led2, HIGH);
    delay(400);
    digitalWrite(led2, LOW);

  }
    if (digitalRead(f1) == HIGH && digitalRead(f2) == HIGH) {
   
   digitalWrite(led2, LOW);
    delay(400);
    digitalWrite(led2, LOW);

  }
  encendido();
}


void disp (int dato) {
  switch (dato) {
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }
}

void encendido() {
  decS = i / 10;
  if (i < 10) {
    uniS = i;
  } else {
    uniS = i - (decS * 10);
  }
  digitalWrite(dec, HIGH);
  digitalWrite(uni, LOW);
  disp(decS);
  delay(150);
  digitalWrite(dec, LOW);
  digitalWrite(uni, HIGH);
  disp(uniS);
  delay(150);
}
