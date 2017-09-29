int inputSensorF = 0;
int inputSensorB = 0;
bool motor1;
bool motor2;
byte MUX_decider = B00;
#include <NewPing.h>
#define MAX_DISTANCE 200
#define TRIGGER_PIN1 1
#define ECHO_PIN1    2
#define TRIGGER_PIN2 3
#define ECHO_PIN2    4
#define CONTROL0_PIN 5
#define MOTOR_1A_PIN 6
#define MOTOR_2A_PIN 7
#define CONTROL1_PIN 8
#define MOTOR_1B_PIN 9
#define MOTOR_2B_PIN 10
#define INPUT_SWITCH0 11
#define INPUT_SWITCH1 12

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
void setup()
{
  pinMode(CONTROL1_PIN, OUTPUT);
  pinMode(MOTOR_1A_PIN, OUTPUT);
  pinMode(MOTOR_2A_PIN, OUTPUT);
  pinMode(CONTROL0_PIN, OUTPUT);
  pinMode(MOTOR_1B_PIN, OUTPUT);
  pinMode(MOTOR_2B_PIN, OUTPUT);
  pinMode(INPUT_SWITCH0, INPUT);
  pinMode(INPUT_SWITCH1, INPUT);
  Serial.begin(115200);
}


void task1(){
}

void task2(){
}

void task3(){
}


void loop()
{
if ((digitalRead(INPUT_SWITCH0)==HIGH)||(digitalRead(INPUT_SWITCH1)==LOW)){
  task1();
} else if ((digitalRead(INPUT_SWITCH0)==LOW)||(digitalRead(INPUT_SWITCH1)==HIGH)){
  task2();
  
}else if ((digitalRead(INPUT_SWITCH0)==HIGH)||(digitalRead(INPUT_SWITCH1)==HIGH)){
  task3();
} else;


}

