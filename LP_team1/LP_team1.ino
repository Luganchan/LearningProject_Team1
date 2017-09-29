int inputSensorF = 0;
int inputSensorB = 0;
bool motor0;
bool motor1;
byte MUX_decider = B00;
#include <NewPing.h>
#define MAX_DISTANCE 200
#define TRIGGER_PIN0 1
#define ECHO_PIN1    2
#define TRIGGER_PIN1 3
#define ECHO_PIN2    4
#define CONTROL0_PIN 5
#define MOTOR_0A_PIN 6
#define MOTOR_1A_PIN 7
#define CONTROL1_PIN 8
#define MOTOR_0B_PIN 9
#define MOTOR_1B_PIN 10
#define INPUT_SWITCH0 11
#define INPUT_SWITCH1 12

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
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

void runMotors(bool taskType, int angle){
//taskType defines to stop or go when we sense something in front of us, angle is the turn, "0" for straight
//we can't go backwards, but retreating is for pussies and the French
if (taskType){
  //---go forward when there is nothing in front of usfor(int motorSpeed = 0; motorSpeed <= 255; ++motorSpeed)
  while (true){
    digitalWrite(TRIGGER_PIN0, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
    analogWrite(CONTROL1_PIN, 100);
    analogWrite(CONTROL2_PIN, 100);
    
  }
  
}
}
void task1(){
  
}

void task2(){
}


void task3(){
}


void loop(){
  digitalWrite(MOTOR_0A_PIN, LOW);
  digitalWrite(MOTOR_1A_PIN, HIGH);
  digitalWrite(MOTOR_0B_PIN, LOW);
  digitalWrite(MOTOR_1B_PIN, HIGH);
  //This just selects the task needing to be executing by reading the two input switches we have
if ((digitalRead(INPUT_SWITCH0)==HIGH)||(digitalRead(INPUT_SWITCH1)==LOW)){
  task1();
} else if ((digitalRead(INPUT_SWITCH0)==LOW)||(digitalRead(INPUT_SWITCH1)==HIGH)){
  task2();
  
}else if ((digitalRead(INPUT_SWITCH0)==HIGH)||(digitalRead(INPUT_SWITCH1)==HIGH)){
  task3();
} else;


}

