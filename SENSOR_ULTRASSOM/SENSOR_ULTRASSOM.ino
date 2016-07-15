/***********************************************************************
 * Primeiro Workshop Arduino e Robotica - TARZAN
 * 
 * Programa de exemplo para a utilização do sensor ULTRASSOM
 * 
 * Autores: Gustavo Carlos
 *          Thobias Santos
 * 
***********************************************************************/


// Definindo o pinos de entrada e saída
#define echoPin 7
#define trigPin 6
#define LEDPin 13

long duration, cm;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop(){

  //sequencia de nível alto e baixo e gerar a frequência do sinal sonoro
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  //Faz a leitura do tempo do pulso no pino echo
  duration = pulseIn(echoPin, HIGH);

  //calcula a distancia
  cm = microsecondsToCentimeters(duration);

  //Envia valores para a serial
  Serial.print ("Milissegundos: ");
  Serial.print(duration);
  Serial.print(" Distancia estimada: ");
  Serial.print(cm); Serial.println(" cm");
  delay(1000);
}

long microsecondsToCentimeters(long microseconds){

  // A velocidade do som é 340 m/s
  // 29 microsegundos por centrimetro.
  // o Sinal vai e volta
  // a distancia é a metade da distancia percorrida
  return microseconds / 29 /2 ;
}
