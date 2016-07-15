/***********************************************************************
 * Primeiro Workshop Arduino e Robotica - TARZAN
 * 
 * Programa de exemplo para a utilização do conversor AD
 * 
 * Autores: Gustavo Carlos
 *          Thobias Santos
 * 
***********************************************************************/

int analogPin = 3; // Terminal do meio do potenciômetro ligado ao analógico 3
int val = 0; // Variável para armazenar o valor lido

void setup(){

  Serial.begin(9600); // Configura a porta serial

}

void loop(){

  val = analogRead(analogPin); // Lê o valor do AD no pino de entrada

  Serial.println(val); // Envia valor lido para a serial

}
