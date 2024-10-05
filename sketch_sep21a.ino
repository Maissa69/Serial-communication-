#define INA1 8
#define INA2 9
#define ENAA 3

#define INB1 10
#define INB2 11
#define ENAB 4

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
        String command = Serial.readStringUntil('\n'); 
        
        if (command == "Avancer") { 
            avancer(150);

        } else if (command == "Droite") { 
            droite();

        } else if (command == "Gauche") { 
            gauche(); 

        } else if (command == "Stope") { 
            stope();
        }
    }
}

void avancer(int vitesse) {
    digitalWrite(INA1, HIGH);
    digitalWrite(INB1, HIGH);
    digitalWrite(INA2, LOW);
    digitalWrite(INB2, LOW);
    analogWrite(ENAA, vitesse); 
    analogWrite(ENAB, vitesse); 
}

void droite() {
    digitalWrite(INA1, HIGH);
    digitalWrite(INB1, LOW);
    digitalWrite(INA2, LOW);
    digitalWrite(INB2, LOW);
}

void gauche() { 
    digitalWrite(INA1, LOW);
    digitalWrite(INB1, HIGH);
    digitalWrite(INA2, LOW);
    digitalWrite(INB2, LOW);
}

void stope() {
    digitalWrite(INA1, LOW);
    digitalWrite(INB1, LOW);
    digitalWrite(INA2, LOW);
    digitalWrite(INB2, LOW);
}
