import serial
import time

# Remplacez '/dev/ttyUSB0' par le port correct pour votre configuration
ser = serial.Serial('/dev/ttyUSB0', 9600)
time.sleep(2)  # Attendre que la connexion soit établie

ser.write(b'Avancer')  # Envoyer une commande pour avancer
#time.sleep(5)    # Attendre 5 secondes
ser.write(b'Droite')  # Envoyer une commande pour tourner a droite 
#time.sleep(5)
ser.write(b'S')
ser.close()  # Fermer la connexion série

