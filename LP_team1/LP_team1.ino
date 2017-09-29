int inputSensorF = 0;
int inputSensorB = 0;
bool motor0;
bool motor1;
bool runFlag=true;
byte MUX_decider = B00;
int duration, distance = 0;
#include <NewPing.h>
#define MAX_DISTANCE 200
#define TRIGGER_PIN0 1
#define ECHO_PIN0    2
#define TRIGGER_PIN1 3
#define ECHO_PIN1    4
#define CONTROL0_PIN 5
#define MOTOR_0A_PIN 6
#define MOTOR_1A_PIN 7
#define CONTROL1_PIN 8
#define MOTOR_0B_PIN 9
#define MOTOR_1B_PIN 10
#define INPUT_SWITCH0 11
#define INPUT_SWITCH1 12

NewPing sonar1(TRIGGER_PIN0, ECHO_PIN0, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
void setup()
{
  pinMode(CONTROL1_PIN, OUTPUT);
  pinMode(MOTOR_0A_PIN, OUTPUT);
  pinMode(MOTOR_1A_PIN, OUTPUT);
  pinMode(CONTROL0_PIN, OUTPUT);
  pinMode(MOTOR_0B_PIN, OUTPUT);
  pinMode(MOTOR_1B_PIN, OUTPUT);
  pinMode(INPUT_SWITCH0, INPUT);
  pinMode(INPUT_SWITCH1, INPUT);
  Serial.begin(115200);
}

int checkPulse() {
  digitalWrite(TRIGGER_PIN0, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN0, LOW);
  duration = pulseIn(ECHO_PIN0, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
void runMotors(int taskType, int angle) {
  //taskType defines to stop or go when we sense something in front of us, angle is the turn, "0" for straight
  //we can't go backwards, but retreating is for pussies and the French
  /*
     taskType:
     0=task2 <=avoid obstacles
     1=task3 <= fuck em' up
     2=turn right with a certain angle. (recursion mf'ers)
     3=turn left with a certain angle
  */
  if (taskType == 0 ) {
    //---go forward when there is nothing in front of usfor(int motorSpeed = 0; motorSpeed <= 255; ++motorSpeed)
    while (runFlag) {

      if (checkPulse > 100) { //i have no clue what units this is, change the 100 to whatever we decide on
        analogWrite(CONTROL0_PIN, 100);
        analogWrite(CONTROL1_PIN, 100);
        delay(100);
        analogWrite(CONTROL0_PIN, 0);
        analogWrite(CONTROL1_PIN, 0);

      } else {
        runMotors(2, 30);

        if (checkPulse < 100) {
          runMotors(3, (2 * angle));
        } else {
          return;
        }
      }
    }

  } else if (taskType == 1) {
     while (runFlag) {

      if (checkPulse < 100) { //i have no clue what units this is, change the 100 to whatever we decide on
        analogWrite(CONTROL0_PIN, 100);
        analogWrite(CONTROL1_PIN, 100);
        delay(100);
        analogWrite(CONTROL0_PIN, 0);
        analogWrite(CONTROL1_PIN, 0);

      } else {
        runMotors(2, 30);

        if (checkPulse < 100) {
          runMotors(3, (2 * angle));
        } else {
          return;
        }
      }
    }
  } else if (taskType == 2) {
    analogWrite(CONTROL1_PIN, 100);
    delay(angle);
    analogWrite(CONTROL1_PIN, 0);
  } else if (taskType == 3) {
    analogWrite(CONTROL0_PIN, 100);
    delay(angle);
    analogWrite(CONTROL0_PIN, 0);
  }
}
void task1() {

}

void task2() {
  runMotors(0,0);
}


void task3() {
   runMotors(1,0);
}


void loop() {
  digitalWrite(MOTOR_0A_PIN, LOW);
  digitalWrite(MOTOR_1A_PIN, HIGH);
  digitalWrite(MOTOR_0B_PIN, LOW);
  digitalWrite(MOTOR_1B_PIN, HIGH);
  //This just selects the task needing to be executing by reading the two input switches we have
  if ((digitalRead(INPUT_SWITCH0) == HIGH) || (digitalRead(INPUT_SWITCH1) == LOW)) {
    task1();
  } else if ((digitalRead(INPUT_SWITCH0) == LOW) || (digitalRead(INPUT_SWITCH1) == HIGH)) {
    task2();

  } else if ((digitalRead(INPUT_SWITCH0) == HIGH) || (digitalRead(INPUT_SWITCH1) == HIGH)) {
    task3();
  } else;


}

