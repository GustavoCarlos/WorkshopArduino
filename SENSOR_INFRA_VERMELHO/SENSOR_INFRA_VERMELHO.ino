/***********************************************************************
 * Primeiro Workshop Arduino e Robotica - TARZAN
 * 
 * Programa inicial para a utilização do sensor Infra vermelho
 * 
 * Autores: Gustavo Carlos
 *          Thobias Santos
 * 
***********************************************************************/

int sensor; //Declarando a variável para armazenar valores do AD
int Led = 13; //Declarando a variável para o led no pino 13


void setup() {

  Serial.begin(9600); // Inicializa comunicação serial a 9600 bits por segundo

  pinMode(Led, OUTPUT); // Configurando o led como saída

}


void loop() {

  sensor= analogRead(A0); //Realiza a leitura do AD no canal A0

  if(sensor<500){ //Se o valor da leitura do pino A0 for menor que 500

    digitalWrite(Led,HIGH); //acende o Led

  }
  else{ //Caso contrario

    digitalWrite(Led,LOW); //apaga o Led

  }
}
