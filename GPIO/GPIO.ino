/***********************************************************************
 * Primeiro Workshop Arduino e Robotica - TARZAN
 * 
 * Programa inicial para a utilização do GPIO
 * 
 * Autores: Gustavo Carlos
 *          Thobias Santos
 * 
***********************************************************************/

void setup() {

  // inicializa o pino digital 13 como saída.
  pinMode(13, OUTPUT);

}

// A função loop roda infinitamente.
void loop() {

  digitalWrite(13, HIGH); // Deixa o pino de saída em nível alto

  delay(1000); // Espera por um Segundo

  digitalWrite(13, LOW); // Deixa o pino de saída em nível baixo

  delay(1000); // Espera por um Segundo
}
