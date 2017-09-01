/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
int ledPinGreenOne = 13; // choose the pin for the LED
int ledPinGreenTwo = 11; // choose the pin for the LED
int ledPinRed = 12; // choose the pin for the LED
int inputPin = 2; // choose the input pin (for PIR sensor)
int ledOff = LOW; // we start, assuming no motion detected
int ledOn = HIGH; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status

int pirState = LOW;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledPinGreenOne, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreenTwo, OUTPUT);
  pinMode(inputPin, INPUT); // declare sensor as input

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  val = digitalRead(inputPin); // read input value
  if (val == HIGH) { // check if the input is HIGH
    digitalWrite(ledPinGreenOne, HIGH); // turn LED ON
  if (pirState == LOW) {
    // we have just turned on
    Serial.println("Motion detected!");
    // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPinGreenOne, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
}



  
}
