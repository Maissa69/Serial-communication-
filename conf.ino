#define INA1 8
#define INA2 9
#define ENAA 3
#define INB1 10
#define INB2 11
#define ENAB 2

void setup()
{
    Serial.begin(9600); // Initialiser la communication série
    pinMode(INA1, OUTPUT);
    pinMode(INA2, OUTPUT);
    pinMode(ENAA, OUTPUT);
    pinMode(INB1, OUTPUT);
    pinMode(INB2, OUTPUT);
    pinMode(ENAB, OUTPUT);
}

void loop()
{
    if (Serial.available()) {
        char command = Serial.read();

        if (command == 'F') { // Avancer
            moveForward();
        } else if (command == 'B') { // Reculer
            moveBackward();
        } else if (command == 'L') { // Tourner à gauche
            turnLeft();
        } else if (command == 'R') { // Tourner à droite
            turnRight();
        } else if (command == 'S') { // Stopper
            moveStop();
        }
    }
}

void moveStop()
{
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, LOW);
    digitalWrite(INB1, LOW);
    digitalWrite(INB2, LOW);
}

void moveForward()
{
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, LOW);
    digitalWrite(INB1, HIGH);
    digitalWrite(INB2, LOW);

    analogWrite(ENAA, 150); // Vitesse du moteur A
    analogWrite(ENAB, 150);  // Vitesse du moteur B
}

void moveBackward()
{
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);
    digitalWrite(INB1, LOW);
    digitalWrite(INB2, HIGH);

    analogWrite(ENAA, 150); // Vitesse du moteur A
    analogWrite(ENAB, 150);  // Vitesse du moteur B
}

void turnRight()
{
    digitalWrite(INA1, HIGH);  // Moteur A avance
    digitalWrite(INA2, LOW);
    
    digitalWrite(INB1, LOW);   // Moteur B recule
    digitalWrite(INB2, HIGH);

    analogWrite(ENAA, 150); // Vitesse du moteur A
    analogWrite(ENAB, 150);  // Vitesse du moteur B

    //delay(500); // Ajustez le délai selon vos besoins

    //moveStop(); // Arrêter après la rotation
}

void turnLeft()
{
    digitalWrite(INA1, LOW);   // Moteur A recule
    digitalWrite(INA2, HIGH);
    
    digitalWrite(INB1, HIGH);  // Moteur B avance
    digitalWrite(INB2, LOW);

    analogWrite(ENAA, 150); // Vitesse du moteur A
    analogWrite(ENAB, 150);  // Vitesse du moteur B

    //delay(500); // Ajustez le délai selon vos besoins

    //moveStop(); // Arrêter après la rotation
}
