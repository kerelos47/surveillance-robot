#define forward_Button 1
#define backward_Button 2
#define right_Button 3
#define left_Button 4
#define MRPWM_Slider 5
#define MLPWM_Slider 6

short shift_1 = 0;
short shift_2 = 0;


void setup_Motor_Driver()
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(Latch, OUTPUT);
  pinMode(Data, OUTPUT);
  pinMode(Clock, OUTPUT);
  pinMode(MR, OUTPUT);

  pinMode(MRPWM, OUTPUT);
  pinMode(MLPWM, OUTPUT);

  
  digitalWrite(MR,HIGH);
  var_res_int[MRPWM_Slider]=255;
  var_res_int[MLPWM_Slider]=255;
}


void motor_forward(){
  bitWrite(shift_1,0,1); //M1A
  bitWrite(shift_1,1,0); //M1B
  bitWrite(shift_1,2,1); //M2A
  bitWrite(shift_1,3,0); //M2B
  bitWrite(shift_1,4,1); //M3A
  bitWrite(shift_1,5,0); //M3B
  bitWrite(shift_1,6,1); //M4A
  bitWrite(shift_1,7,0); //M4B
}

void motor_stop(){
  bitWrite(shift_1,0,0); //M1A
  bitWrite(shift_1,1,0); //M1B
  bitWrite(shift_1,2,0); //M2A
  bitWrite(shift_1,3,0); //M2B
  bitWrite(shift_1,4,0); //M3A
  bitWrite(shift_1,5,0); //M3B
  bitWrite(shift_1,6,0); //M4A
  bitWrite(shift_1,7,0); //M4B
}

void motor_backward(){
  myServo.write(90);
  var_send_int[angle_index]=90;
  if(calculateDistance()>30){
  bitWrite(shift_1,0,0); //M1A
  bitWrite(shift_1,1,1); //M1B
  bitWrite(shift_1,2,0); //M2A
  bitWrite(shift_1,3,1); //M2B
  bitWrite(shift_1,4,0); //M3A
  bitWrite(shift_1,5,1); //M3B
  bitWrite(shift_1,6,0); //M4A
  bitWrite(shift_1,7,1); //M4B
  }
  else{motor_stop();}
}

void motor_right(){
  bitWrite(shift_1,0,1); //M1A
  bitWrite(shift_1,1,0); //M1B
  bitWrite(shift_1,2,1); //M2A
  bitWrite(shift_1,3,0); //M2B
  bitWrite(shift_1,4,0); //M3A
  bitWrite(shift_1,5,1); //M3B
  bitWrite(shift_1,6,0); //M4A
  bitWrite(shift_1,7,1); //M4B
}

void motor_left(){
  bitWrite(shift_1,0,0); //M1A
  bitWrite(shift_1,1,1); //M1B
  bitWrite(shift_1,2,0); //M2A
  bitWrite(shift_1,3,1); //M2B
  bitWrite(shift_1,4,1); //M3A
  bitWrite(shift_1,5,0); //M3B
  bitWrite(shift_1,6,1); //M4A
  bitWrite(shift_1,7,0); //M4B
}



void updateShiftRegister()
{
   digitalWrite(Latch, LOW);
   shiftOut(Data, Clock, MSBFIRST, shift_1);
   shiftOut(Data, Clock, MSBFIRST, shift_1);
   digitalWrite(Latch, HIGH);
}


void loop_Motor_Driver()
{
  if(var_res_int[forward_Button]==1){motor_forward();}
  if(var_res_int[backward_Button]==1){motor_backward();}
  if(var_res_int[right_Button]==1){motor_right();}
  if(var_res_int[left_Button]==1){motor_left();}
   if(var_res_int[forward_Button]==0&&var_res_int[backward_Button]==0&&var_res_int[right_Button]==0&&var_res_int[left_Button]==0){
    motor_stop();}

  analogWrite(MLPWM,var_res_int[MRPWM_Slider]);
  //analogWrite(MRPWM,var_res_int[MRPWM_Slider]);
  
   
  updateShiftRegister();
  

}
