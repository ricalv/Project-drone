#include <VarSpeedServo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

VarSpeedServo servo9; 
VarSpeedServo servo10;    // create servo object to control a servo 
VarSpeedServo servo11;

/*void servoROS(const std_msgs::UInt16& cmd_msg1){

  
}

ros::NodeHandle  nh;

ros::Subscriber<std_msgs::UInt16> sub1("servoROS", servoROS);*/

void setup() {

  //nh.initNode();
  //nh.subscribe(sub1);
  
  pinMode(A0, OUTPUT);    // sets the digital pin 0 as output
  digitalWrite(A0, HIGH);

  servo9.attach(9);
  servo10.attach(10); 
  servo11.attach(11);

  delay(2000);

  servo9.write(70, 5);
  servo10.write(95, 5);
  servo11.write(95, 5);

  Serial.begin(57600);    // opens serial port, sets data rate to 57600 bps

  delay(2000);
  digitalWrite(A0, LOW);
}


void shortG(){

  delay(1000);
  digitalWrite(A0, HIGH);
  
  servo9.write(145, 10, true);
  servo10.write(156, 10);
  servo11.write(157, 10);

  delay(3000);

  digitalWrite(A0, LOW);

  delay(600000);

  digitalWrite(A0, HIGH);

 
  servo10.write(95, 10);
  servo11.write(95,10, true); 
  servo9.write(70, 10);
  
  delay(3000);

  digitalWrite(A0, LOW);

}

void loop() {

 shortG();

}
