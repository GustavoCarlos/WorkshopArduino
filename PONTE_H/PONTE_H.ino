/***********************************************************************
 * Primeiro Workshop Arduino e Robotica - TARZAN
 * 
 * Programa inicial para a utilização da Ponte H
 * 
 * Autores: Gustavo Carlos
 *          Thobias Santos
 * 
***********************************************************************/

//Definições pinos do Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {

  //Define os pinos como saída
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  //Gira o Motor A no sentido horário
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(3000);
  
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(1000); 
  
  //Gira o Motor A no sentido anti-horário
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(3000);
  
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(1000);

}
