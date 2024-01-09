#include <SharpIR.h>

const byte TRIGGER_PIN = A1; 
const byte ECHO_PIN = A2;    
 
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

// Vitesse du son dans l'air en mm/us //
const float SOUND_SPEED = 340.0 / 1000;


void setup() {
  
  Serial.begin(9600);

  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  mesureDistance();
  delay(1000);
}

// Fonction pour mesurer la distance //
void mesureDistance() {
  // 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER //
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(1000);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) //
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  // 3. Calcul la distance à partir du temps mesuré //
  float distance_m = measure / 2.0 * SOUND_SPEED;
   
  // Affiche les résultats en cm 
  Serial.print(F("Distance: "));
  Serial.print(distance_m / 10.0, 2);
  Serial.print(F("cm, "));
}