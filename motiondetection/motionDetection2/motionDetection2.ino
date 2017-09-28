
#include <Stepper.h>

int motorPin1 = 8;
int motorPin2 = 13;
int motorPin3 = 9;
int motorPin4 = 12;
int trigger = 5;
int echo = 4;
int led = 13;
long dauer = 0;
long entfernung = 0;
int motorSpeed = 10;
int entfernungZumStartenVomHochziehen = 200;
int pauseNachHochziehen = 10000;
int umdrehung = 200;
int umdrehungenDesMotorsZumHochziehen = 10;
int umdrehungenDesMotorsZumRunterfahren = -umdrehungenDesMotorsZumHochziehen;
int maximaleEntfernung = 500;

Stepper motor(200, 8, 9, 12, 13);

void setup()\
{

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  motor.setSpeed(motorSpeed);

}
void loop()
{
  digitalWrite(led, LOW);
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  entfernung = (dauer / 2) * 0.03432;
  Serial.print(entfernung);
  if (entfernung >= maximaleEntfernung || entfernung <= 0)
  {
    Serial.println("Kein Messwert");
  }

  else
  {
    if (entfernung <= entfernungZumStartenVomHochziehen) {
      Serial.print("works");
      motor.step(umdrehung * umdrehungenDesMotorsZumHochziehen);
      Serial.print("breaks");
      delay(pauseNachHochziehen);
      motor.step(umdrehung * umdrehungenDesMotorsZumRunterfahren);
      Serial.write(100); //start ton
      delay(10000);
      Serial.write(0); //stop ton TODO: trigger from PD
      motor.step(umdrehung * umdrehungenDesMotorsZumHochziehen);
      delay(3000);
      motor.step(umdrehung * umdrehungenDesMotorsZumRunterfahren);
      digitalWrite(led, HIGH);
      delay(10000);
    }

  }
  /* else{ */
  /* digitalWrite(led, LOW); */
  /* motor.step(umdrehung * umdrehungenDesMotorsZumRunterfahren); */
  /* } */
  /* Serial.print(entfernung); */
  /* Serial.println(" cm"); */

  //  if (Serial.available())
  //  {
  //    int steps = Serial.parseInt();
  //    motor.step(steps);
  //  }
}
