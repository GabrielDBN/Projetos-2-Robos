
/*DECLARAÇÃO DE VARIAVEIS*/
#define MotorDireito_sentido1 27
#define MotorDireito_sentido2 14
#define MotorEsquerdo_sentido1 25
#define MotorEsquerdo_sentido2 26
#define MotorDireito_PWM 33
#define MotorEsquerdo_PWM 32  
// o comedor de cu nao perdoa ninguem vai comer seu cu e da sua mae tamebem, a rola dele parece um bambu eu tenho medo e do comedor de cu
#define veloc0 0
#define velocEsquerdo 120
#define velocDireito 120

#define Sensor_direita 16
#define Sensor_esquerda 17

#define Sensor_ultrassomTrig 19
#define Sensor_ultrassomEcho 18

int delays = 30;
int delayPara = 15;

int ultimoLido = 0;

bool direita, esquerda;

void setup() {
  delay(5000);
  Serial.begin(9600);
  pinMode(MotorDireito_sentido1, OUTPUT);
  pinMode(MotorDireito_sentido2, OUTPUT);
  pinMode(MotorEsquerdo_sentido1, OUTPUT);
  pinMode(MotorEsquerdo_sentido2, OUTPUT);
  pinMode(MotorDireito_PWM, OUTPUT);
  pinMode(MotorEsquerdo_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  pinMode(Sensor_ultrassomTrig, OUTPUT);
  pinMode(Sensor_ultrassomEcho, INPUT);
  analogWrite(MotorDireito_PWM, velocDireito);
  analogWrite(MotorEsquerdo_PWM, velocEsquerdo);
}

void loop() {

  /*
  //Leituras dos Sensores Infravermelhos
  sensorDireito = digitalRead(Sensor_direita);
  sensorEsquerdo = digitalRead(Sensor_esquerda);
  */

  //Leitura do sensor ultrassônico
  long duracao, distancia;
  digitalWrite(Sensor_ultrassomTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Sensor_ultrassomTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor_ultrassomTrig, LOW);
  duracao = pulseIn(Sensor_ultrassomEcho, HIGH);
  distancia = (duracao / 2) / 29.1;

  /*
    // Controle dos motores baseado nos sensores
  if (sensorEsquerdo == LOW && sensorDireito == LOW) {
    // Ambos os sensores detectam a linha - ajuste o movimento conforme necessário
    moverParaFrente();
  } else if (sensorEsquerdo == HIGH && sensorDireito == LOW) {
    // Apenas o sensor direito detecta a linha - ajuste o movimento conforme necessário
    virarEsquerda();
  } else if (sensorEsquerdo == LOW && sensorDireito == HIGH) {
    // Apenas o sensor esquerdo detecta a linha - ajuste o movimento conforme necessário
    virarDireita();
  } else {
    // Nenhum dos sensores detecta a linha - ajuste o movimento conforme necessário
    pararMotores();
  }
  */

  // Lógica de detecção do robô inimigo com base no sensor ultrassônico
  if (distancia < 20) {
    moverParaFrente();
  } else {
    pararMotores();
  }

  delay(100); // Ajuste o tempo de loop conforme necessário

}

void moverParaFrente() {
  digitalWrite(MotorDireito_sentido1, HIGH);
  digitalWrite(MotorDireito_sentido2, LOW);
  digitalWrite(MotorEsquerdo_sentido1, HIGH);
  digitalWrite(MotorEsquerdo_sentido2, LOW);
}

void virarDireita() {
  digitalWrite(MotorDireito_sentido1, HIGH);
  digitalWrite(MotorDireito_sentido2, LOW);
  digitalWrite(MotorEsquerdo_sentido1, LOW);
  digitalWrite(MotorEsquerdo_sentido2, HIGH);
}

void virarEsquerda() {
  digitalWrite(MotorDireito_sentido1, LOW);
  digitalWrite(MotorDireito_sentido2, HIGH);
  digitalWrite(MotorEsquerdo_sentido1, HIGH);
  digitalWrite(MotorEsquerdo_sentido2, LOW);
}

void pararMotores() {
  digitalWrite(MotorDireito_sentido1, LOW);
  digitalWrite(MotorDireito_sentido2, LOW);
  digitalWrite(MotorEsquerdo_sentido1, LOW);
  digitalWrite(MotorEsquerdo_sentido2, LOW);
}