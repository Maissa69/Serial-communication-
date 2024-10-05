#define INA1 8
#define INA2 9
#define ENAA 3
#define INB1 10
#define INB2 11
#define ENAB 2

void setup() {
    Serial.begin(9600); // Initialiser la communication série
    pinMode(INA1, OUTPUT);
    pinMode(INA2, OUTPUT);
    pinMode(ENAA, OUTPUT);

    pinMode(INB1, OUTPUT);
    pinMode(INB2, OUTPUT);
    pinMode(ENAB, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        char command = Serial.read();
        
        if (command == 'F') { // Avancer
            digitalWrite(INA1, HIGH);
            digitalWrite(INA2, LOW);
            analogWrite(ENAA, 150); // Vitesse maximale

            digitalWrite(INB1, HIGH);
            digitalWrite(INB2, LOW);
            analogWrite(ENAB, 150); // Vitesse maximale
            
        } else if (command == 'B') { // Reculer
            digitalWrite(INA1, LOW);
            digitalWrite(INA2, HIGH);
            analogWrite(ENAA, 150); // Vitesse maximale

            digitalWrite(INB1, LOW);
            digitalWrite(INB2, HIGH);
            analogWrite(ENAB, 150); // Vitesse maximale
            
        } else if (command == 'L') { // Tourner à gauche
            digitalWrite(INA1, LOW);   // Arrêter le moteur A
            digitalWrite(INA2, LOW);   // Arrêter le moteur A
            digitalWrite(INB1, LOW);   // Activer le moteur B
            digitalWrite(INB2, HIGH);    // Activer le moteur B
            analogWrite(ENAB, 150);     // Vitesse du moteur B
            
        } else if (command == 'R') { // Tourner à droite
            digitalWrite(INB1, LOW);   // Arrêter le moteur B
            digitalWrite(INB2, LOW);   // Arrêter le moteur B
            digitalWrite(INA1, LOW);   // Activer le moteur A
            digitalWrite(INA2, HIGH);    // Activer le moteur A
            analogWrite(ENAA, 150);     // Vitesse du moteur A
            
        } else if (command == 'S') { // Stopper
            digitalWrite(INA1, LOW);
            digitalWrite(INA2, LOW);

            digitalWrite(INB1, LOW);
            digitalWrite(INB2, LOW);
        }
    }
}
