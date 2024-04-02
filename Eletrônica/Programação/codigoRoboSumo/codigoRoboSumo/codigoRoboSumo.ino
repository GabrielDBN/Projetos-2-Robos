// Robo sumo V2

/* DECLARAÇÃO DE PINOS */
#define MotorDireito_sentido1 27
#define MotorDireito_sentido2 14
#define MotorEsquerdo_sentido1 25
#define MotorEsquerdo_sentido2 26
#define MotorDireito_PWM 33
#define MotorEsquerdo_PWM 32  
#define Sensor_direita 16
#define Sensor_esquerda 17
#define Sensor_ultrassomTrig 19
#define Sensor_ultrassomEcho 18

/* CONSTANTES */
#define DISTANCIA_INIMIGO 30  // Distância para considerar um inimigo (ajuste conforme necessário)
#define TEMPO_MAXIMO_GIRO 50000  // Tempo máximo de giro em milissegundos (50 segundos)

unsigned long tempoInicioGiro = 0;  // Variável para armazenar o início do giro

void moveFrente() {
  digitalWrite(MotorDireito_sentido1, HIGH);
  digitalWrite(MotorDireito_sentido2, LOW);
  analogWrite(MotorDireito_PWM, 150);

  digitalWrite(MotorEsquerdo_sentido1, HIGH);
  digitalWrite(MotorEsquerdo_sentido2, LOW);
  analogWrite(MotorEsquerdo_PWM, 150);
}

void moveGirar() {
  digitalWrite(MotorDireito_sentido1, HIGH);
  digitalWrite(MotorDireito_sentido2, LOW);
  analogWrite(MotorDireito_PWM, 73);

  digitalWrite(MotorEsquerdo_sentido1, LOW);
  digitalWrite(MotorEsquerdo_sentido2, HIGH);
  analogWrite(MotorEsquerdo_PWM, 73);
}

void parar() {
  digitalWrite(MotorDireito_sentido1, LOW);
  digitalWrite(MotorDireito_sentido2, LOW);
  analogWrite(MotorDireito_PWM, 0);

  digitalWrite(MotorEsquerdo_sentido1, LOW);
  digitalWrite(MotorEsquerdo_sentido2, LOW);
  analogWrite(MotorEsquerdo_PWM, 0);
}

int medirDistancia() {
  digitalWrite(Sensor_ultrassomTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Sensor_ultrassomTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor_ultrassomTrig, LOW);

  return pulseIn(Sensor_ultrassomEcho, HIGH) / 58.0; // Converte o tempo de retorno em centímetros
}

// Função para verificar se a linha branca foi detectada pelos dois sensores
bool linhaBrancaDetectada() {
  // Lógica de detecção da linha branca com os dois sensores
  // Substitua a lógica abaixo com a lógica específica para seus sensores
  return (digitalRead(Sensor_esquerda) == HIGH && digitalRead(Sensor_direita) == HIGH);
}

void setup() {
  Serial.begin(115200);           // Inicia a comunicação serial
  Serial.println("Controle do Robô com Detecção de Inimigos e Bordas!");

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
}

void avancarPorCentimetros(int centimetros) {
  moveFrente(); // Inicia o movimento para frente
  delay(centimetros * 10); // Delay proporcional ao número de centímetros a percorrer
  parar(); // Para o movimento
}

void loop() {
  int sensorDireita = digitalRead(Sensor_direita);
  int sensorEsquerda = digitalRead(Sensor_esquerda);

  if (sensorDireita == HIGH && sensorEsquerda == HIGH) {

    // Etapa inicial: avançar alguns centímetros
    avancarPorCentimetros(1); // Ajuste o número de centímetros conforme necessário

    // Lógica para detecção de inimigos após avançar
    while (true) {
      int distancia = medirDistancia();  // Mede a distância em centímetros

      Serial.print("Distância: ");
      Serial.print(distancia);
      Serial.println(" cm");

      // Lógica para detecção de inimigos
      if (distancia <= DISTANCIA_INIMIGO) {
        Serial.println("Inimigo detectado! Movendo imediatamente em direção a ele.");
        parar(); // Para o movimento antes de seguir em direção ao inimigo
        moveFrente();
        delay(1000);  // Move em direção ao inimigo por 1 segundo
        parar(); // Para o movimento após avançar
        break; // Sai do loop após detectar e seguir em direção ao inimigo
      } else {
        // Lógica para girar até encontrar um inimigo
        Serial.println("Girando até encontrar um inimigo.");

        // Se não começou a girar, registra o início do giro
        if (tempoInicioGiro == 0) {
          tempoInicioGiro = millis();
        }

        // Se o tempo de giro atingir o limite, avança mais 10 centímetros
        if (millis() - tempoInicioGiro >= TEMPO_MAXIMO_GIRO) {
          Serial.println("Tempo máximo de giro atingido. Avançando mais 10 centímetros.");
          parar(); // Para o movimento antes de avançar
          avancarPorCentimetros(5);
          break; // Sai do loop após avançar
        }

        moveGirar();
      }
    }

  } else {
    Serial.println("Sensores não detectam linha branca. Interrompendo ação.");
    parar(); // Para qualquer ação caso os sensores não estejam detectando uma linha branca
  }

  tempoInicioGiro = 0; // Reseta o tempo de início do giro para a próxima iteração

  delay(1000);  // Aguarda 1 segundo antes de começar a próxima iteração
}