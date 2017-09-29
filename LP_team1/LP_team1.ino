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
#define CONTROL1_PIN 5
#define MOTOR_1A_PIN 6
#define MOTOR_2A_PIN 7
#define CONTROL2_PIN 8
#define MOTOR_1B_PIN 9
#define MOTOR_2B_PIN 10
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
void setup()
{
  pinMode(CONTROL1_PIN, OUTPUT);
  pinMode(MOTOR_1A_PIN, OUTPUT);
  pinMode(MOTOR_2A_PIN, OUTPUT);
  pinMode(CONTROL2_PIN, OUTPUT);
  pinMode(MOTOR_1B_PIN, OUTPUT);
  pinMode(MOTOR_2B_PIN, OUTPUT);
  Serial.begin(115200);
}
void loop()
{
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar1.ping_cm());
  Serial.println("cm");
  
  digitalWrite(MOTOR_1A_PIN, LOW);
  digitalWrite(MOTOR_2A_PIN, HIGH);
  digitalWrite(MOTOR_1B_PIN, LOW);
  digitalWrite(MOTOR_2B_PIN, HIGH);
  for(int motorSpeed = 0; motorSpeed <= 255; ++motorSpeed)
  {
    analogWrite(CONTROL1_PIN, motorSpeed);
    analogWrite(CONTROL2_PIN, motorSpeed);
    delay(15);
  }
  
  for(int motorSpeed = 255; motorSpeed >=0; --motorSpeed)
  {
    analogWrite(CONTROL1_PIN, motorSpeed);
    analogWrite(CONTROL2_PIN, motorSpeed);
    delay(15);
  }
}




void task1(){
}

void task2(){
}

void task3(){
  }

}

