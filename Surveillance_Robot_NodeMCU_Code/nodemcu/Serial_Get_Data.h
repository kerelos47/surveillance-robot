#include "Serial_Put_Data.h" 
#define max_get_data 10
 String var_res_str[max_get_data+1];
 int var_res_int[max_get_data+1];
 char c;short var , cont;


 void clear_string(){
  for(int i=1;i<=max_get_data;i++){
            var_res_str[i]="";
          }            
  }


 void Get_Serial_Data(char header,char delimiter,char terminator){
  
if(mySerial.available())                                           //if there's any data received and stored in the serial receive buffer, go and excute the if-condition body. If not, dont excute the if-condition body at all.
  {
    while(mySerial.available())                                      //is there any response came from the ESP8266 and saved in the Arduino input buffer?
      {
       c = mySerial.read();  //gets one byte from serial buffer
       delay(3);  //small delay to allow input buffer to fill                                  //if yes, read the next character from the input buffer and save it in the "response" String variable.
       if(c == header){cont=1;var=1;clear_string();}
      if(c == delimiter){var++;}
      
      if(cont==1&&c!=header&&c!=delimiter&&c!=terminator){
        var_res_str[var] += c;       
        }                                                  //append the next character to the response variabl. at the end we will get a string(array of characters) contains the response.
        
  
 
   
    
      
     
    
      if (cont==1&&c == terminator) {
        for(int i=1;i<=var;i++){
          //Serial.print(var_res_str[i]);
          var_res_int[i]=var_res_str[i].toInt();
          //Serial.print("-->");
          //Serial.println(var_res_int[i]);
          //Serial.println("*****************");
          
        } 
        clear_string();
        c=' ';
        cont=0;
       
    }
      }

  }
  mySerial.flush();
 }
