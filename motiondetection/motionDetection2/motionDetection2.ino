
#include <Stepper.h>
 
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;
int trigger=3; 
int echo=2; 
int led = 13;
long dauer=0; 
long entfernung=0; 

Stepper motor(200, in1Pin, in2Pin, in3Pin, in4Pin);  

void setup()
{

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(led, OUTPUT); 
  Serial.begin(9600);
  motor.setSpeed(10);

}
void loop()
{
digitalWrite(trigger, LOW); 
delay(5); 
digitalWrite(trigger, HIGH); 
delay(10);
digitalWrite(trigger, LOW);
dauer = pulseIn(echo, HIGH); 
entfernung = (dauer/2) * 0.03432; 
if (entfernung >= 500 || entfernung <= 0) 
{
Serial.println("Kein Messwert"); 
}


else 
{
if (entfernung >= 200) {
  digitalWrite(led, HIGH);
  motor.step(200);
  
}
else{
  digitalWrite(led, LOW);
  motor.step(-200);
  
}
Serial.print(entfernung); 
Serial.println(" cm"); 
}
delay(2000); 
  
//  if (Serial.available())
//  {
//    int steps = Serial.parseInt();
//    motor.step(steps);
//  }
}
