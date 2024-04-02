#include <analogWrite.h>

// --------------------------------------------------- DECLARATION TRASHSENSOR RELAY WITH SENSOR IR ----------------------------
//const int RELAY = 32;
const int trashsensor = 35;

// --------------------------------------------------- IF THERE IS AN OBSTACLE STOP USING THE ULTRASONIC SENSOR ----------------
int TRIG = 26; // membuat varibel trig yang di set ke-pin D6
int ECHO = 25; // membuat variabel echo yang di set ke-pin D7
long duration, distance;     // membuat variabel durasi dan jarak

// --------------------------------------------------- DECLARATION FRONT REAR MOTOR DC LEFT ------------------------------------
int frontleftmotorPin1 = 21;
int rearleftmotorPin2 = 22;
int enablePinA = 23;

// --------------------------------------------------- DECLARATION FRONT REAR MOTOR DC RIGHT -----------------------------------
int frontrightmotorPin1 = 18;
int rearrightmotorPin2 = 19;
int enablePinB = 5;

// --------------------------------------------------- DECLARATION SENSOR IR ---------------------------------------------------
int leftsensor1 = 27;
int leftsensor2 = 14;
int rightsensor1 = 13;
int rightsensor2 = 12;

// --------------------------------------------------- VOID SETUP --------------------------------------------------------------
void setup() {
  // linefollow:
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);
  
  pinMode(leftsensor1, INPUT);
  pinMode(leftsensor2, INPUT);
  pinMode(rightsensor1, INPUT);
  pinMode(rightsensor2, INPUT);
  
  pinMode(frontleftmotorPin1, OUTPUT);
  pinMode(rearleftmotorPin2, OUTPUT);
  pinMode(frontrightmotorPin1, OUTPUT);
  pinMode(rearrightmotorPin2, OUTPUT);

  // setup pin relay with sensor IR
  pinMode(trashsensor, INPUT);
  //pinMode(RELAY, OUTPUT);
  //digitalWrite(RELAY, HIGH);

  // setup pin sensor ultrasonik
  pinMode(TRIG, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(ECHO, INPUT);     // set pin echo menjadi

  Serial.begin(115200);
}

// --------------------------------------------------- VOID FUNCTION -----------------------------------------------------------
void maju (void) {
    digitalWrite(frontleftmotorPin1,LOW);
    digitalWrite(rearleftmotorPin2,HIGH);
    digitalWrite(frontrightmotorPin1,HIGH);
    digitalWrite(rearrightmotorPin2,LOW);
    analogWrite (enablePinA, 150);
    analogWrite (enablePinB, 150);
    //delay(2);
  }

void belokkanan (void) {
    digitalWrite(frontleftmotorPin1,LOW);
    digitalWrite(rearleftmotorPin2,HIGH);
    digitalWrite(frontrightmotorPin1,LOW);
    digitalWrite(rearrightmotorPin2,HIGH);
    analogWrite (enablePinA, 150);
    analogWrite (enablePinB, 150);
    //delay(2);
  }

void belokkiri (void) {
    digitalWrite(frontleftmotorPin1,HIGH);
    digitalWrite(rearleftmotorPin2,LOW);
    digitalWrite(frontrightmotorPin1,HIGH);
    digitalWrite(rearrightmotorPin2,LOW);
    analogWrite (enablePinA, 150);
    analogWrite (enablePinB, 150);
    //delay(2);
  }
  
void berhenti (void) {
    digitalWrite(frontleftmotorPin1,LOW);
    digitalWrite(rearleftmotorPin2,LOW);
    digitalWrite(frontrightmotorPin1,LOW);
    digitalWrite(rearrightmotorPin2,LOW);
    analogWrite (enablePinA, 0);
    analogWrite (enablePinB, 0);
  }

void linefollow (void) {
    int leftsensor1 = digitalRead(27); 
    int leftsensor2 = digitalRead(14);
    int rightsensor1 = digitalRead(13);
    int rightsensor2 = digitalRead(12);

    /*if (leftsensor1 == LOW && leftsensor2 == LOW && rightsensor1 == LOW && rightsensor2 == LOW) {
        maju ();
    }*/
    if (leftsensor1 == HIGH && leftsensor2 == LOW && rightsensor1 == LOW && rightsensor2 == LOW) {
        belokkiri ();
    }
    if (leftsensor1 == LOW && leftsensor2 == LOW && rightsensor1 == LOW && rightsensor2 == HIGH) {
        belokkanan ();
    }
    if (leftsensor1 == LOW && leftsensor2 == HIGH && rightsensor1 == LOW && rightsensor2 == LOW) {
        belokkiri ();
    }
    if (leftsensor1 == LOW && leftsensor2 == LOW && rightsensor1 == HIGH && rightsensor2 == LOW) {
        belokkanan ();
    }
    if (leftsensor1 == HIGH && leftsensor2 == HIGH && rightsensor1 == LOW && rightsensor2 == LOW) {
        belokkiri ();
    }
    if (leftsensor1 == LOW && leftsensor2 == LOW && rightsensor1 == HIGH && rightsensor2 == HIGH) {
        belokkanan ();
    }
    if (leftsensor1 == HIGH && leftsensor2 == HIGH && rightsensor1 == HIGH && rightsensor2 == HIGH) {
        berhenti ();

    }
}

void obstacleultrasonic (void) {
  //obstacle ultrasonik
  digitalWrite(TRIG, LOW);
  delayMicroseconds(4);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(4);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(4);
  duration = pulseIn(ECHO, HIGH); // menerima suara ultrasonic
  distance = (duration / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)
  if (distance < 18){
    berhenti ();
    //Serial.println("There Are Obstacle Ahead");
    delay(60);
  }
  else if (distance > 18) {
     linefollow ();
     //Serial.println("No Obstacle Ahead");
     delay(60);
  }

    /*Serial.print("Jarak Benda: ");
    Serial.print(distance);          // menampilkan jarak pada serial monitor
    Serial.println(" cm");
    delay(500);*/
}

void trashsensordetect (void) {
  int sensorState = digitalRead(trashsensor);
  if (sensorState == LOW) {
    maju ();
    /*digitalWrite(RELAY, LOW);
    Serial.println("Full Trash");*/
    //delay(60);
  }
   else {
    linefollow ();
    /*digitalWrite(RELAY, HIGH);
    Serial.println("Trash Not Full");*/
    delay(60);
   }
}

// --------------------------------------------------- VOID LOOP ---------------------------------------------------------------
void loop() {
    //line follow
    linefollow ();

    //obstacle ultrasonic
    obstacleultrasonic ();

    //trashsensor
    trashsensordetect ();
}