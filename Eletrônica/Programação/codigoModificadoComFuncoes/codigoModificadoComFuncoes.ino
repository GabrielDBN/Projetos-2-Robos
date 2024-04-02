
/* DECLARAÇÃO DE VARIAVEIS */
#define MotorA_sentido1 19
#define MotorA_sentido2 18
#define MotorB_sentido1 32
#define MotorB_sentido2 33
#define MotorA_PWM 16
#define MotorB_PWM 13  

#define veloc0 0
#define veloc1 50
#define veloc2 120

#define Sensor_direita 15
#define Sensor_esquerda 25

int delays = 30;
int delayPara = 15;
int ultimoLido = 0;
bool direita, esquerda;
unsigned long millis1 = millis();

/* FUNÇÕES */
void inicializar() {
  delay(5000); // Aguarda 5 segundos após ligar o sistema
  Serial.begin(9600); // Inicia a comunicação serial
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  analogWrite(MotorA_PWM, veloc2); // Define a velocidade inicial dos motores
  analogWrite(MotorB_PWM, veloc2);
}

void moverParaFrente() {
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);
}

void pararMovimento() {
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, LOW);
  digitalWrite(MotorB_sentido1, LOW);
  digitalWrite(MotorB_sentido2, LOW);
}

void virarDireita() {
  ultimoLido = 1;
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, LOW);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);
}

void virarEsquerda() {
  ultimoLido = 2;
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, LOW);
  digitalWrite(MotorB_sentido2, LOW);
}

/* SETUP */
void setup() {
  inicializar();
}

/* LOOP PRINCIPAL */
void loop() {
  // Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);

  // Rodando os motores dependendo das leituras
  if (direita && esquerda) {
    if (ultimoLido == 0) {
      moverParaFrente();
      delay(delays);
    } else {
      moverParaFrente();
      delay(delays);
      pararMovimento();
      delay(delayPara);
    }
  } else if (direita && !esquerda) {
    virarDireita();
    delay(delays);
    pararMovimento();
    delay(delayPara);
  } else if (!direita && esquerda) {
    virarEsquerda();
    delay(delays);
    pararMovimento();
    delay(delayPara);
  } else if (!direita && !esquerda) {
    if (ultimoLido == 1) {
      virarDireita();
      delay(delays);
      pararMovimento();
      delay(delayPara);
    } else if (ultimoLido == 2) {
      virarEsquerda();
      delay(delays);
      pararMovimento();
      delay(delayPara);
    }
    // Adicione mais condições (ultimoLido == 3, 4, ...) se necessário
  }
}
