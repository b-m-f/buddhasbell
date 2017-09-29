
int delaylegnth = 10;
int accellerationFactor = 2;
int maxAccelleration = 25;
int trigger = 6;
int echo = 7;

int led = 10;
long dauer = 0;
long entfernung = 0;
int motorSpeed = 10;
int entfernungZumStartenVomHochziehen = 200;
int minute = 60000;
int pauseNachHochziehen = 10000;
int pauseZumMeditieren = 2 * minute;
int pauseWennFertig = minute;

int umdrehung = 50;
int umdrehungenDesMotorsZumHochziehen = 27;
int umdrehungenDesMotorsZumRunterfahren = umdrehungenDesMotorsZumHochziehen;
int maximaleEntfernung = 500;
int stepsTaken = 0;


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
  digitalWrite(led, HIGH);
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
    digitalWrite(led, LOW);
    if (entfernung <= entfernungZumStartenVomHochziehen) {
      pullUp(umdrehung * umdrehungenDesMotorsZumHochziehen);
      delay(pauseNachHochziehen);
      pullDown(umdrehung * umdrehungenDesMotorsZumRunterfahren);
      delay(pauseZumMeditieren);
      pullUp(umdrehung * umdrehungenDesMotorsZumHochziehen);
      delay(pauseNachHochziehen);
      pullDown(umdrehung * umdrehungenDesMotorsZumRunterfahren);
      delay(pauseWennFertig);
    }
  }
}

void pullUp (int duration) {
  for (int i = 0; i < duration; i++) {
    turnMotor(255);
    stepsTaken++;
  }
}

void pullDown (int duration) {
  for (int i = 0; i < duration; i++) {
    turnMotorReverse(255);
    stepsTaken = 0;
    stepsTaken++;
  }
}



void turnMotorReverse(int steps) {
  if (delaylegnth == 0 || delaylegnth == maxAccelleration) {
    delaylegnth = - accellerationFactor ;
  }
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


void turnMotor(int steps) {
   if (delaylegnth == 0 || delaylegnth == maxAccelleration) {
    delaylegnth =- accellerationFactor ;
  }
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, steps);   //Moves CH A

  delay(delaylegnth);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, steps);   //Moves CH B

  delay(delaylegnth);

  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, steps);   //Moves CH A

  delay(delaylegnth);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, steps);   //Moves CH B

  delay(delaylegnth);

}

