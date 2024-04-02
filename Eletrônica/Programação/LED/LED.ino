#define SENSOR_ESQUERDA 15 // Pino do sensor esquerdo
#define SENSOR_CENTRO 25 // Pino do sensor central
#define SENSOR_DIREITA 33 // Pino do sensor direito
#define MOTOR1_SENTIDO_A 19 // Pino do Motor1 frente
#define MOTOR1_SENTIDO_B 18 // Pino do Motor1 tras
#define MOTOR2_SENTIDO_A 16 // Pino do Motor2 Frente
#define MOTOR2_SENTIDO_B 4 // Pino do Motor2 tras
#define Motor1_PWM 23 // Pino do PWM1
#define Motor2_PWM 21 // Pino do PWM2
#define velocidade0 0
#define velocidade1 110
#define velocidade2 150

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_ESQUERDA, INPUT);
  pinMode(SENSOR_CENTRO, INPUT);
  pinMode(SENSOR_DIREITA, INPUT);
  pinMode(MOTOR1_SENTIDO_A, OUTPUT);
  pinMode(MOTOR1_SENTIDO_B, OUTPUT);
  pinMode(MOTOR2_SENTIDO_A, OUTPUT);
  pinMode(MOTOR2_SENTIDO_B, OUTPUT);
  analogWrite(Motor1_PWM, velocidade1);
  analogWrite(Motor2_PWM, velocidade1);
}

void loop() {
  int leituraSensorEsquerda = digitalRead(SENSOR_ESQUERDA);
  int leituraSensorCentro = digitalRead(SENSOR_CENTRO);
  int leituraSensorDireita = digitalRead(SENSOR_DIREITA);

  if (leituraSensorEsquerda == LOW && leituraSensorDireita == LOW) {
    // Ambos os sensores estão fora da linha, siga em frente
    digitalWrite(MOTOR1_SENTIDO_A, HIGH);
    digitalWrite(MOTOR2_SENTIDO_A, HIGH);
  } else if (leituraSensorEsquerda == HIGH && leituraSensorDireita == LOW) {
    // O sensor esquerdo está na linha, vire à direita
    digitalWrite(MOTOR2_SENTIDO_A, HIGH);
    digitalWrite(MOTOR1_SENTIDO_A, LOW);
  } else if (leituraSensorEsquerda == LOW && leituraSensorDireita == HIGH) {
    // O sensor direito está na linha, vire à esquerda
    digitalWrite(MOTOR2_SENTIDO_A, LOW);
    digitalWrite(MOTOR1_SENTIDO_A, HIGH);
  } else {
    // Ambos os sensores estão na linha ou algo deu errado, pare
    digitalWrite(MOTOR1_SENTIDO_A, LOW);
    digitalWrite(MOTOR2_SENTIDO_A, LOW);
  }
}
