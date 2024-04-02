
/*DECLARAÇÃO DE VARIAVEIS*/
#define MotorA_sentido1 19
#define MotorA_sentido2 18
#define MotorB_sentido1 32
#define MotorB_sentido2 33
#define MotorA_PWM 16
#define MotorB_PWM 13  

#define veloc0 0
#define veloc1 50
#define veloc2 100

#define Sensor_direita 14
#define Sensor_esquerda 25

int delays = 20;
int delayPara = 10;

int ultimoLido = 0;

bool direita, esquerda;
unsigned long millis1 = millis();


void setup() {
  delay(5000);
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  analogWrite(MotorA_PWM, veloc2);
  analogWrite(MotorB_PWM, veloc2);
}

void loop() {
   //Define o sentido de rotação dos motores
  
  
  //Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);

  //Rodando os motores dependendo das leituras
 if(direita == true && esquerda == true){

  if(ultimoLido == 0) {
    //delay(5000);
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, HIGH);
    digitalWrite(MotorB_sentido1, HIGH);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delays);
    
  } else {
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, HIGH);
    digitalWrite(MotorB_sentido1, HIGH);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delays);
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, LOW);
    digitalWrite(MotorB_sentido1, LOW);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delayPara);
  }
 } else if(direita == true && esquerda == false){
 
  ultimoLido = 1;
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, LOW);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);
  delay(delays);
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, LOW);
  digitalWrite(MotorB_sentido1, LOW);
  digitalWrite(MotorB_sentido2, LOW);
  delay(delayPara);
  
  
 }else if(direita == false && esquerda == true){
  ultimoLido = 2;
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, LOW);
  digitalWrite(MotorB_sentido2, LOW);
  delay(delays);
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, LOW);
  digitalWrite(MotorB_sentido1, LOW);
  digitalWrite(MotorB_sentido2, LOW);
  delay(delayPara);
  
  
 
 }else if(direita == false && esquerda == false){
  
  if(ultimoLido == 1){
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, LOW);
    digitalWrite(MotorB_sentido1, HIGH);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delays);
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, LOW);
    digitalWrite(MotorB_sentido1, LOW);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delayPara);
  
  }
  if(ultimoLido == 2) {
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, HIGH);
    digitalWrite(MotorB_sentido1, LOW);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delays);
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, LOW);
    digitalWrite(MotorB_sentido1, LOW);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delayPara);
  
  }
  if(ultimoLido == 3 ){
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, HIGH);
    digitalWrite(MotorB_sentido1, LOW);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delays);
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, LOW);
    digitalWrite(MotorB_sentido1, LOW);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delayPara);
    
  }
  if(ultimoLido == 0) {
    digitalWrite(MotorA_sentido1, LOW);
    digitalWrite(MotorA_sentido2, HIGH);
    digitalWrite(MotorB_sentido1, HIGH);
    digitalWrite(MotorB_sentido2, LOW);
    delay(delays);
    
  }
  
 }
}