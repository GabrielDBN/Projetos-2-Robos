#define TRIGGER_PIN 9 // Define o pino do trigger
#define ECHO_PIN 10 // Define o pino do echo

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  pinMode(TRIGGER_PIN, OUTPUT); // Define o pino do trigger como saída
  pinMode(ECHO_PIN, INPUT); // Define o pino do echo como entrada
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH); // Lê o tempo do sinal de eco
  long distance = (duration/2) / 29.1; // Converte o tempo em distância

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm"); // Imprime a distância
  delay(100); // Aguarda 100 milissegundos
}