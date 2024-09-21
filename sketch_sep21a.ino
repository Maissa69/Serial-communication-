#define IN1 9
#define IN2 10
#define ENA 11

void setup() {
    Serial.begin(9600); // Initialiser la communication série
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        char command = Serial.read();
        if (command == 'F') { // Avancer
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, 150); // Vitesse maximale
        } else if (command == 'B') { // Reculer
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            analogWrite(ENA, 150); // Vitesse maximale
        } else if (command == 'S') { // Stopper
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
        }
    }
}
