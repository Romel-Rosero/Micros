/*    UNIVERSIDAD TÉCNICA DEL NORTE
 *          FICA - CIERCOM
 *      SISTEMAS MICROPROCESADOS
 *  Validación de la Cédula Ecuatoriana, la misma que tiene un formato, Ejemplo: 100310444-3 
 *  
 *  CONSIDERACIONES:
 *    - Se debe validar que tenga 10 numeros
 *    - Se extrae los dos primero digitos de la izquierda y se comprueba que existan las regiones
 *    - Se extrae el ultimo digito de la cedula
 *    - Extraer todos los pares y los sumo
 *    - Extraer los impares los multiplico x 2 si el numero resultante es mayor a 9 le restamos 9 al resultante
 *    - Extraer el primer Digito de la suma (sumaPares + sumaImpares)
 *    - Conseguimos la decena inmediata del digito extraido del paso 6 (digito + 1) * 10
 *    - Restamos la decena inmediata - suma / si la suma nos resulta 10, el decimo digito es cero
 *    - Comparamos el digito resultante con el ultimo digito de la cedula si son iguales
 */ 
String CI ;             //Cadena que almacena los datos de la cedula CI
String C1;             //D1,D2,D3,D4,D5,D6,D7,D8,D9,D10 son las variable que almacenan los digitos de la cedula
String C2 ;            
String C3 ;             
String C4 ;             
String C5 ;             
String C6 ;           
String C7 ;             
String C8 ;             
String C9 ;             
String guion ;          //Variable que almacena el guion de la cedula
String C10 ;            
int suma ;              //Variable que almacena los dos primero digitos de la cedula
int sumImp ;            //Variable que almacena los numeros en las posiciones impares de la cedula
int sumPares ;         //Variable que almacena los numeros en las posiciones pares de la cedula
int decena ;            //Variable que almacena las decenas de la suma de los dos primeros digitos de la cedula
int digito1;            //Variable que almacena el primer digito de la cedula 
int digito2;            //Variable que almacena el segundo digito de la cedula 
int digito3;            //Variable que almacena el tercerr digito de la cedula
int digito4;            //Variable que almacena el cuarto digito de la cedula
int digito5;            //Variable que almacena el quinto digito de la cedula
int digito6;            //Variable que almacena el sexto digito de la cedula
int digito7;            //Variable que almacena el septimo digito de la cedula
int digito8;            //Variable que almacena el octavo digito de la cedula
int digito9 ;           //Variable que almacena el noveno digito de la cedula 
int digito10;           //Variable que almacena el decimo digito de la cedula
int sumaValidacion ;    //Variable que almacena la suma de las posiciones pares e impares, y a su vez permite validar la cedula
int numeroValidador ;    //Variable que almacena el dato validador de la cedula
int Impar1 ; //Variable que almacena la primera posicion impar la de cedula
int Impar2 ;//Variable que almacena la segunda posicion impar la de cedula
int Impar3 ;//Variable que almacena la tercera posicion impar la de cedula
int Impar4 ;//Variable que almacena la cuarta posicion impar la de cedula
int Impar5 ;//Variable que almacena la quinta posicion impar la de cedula

void setup() {
  Serial.begin(9600);
  Serial.println ("Ingrese su numero de cedula con la siguiente estructura: 100310444-3") ;
}
void loop() {
  if (Serial.available () >0){
    CI=Serial.readString () ;
    while ((CI.length ()>11 || CI.length ()<11) && CI.charAt(9)!= ('-')){ //Parametros que debe tener la cedula ingresada 
      Serial.println ("Ingrese correctamente su numero de cedula con la siguiente estructura: 100310444-3") ;
      CI=Serial.readString () ;
      delay (3000) ;
    }
        Serial.println ("La cedula ingresada es: ") ;
    Serial.println (CI);    //Permite leer los datos ingresados en la Cadena CI
  
    
    digito1=(CI.substring(0,1)).toInt () ;      //Variable que almacena el primer digito de la cedula en tipo Int
    C2=CI.substring (1,2) ;                     //Variable que almacena el segundo digito de la cedula en tipo String
    digito2=C2.toInt () ;                       //Variable que almacena el segundo digito de la cedula en tipo Int
    C3=CI.substring (2,3) ;                     //Variable que almacena el tercer digito de la cedula en tipo String
    digito3=C3.toInt ();                        //Variable que almacena el Tercer digito de la cedula en tipo Int
    C4=CI.substring (3,4) ;                     //Variable que almacena el cuarto digito de la cedula en tipo String
    digito4=C4.toInt () ;                       //Variable que almacena el Cuarto digito de la cedula en tipo Int
    C5=CI.substring (4,5) ;                     //Variable que almacena el quinto digito de la cedula en tipo String
    digito5=C5.toInt () ;                       //Variable que almacena el Quinto digito de la cedula en tipo Int
    C6=CI.substring (5,6) ;                     //Variable que almacena el sexto digito de la cedula en tipo String
    digito6=C6.toInt () ;                       //Variable que almacena el Sexto digito de la cedula en tipo Int
    C7=CI.substring (6,7) ;                     //Variable que almacena el septimo digito de la cedula en tipo String
    digito7=C7.toInt () ;                       //Variable que almacena el Septimo digito de la cedula en tipo Int
    C8=CI.substring (7,8) ;                     //Variable que almacena el octavo digito de la cedula en tipo String
    digito8=C8.toInt () ;                       //Variable que almacena el Octavo digito de la cedula en tipo Int
    C9=CI.substring (8,9) ;                     //Variable que almacena el noveno digito de la cedula en tipo String
    digito9=C9.toInt () ;                       //Variable que almacena el noveo digito de la cedula en tipo Int
    C10=CI.substring(10,11) ;                   //Variable que almacena el decimo digito de la cedula en tipo String
    digito10=C10.toInt () ;                     //Variable que almacena el decimo digito de la cedula en tipo Int
    decena=digito1*10 ;                         //Extraccion de las decenas de la suma realiza entre los primeros digitos de la cedula
    suma= decena+digito2 ;                      //Suma de los dos primero digitos
    validacionDigito();
  }
}
void validacionDigito (){                       //Metodo que permite realizar las operaciones con los digitos de las posiciones pares e impares
  Impar1= 2*digito1 ;
  int numeroDecenas ;
  if (Impar1>9){
    Impar1=Impar1-9 ;
  }
  Impar2= 2*digito3 ;
   if (Impar2>9){
    Impar2=Impar2-9 ;
  }
  Impar3= 2*digito5 ;
   if (Impar3>9){
    Impar3=Impar3-9 ;
  }
  Impar4=2*digito7 ;
   if (Impar4>9){
    Impar4=Impar4-9 ;
  }
  Impar5=2*digito9 ;
   if (Impar5>9){
    Impar5=Impar5-9 ;
  }
  sumImp=Impar1 + Impar2 + Impar3+Impar4+Impar5 ;         //Suma de todas las posiciones impares
  sumPares = digito2+digito4 +digito6 + digito8 ;         //no se toma ninguna condicion para la sumtaria de las posiciones pares 
  sumaValidacion=sumImp+sumPares ;
  numeroDecenas=sumaValidacion/10 ;                     //Se realiza la sumatoria de las posiciones pares e impares. Si el resultado es 0, el numero validador será 0, pero si este diferente a cero se toma la unidad de la suma y este será el numero validador
  if (sumaValidacion/10 == 0){                          
    numeroValidador=0 ;
  } else{
    numeroValidador=10-(sumaValidacion % 10);           //Operacion para encontrar el numero validador cuando el modulo es diferente a 0
  }
  if (numeroValidador==digito10){                       //Finalmente, si el numero validador es igual al ultimo digito de la cedula, esta sera valida, caso contrario será una cedula incorrecta.
    Serial.println ("El numero validador coincide con el de su cedula") ;
    Serial.println ("La cedula es valida")  ;
  } else {
    Serial.println (" ");
    Serial.println ("El numero validador no coincide con el de su cedula") ;
    Serial.println ("Ingrese nuevamente su Numero de cedula") ;
  }
}
