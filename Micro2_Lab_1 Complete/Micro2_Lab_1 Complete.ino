int redLED = 13;
int yellowLED = 12;
int greenLED = 11;
int BUTTON_PIN = 7;
int buzzer = 10;
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(BUTTON_PIN) == LOW) {
    StoplightSequence(); //if button press is detected, go into stoplight sequence
  }
  else {
    IdleBlinkState(); //otherwise, play the idle light sequence (1 sec on... 1 sec off).
  }



}

void StoplightSequence() {

while (1) //infinite while loop... only stops when system is restarted/powered off.
{
 digitalWrite(redLED, HIGH); //RED light comes on
  delay(20000); //RED light stays on for 20 seconds
  tone(buzzer, 500); //LED buzzer sounds
  delay(3000); //after 3 seconds, buzzer is off and light is off
  digitalWrite(redLED, LOW); //light turns off
  noTone(buzzer); //buzzer turns off
  delay(100);


  digitalWrite(greenLED, HIGH); //GREEN light comes on
  delay(20000); //GREEN light stays on for 20 seconds
  tone(buzzer, 500); //Buzzer sounds
  delay(3000); //after 3 seconds...
  digitalWrite(greenLED, LOW); //light turns off
  noTone(buzzer); //buzzer turns off
  delay(100);


  digitalWrite(yellowLED, HIGH); //yellow light is on
  tone(buzzer, 500);   //buzzer turns on
  delay(3000); //yellow light and buzzer stay on for 3 seconds
  digitalWrite(yellowLED, LOW); //light turns off
  noTone(buzzer); //buzzer turns off
  delay(100);

}
 

}

void IdleBlinkState(){

 
  digitalWrite(redLED, HIGH);
  delay(1000);
  digitalWrite(redLED, LOW);
  delay(1000);

}