//Motor Direito 
#define MotorDireito_Tras 16 // Pino do Motor esquerdo Frente
#define MotorDireito_Frente 4 // Pino do Motor2 
#define VelDir 22 // Pino do PWM1

//Motor Esquerdo
#define MotorEsquerdo_Tras 19 // Pino do Motor Direito frente
#define MotorEsquerdo_Frente 5 // Pino do Motor Esquerdo tras
#define VelEsq 23 // Pino do PWM1

// Sensores
#define Sensor_Esquerda 33 // Pino do sensor esquerdo
#define Sensor_Centro 15 // Pino do sensor central
#define Sensor_Direita 25 // Pino do sensor direito


#define velocidade0 0
#define velEsquerda 110
#define velDireito 255

void setup() {

  Serial.begin(9600);

  pinMode(Sensor_Esquerda, INPUT);
  pinMode(Sensor_Centro, INPUT);
  pinMode(Sensor_Direita, INPUT);
  pinMode(MotorEsquerdo_Frente, OUTPUT);
  pinMode(MotorEsquerdo_Tras, OUTPUT);
  pinMode(MotorDireito_Frente, OUTPUT);
  pinMode(MotorDireito_Tras, OUTPUT);
  pinMode(VelEsq, OUTPUT);
  analogWrite(VelEsq, velEsquerda);
  pinMode(VelDir, OUTPUT);
  analogWrite(VelDir, velEsquerda);

  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  
  delay(100);

}

void loop() {
  int esquerda = digitalRead(Sensor_Esquerda);
  int centro = digitalRead(Sensor_Centro);
  int direita = digitalRead(Sensor_Direita);

if (esquerda == true && centro == false && direita == false) {
  Serial.println("Sensor Esquerda: Preto, Sensor Centro: Branco, Sensor Direita: Branco - Virar Esquerda");

  digitalWrite(MotorEsquerdo_Frente, HIGH);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  delay(30);

  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(15);

} else if (esquerda == true && centro == true && direita == false) {
  Serial.println("Sensor Esquerda: Preto, Sensor Centro: Preto, Sensor Direita: Branco - Virar Esquerda");

  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  digitalWrite(MotorDireito_Frente, HIGH);
  digitalWrite(MotorDireito_Tras, LOW);

  delay(30);

  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(15);

} else if (esquerda == false && centro == true && direita == false) {
  Serial.println("Sensor Esquerda: Branco, Sensor Centro: Preto, Sensor Direita: Branco - Avançar");

  digitalWrite(MotorDireito_Frente, HIGH);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, HIGH);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(30);

  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(15);

} else if (esquerda == false && centro == true && direita == true) {
  Serial.println("Sensor Esquerda: Branco, Sensor Centro: Preto, Sensor Direita: Preto - Virar Direita");
  
  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, HIGH);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(30);
  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(15);
} else if (esquerda == false && centro == false && direita == true) {
  Serial.println("Sensor Esquerda: Branco, Sensor Centro: Branco, Sensor Direita: Preto - Virar Direita");

  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, HIGH);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(30);
  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(15);
} else if (esquerda == false && centro == false && direita == false) {
  Serial.println("Sensor Esquerda: Branco, Sensor Centro: Branco, Sensor Direita: Branco - Parar");
  
  while((direita =! true || centro != true)){

  digitalWrite(MotorDireito_Frente, HIGH);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(30);
  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(15);
  }
  while(esquerda =! true || centro != true){
  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, HIGH);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(30);

  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(15);

  }

} else if (esquerda == true && centro == true && direita == true) {
  Serial.println("Sensor Esquerda: Preto, Sensor Centro: Preto, Sensor Direita: Preto - Parar");
  
  digitalWrite(MotorDireito_Frente, HIGH);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, HIGH);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(30);
  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(15);
}

}

void avancar(){

  digitalWrite(MotorDireito_Frente, HIGH);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, HIGH);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(20);

}

void virarDireita(){

  digitalWrite(MotorEsquerdo_Frente, HIGH);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  delay(20);

}

void virarEsquerda(){

  digitalWrite(MotorDireito_Frente, HIGH);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(20);

}

void parar(){

  digitalWrite(MotorDireito_Frente, LOW);
  digitalWrite(MotorDireito_Tras, LOW);
  digitalWrite(MotorEsquerdo_Frente, LOW);
  digitalWrite(MotorEsquerdo_Tras, LOW);
  delay(20);

}