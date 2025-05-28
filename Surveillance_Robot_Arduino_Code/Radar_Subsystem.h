#define SRPWM_Slider 7
#define Servo_Auto 8
#define distance_index 1
#define angle_index 2

#include <Servo.h>

short Servo_dir,Servo_angle;
long duration,previousMillis_servo;
int distance;
Servo myServo;

int calculateDistance(){  
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH,5000);
  distance= duration*0.034/2;
  if(distance==0){return 85;}
  return distance;
}

  void sweep_servo(){
if (millis() - previousMillis_servo >= 15) {
    previousMillis_servo = millis();
    if(Servo_dir==1){Servo_angle+=1;}
    if(Servo_angle>=180){Servo_dir=2;}
    if(Servo_dir==2){Servo_angle-=1;}
    if(Servo_angle<=0){Servo_dir=1;}
    //Serial.println(Servo_angle);
    
    if(var_res_int[2]==0){var_send_int[angle_index]=Servo_angle;myServo.write(Servo_angle);}
    
}
  }



void setup_Radar_Subsystem(){
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);

  digitalWrite(TRIG,LOW);
  
  myServo.attach(SRPWM);
  }

void loop_Radar_Subsystem(){
  if(var_res_int[Servo_Auto]==0){
    
    if(var_res_int[2]==0){
      var_send_int[angle_index]=var_res_int[SRPWM_Slider];
      myServo.write(var_res_int[SRPWM_Slider]);}
    }
  if(var_res_int[Servo_Auto]==1) {sweep_servo();}
  var_send_int[distance_index]=calculateDistance();
  
  
  }
