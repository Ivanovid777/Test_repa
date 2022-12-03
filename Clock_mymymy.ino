uint8_t hour = 0;
uint8_t min = 0;
uint8_t sec = 0;
long msec0 = 0;
long msec = 0;

String check(uint8_t data)
{
  String ss ="";
  if (data <= 9)
  {
    return "0" + String(data);
  }
  else 
    return String(data);
 
}

void setup() {
  Serial.begin(115200);

}

void loop() {
  msec = millis();
  if(msec - msec0 >= 1000){
    msec0 = msec;
    sec ++;
  
    if(sec >= 59){
      min ++;
      sec = 0;
      
      if(min >= 59){
        hour ++;
        min = 0;
        
        if(hour >= 23){
        hour =0;
    
        }  
      }
    }
    
    Serial.println(check(hour) + ":" + check(min) + ":" + check(sec));
    }
}
 
