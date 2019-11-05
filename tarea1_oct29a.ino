////EJERCICIO 5
int i=0;
int j=0;
int cont [6]= {8,9,10,11,12,13};
void setup() {
    for(i=0;i<6;i++){
    pinMode(cont[i],OUTPUT);
    }
    }
void loop() {
      for(i=0;i<61;i++){
        for(j=0;j<7;j++){
        if(((2*i>>j)& 1 ) == 1) {
        digitalWrite (cont[j],HIGH);
        }
        else digitalWrite (cont [j], LOW);
        }
     delay (700);
  }
}
