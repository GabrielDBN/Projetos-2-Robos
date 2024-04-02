// Define os pinos dos sensores
const int sensor1Pin = 14; // Pino do sensor 1 // azul  // direita  
const int sensor2Pin = 25; // Pino do sensor 2 // verde // esquerda

// Define um limiar para distinguir entre preto e branco
const int limiar = 500; // Ajuste este valor conforme necessário

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lê os valores dos sensores
  int sensor1Value = analogRead(sensor1Pin);
  int sensor2Value = analogRead(sensor2Pin);

  // Converte os valores para 0 ou 1 usando o limiar
  int sensor1Binary = (sensor1Value > limiar) ? 1 : 0;
  int sensor2Binary = (sensor2Value > limiar) ? 1 : 0;

  // Exibe os valores binários no monitor serial
  Serial.print("Sensor 1: ");
  Serial.print(sensor1Binary);
  Serial.print("\tSensor 2: ");
  Serial.println(sensor2Binary);

  // Aguarda um curto período de tempo
  delay(100);
}
