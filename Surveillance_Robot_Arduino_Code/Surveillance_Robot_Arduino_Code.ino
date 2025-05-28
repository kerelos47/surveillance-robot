#include "Pin_Config.h"
#include "Serial_Get_Data.h"
#include "Serial_Put_Data.h"
#include "Radar_Subsystem.h"
#include "Motor_Driver.h"
#include "Lighting_Subsystem.h"
int durrr;

byte leds = 0;    
long previousMillis;
void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  setup_Motor_Driver();
  setup_Radar_Subsystem();
  setup_Lighting_Subsystem();
  pinMode(Latch, OUTPUT);
  pinMode(Data, OUTPUT);  
  pinMode(Clock, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12,HIGH);
  }

void loop(){
   if(digitalRead(State_ESP)==0&&digitalRead(State_BL)==0){
    durrr=600;
    var_res_int[1]=0;var_res_int[2]=0;var_res_int[3]=0;var_res_int[4]=0;
   }else{durrr=100;}
  Get_Serial_Data('@',',','*');
  loop_Motor_Driver();
  loop_Radar_Subsystem();
  loop_Lighting_Subsystem();

//leds = 14; // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
 // updateShiftRegister();
 
    var_send_int[4]=var_res_int[forward_Button];
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= durrr) {
      previousMillis = currentMillis;
    Put_Serial_Data('@',',','*');
    digitalWrite(13,!(digitalRead(13)));
   bitWrite(shift_2,7,(digitalRead(13)));
   
  }
         
  }
