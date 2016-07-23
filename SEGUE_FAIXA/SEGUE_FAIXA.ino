/***********************************************************************
 * Primeiro Workshop Arduino e Robotica - TARZAN
 * 
 * Programa que permite o robô seguir faixas e parar na presença de obstáculos
 * 
 * Autores: Gustavo Carlos
 *          Thobias Santos
 * 
***********************************************************************/


//Definição dos pinos utilizados para o funcionamento do sensor ultrassonico
#define TRIG_PIN  6
#define ECHO_PIN  7

//Definição dos pinos utilizados para a leitura dos sensores IR
#define IR1_AN_PIN  A0
#define IR2_AN_PIN  A1

//Definição dos pinos para controle dos motores
#define EN1 8
#define EN2 9
#define EN3 10
#define EN4 11

//Definicao de valores de sensibilidade dos sensores IR
#define SENS_IR1_PRETO  240// 240valor medio no preto
#define SENS_IR2_PRETO  350//110 valor medio preto

//Definicao dos valores para controle do motor
#define VEL_P_MOTOR1  190
#define VEL_P_MOTOR2  210


//Definição de variaveis para armazenamento de dados
int val_sensorIR1 = 0; //armazena valor lido do canal analogico no sensor IR 1
int val_sensorIR2 = 0; //armazena valor lido do canal analogico no sensor IR 2

int distancia = 0; //armazena o valor da distancia lido pelo ultrassom


//Função setup, será executada apenas na inicialização 
void setup() {

   //Inicializacao da serial para depuracao
  Serial.begin(9600);

  //Inicializacao dos pinos do ultrassom
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  //Inicializacao dos pinos para controle do motor
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);

  //delay para manuseio inicial
  delay(3000);


  //Como o robô so ira para frente, fixamos em nivel logico 1 os pinos EN1 e EN3
  digitalWrite(EN1, HIGH);
  digitalWrite(EN3, HIGH);
  //Coloca nivel auto em EN2 e EN4 para que os motores iniciem parados
  digitalWrite(EN2, HIGH);
  digitalWrite(EN4, HIGH);
 
}

void loop() {
  
  //Realiza a medida de distancia no sensor ultrassonico
  distancia = medeDistancia();

  if(distancia < 15){//Se distancia é menor que 15 cm, tem algo a frente
    //Coloca as saidas EN2 e EN4 em 1 para parar os motores
    analogWrite(EN2,255);
    analogWrite(EN4,255);
  }
  else{//Caso contrario, executa-se a rotina de seguir a faixa

    //Realiza a leitura dos sensores IR
    val_sensorIR1 = analogRead(IR1_AN_PIN); //sensor esquerdo
    val_sensorIR2 = analogRead(IR2_AN_PIN); //sensor direito
   /* 
    *  Bloco para depuracao dos valores dos sensores infra-vermelho
    Serial.println("SensorIR1");
    Serial.println(val_sensorIR1);
    Serial.println("SensorIR2");
    Serial.println(val_sensorIR2);*/
    
    if(val_sensorIR1 < SENS_IR1_PRETO){ //sensor da esquerda detecta preto
      analogWrite(EN2,VEL_P_MOTOR2); //gira motor direito
      analogWrite(EN4,255); //para motor esquerdo
    }
    else if(val_sensorIR2 < SENS_IR2_PRETO){//sensor da direita detecta preto
      analogWrite(EN2,255); //para motor direito
      analogWrite(EN4,VEL_P_MOTOR1); //gira motor esquerdo
    }
    else{
      analogWrite(EN4,VEL_P_MOTOR1); //motor esquerdo 
      analogWrite(EN2,VEL_P_MOTOR2); //motor direito

    }
    
  }

}

//Funcao utilizada para a realizacao de medidas utilizando o sensor ultrassonico
int medeDistancia(){

  //Rotina para a geracao do pulso de TRIG no ultrassom
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, LOW);
  //Verifica o tamanho do pulso recebido no pino ECHO
  long duracao = pulseIn(ECHO_PIN, HIGH);

  //Conversao para distancia em cm
  int dist = duracao /29/2;
  
  return dist;
}
