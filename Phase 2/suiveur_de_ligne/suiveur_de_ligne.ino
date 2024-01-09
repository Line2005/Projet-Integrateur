#include <Grove_I2C_Motor_Driver.h>
#include <Wire.h>
// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f
int motorPin1 = 5; // Broche de contrôle du moteur 1
int motorPin2 = 6; // Broche de contrôle du moteur 2
int motorPin3 = 10; // Broche de contrôle du moteur 3
int motorPin4 = 11; // Broche de contrôle du moteur 4

int capteurC= 7 ;
int capteurG= 2 ;
int capteurD= 8 ;
char stat1 ,stat2;

void setup(){
  Serial.begin(9600);
  //Motor.begin(I2C_ADDRESS);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
 
}
void Aleatoire(){

  stat1 = random(HIGH,LOW);
  stat2 = random(HIGH,LOW);

  digitalWrite(5,LOW);
  digitalWrite(6,stat1);
  digitalWrite(10,stat2);
  digitalWrite(11,LOW);

  analogWrite(3, 75);
  analogWrite(9, 75);
  }

void d()
{

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  analogWrite(3, 75);
  analogWrite(9, 75); 
}

void g()
{ 

  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  analogWrite(3, 75);
  analogWrite(9, 75); 
}

void d1()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  analogWrite(3, 75);
  analogWrite(9, 75); 
}

void g1()
{ 
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  analogWrite(3, 75);
  analogWrite(9, 75); 
}

void c()
{
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  analogWrite(3, 50);
  analogWrite(9, 50);
}

void s()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int statutCapteurC= digitalRead(capteurC);
  int statutCapteurG= digitalRead(capteurG);
  int statutCapteurD= digitalRead(capteurD);

  if (statutCapteurC && !statutCapteurD && statutCapteurG){
    Serial.println("Tourner à gauche");
    g();
  }
  else if (statutCapteurC && !statutCapteurG && statutCapteurD){
    d();
  }
  else if (statutCapteurC && !statutCapteurD && !statutCapteurG){
    c();
  }
  else if (!statutCapteurC && !statutCapteurD && statutCapteurG){
    g1();
  }
 
  else if (!statutCapteurC && !statutCapteurG && statutCapteurD){
    d1();
  }
  else if (statutCapteurC && statutCapteurG && statutCapteurD){
   Aleatoire();
  } 
}
