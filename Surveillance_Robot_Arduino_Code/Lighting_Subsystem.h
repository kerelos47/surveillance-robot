#define LEDPWM_Slider  9
#define LED_ON 10
#define LDR_index 3

void setup_Lighting_Subsystem(){
  //pinMode(LDR, INPUT);
  pinMode(LEDPWM, OUTPUT);
  digitalWrite(LEDPWM, LOW);
  
  }

void loop_Lighting_Subsystem(){
  if(var_res_int[LED_ON]==1){digitalWrite(LEDPWM,HIGH);}
  else {
  if(var_send_int[LDR_index]<var_res_int[LEDPWM_Slider]){digitalWrite(LEDPWM,HIGH);}
  if(var_send_int[LDR_index]>var_res_int[LEDPWM_Slider]+5){digitalWrite(LEDPWM,LOW);}
  }
  var_send_int[LDR_index]=map(analogRead(LDR),600,1024,100,0);
  } 
