
int delaylegnth = 30;
int trigger = 6;
int echo = 7;

int led = 13;
long dauer = 0;
long entfernung = 0;
int motorSpeed = 10;
int entfernungZumStartenVomHochziehen = 200;
int pauseNachHochziehen = 10000;
int umdrehung = 50;
int umdrehungenDesMotorsZumHochziehen = 10;
int umdrehungenDesMotorsZumRunterfahren = -umdrehungenDesMotorsZumHochziehen;
int maximaleEntfernung = 500;


bool turn = true;

void setup() {

  //establish motor direction toggle pins
  pinMode(12, OUTPUT); //CH A -- HIGH = forwards and LOW = backwards???
  pinMode(13, OUTPUT); //CH B -- HIGH = forwards and LOW = backwards???


  //establish motor brake pins
  pinMode(9, OUTPUT); //brake (disable) CH A
  pinMode(8, OUTPUT); //brake (disable) CH B

  //motion sensor
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
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
      pullUp(umdrehung * umdrehungenDesMotorsZumHochziehen);
      delay(pauseNachHochziehen);
      pullDown(umdrehung * umdrehungenDesMotorsZumRunterfahren);
      Serial.write(100); //start ton
      delay(10000);
      Serial.write(0); //stop ton TODO: trigger from PD
      pullUp(umdrehung * umdrehungenDesMotorsZumHochziehen);
      delay(3000);
      pullDown(umdrehung * umdrehungenDesMotorsZumRunterfahren);
      digitalWrite(led, HIGH);
      delay(10000);
    }
  }
}

void pullUp (int duration) {
  for (int i = 0; i < duration; i++) {
    turnMotor(255);
  }
}

void pullDown (int duration) {
  for (int i = 0; i < duration; i++) {
    turnMotorReverse(255);
  }
}

void turnMotor(int steps) {
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, steps);   //Moves CH A

  delay(delaylegnth);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, steps);   //Moves CH B

  delay(delaylegnth);

  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, steps);   //Moves CH A

  delay(delaylegnth);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, steps);   //Moves CH B

  delay(delaylegnth);
}


void turnMotorReverse(int steps) {
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A

  delay(delaylegnth);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B

  delay(delaylegnth);

  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A

  delay(delaylegnth);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B

  delay(delaylegnth);

}

