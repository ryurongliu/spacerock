const int mag1Button  = 6; //mag 1 direction button
const int mag2Button = 7; //mag other direction button
const int percOnButton = 5; //perc on button
const int percOffButton = 8; //perc off button
const int ledMag1  = 2;
const int ledMag2 = 3;
const int ledPerc = 4;

int percGoing = 0; //is perc going or not
int magRot = 0; //mag rotating or not
int magCount = 0; 

#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Create the motor shield object with the default I2C address

Adafruit_StepperMotor *magMotor = AFMS.getStepper(200, 2); //mag motor to M3 and M4
Adafruit_StepperMotor *percMotor = AFMS.getStepper(200, 1); //perc motor to M1 and M2

int len_directions = 16;
int directions[] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
int steps[] = {60, 70, 110, 40, 40, 90, 40, 50, 140, 40, 150, 100, 50, 140, 100, 160}; void setup()
{
  pinMode(ledMag1,OUTPUT);
  pinMode(ledMag2,OUTPUT);
  pinMode(ledPerc,OUTPUT);
  pinMode(mag1Button,INPUT_PULLUP);
  pinMode(mag2Button,INPUT_PULLUP);
  pinMode(percOnButton,INPUT_PULLUP);
  pinMode(percOffButton, INPUT_PULLUP);
  
  Serial.begin(9600);// set up Serial library at 9600 bps
  while (!Serial);

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  magMotor->setSpeed(10);  // 10 rpm
  percMotor->setSpeed(10);  // 10 rpm
}




int startTime = millis(); 

int currDir = 0;
int currStep = 0; 
int magGoing = 0; 
void loop()
{
  //do perc read
  if (digitalRead(percOnButton) == LOW) //perc on button pressed
  {
    Serial.println("perc on");
    percGoing = 1;
    digitalWrite(ledPerc, HIGH);
  }
  if (digitalRead(percOffButton) == LOW) //perc off button pressed
  {
    Serial.println("perc off");
    percGoing = 0; 
    digitalWrite(ledPerc, LOW);
  }

  if (digitalRead(mag1Button) == LOW)
  {
    Serial.println("mag on");
    magGoing = 1;
    currDir = 0;
    currStep = 0;
  }
  if (digitalRead(mag2Button) == LOW)
  {
    Serial.println("mag off");
    magGoing = 0;
    currDir = 0;
    currStep = 0; 
  }

  //do mag read
  /*
  if (digitalRead(mag1Button) == LOW) //mag1 button pressed
  {
    magRot = 1; //set to go one direction
  }
  else if (digitalRead(mag2Button) == LOW) //mag2 button pressed
  {
    magRot = 2;
  }
  else //no mag button pressed
  {
    magRot = 0; 
  }
  */
  if (magGoing == 1)
  {
    //start reading from beginning direction
    if (currStep < steps[currDir]){ //if our current step is within step bounds
      magRot = directions[currDir];
      currStep += 1;
    }
    else if (currStep == steps[currDir]){
      currStep = 0;
      if (currDir < (len_directions - 1)){
        currDir += 1;
        Serial.println("starting next dir"); 
      }
      else{
        currDir = 0;
        Serial.println("restarting loop");  
      }
      magRot = directions[currDir];
      currStep += 1; 
    }
  }
  else 
  {
    magRot = 3; 
  }
  //do perc out
  if (percGoing == 1) //perc should be going
  {
    percMotor->onestep(BACKWARD, DOUBLE);
    Serial.println("perc going");
  }

  //do mag out
  if (magRot == 1)
  {
    magMotor->onestep(BACKWARD, INTERLEAVE); 
    digitalWrite(ledMag1, HIGH); 
    magCount += 1;
  }
  else if (magRot == 2)
  {
    magMotor->onestep(FORWARD, INTERLEAVE);
    digitalWrite(ledMag2, HIGH);
  }
  else
  {
    digitalWrite(ledMag2, LOW);
    digitalWrite(ledMag1, LOW);
  }
}
