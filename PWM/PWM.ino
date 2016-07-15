/***********************************************************************
 * Primeiro Workshop Arduino e Robotica - TARZAN
 * 
 * Programa de exemplo para a utilização do sinal PWM
 * 
 * Autores: Gustavo Carlos
 *          Thobias Santos
 * 
***********************************************************************/

int Ledpin=9; // Pino para a conexão do LED
int analogpin=A0; // Canal analógico que será lido
int value=0; // Variável para armazenar o valor lido do AD
int x; // Variável que indicara o valor do duty cycle PWM

void setup() {
  pinMode(Ledpin, OUTPUT); // coloca pino do Led como saída
}

void loop() {
  
  value=analogRead(analogpin); // realiza a leitura do AD

  x=map(value,0,1023,0,255); // realiza a conversão do AD para PWM

  analogWrite(Ledpin,x); // atualiza duty cycle no pino do LED

  delay(100); // aguarda 100 milissegundos

}
