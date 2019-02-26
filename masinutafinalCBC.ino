#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

#define in1 8
#define in2 9
#define in3 12
#define in4 13
#define led_red 6
#define led_blue 5
#define led_white 7

char state;

void policeOn()
{
  int strb_speed = 60;
  digitalWrite(led_red, HIGH);
  delay(strb_speed);
  digitalWrite(led_red, LOW);
  digitalWrite(led_blue, HIGH);
  delay(strb_speed);
  digitalWrite(led_blue, LOW);
}
void policeOff()
{
  digitalWrite(led_red, LOW);
  digitalWrite(led_blue, LOW);
}
void setup()
{

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(led_red,OUTPUT);
  pinMode(led_blue, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  BTSerial.begin(38400);  
  Serial.begin(9600);
}

void loop() {
 
  
      if(BTSerial.available() > 0)
         {     
           state = BTSerial.read(); 
           Serial.println(state);  
         }
    
      if(state == 'A')
        {
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
        }
      if(state == 'B')
        {
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
        }
      if(state == 'C')
        {
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
        }
      if(state == 'D')
        {
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
        }
      if(state == 'F')
        {
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
        }
      if(state == 'G')
         policeOn();
      if(state == 'P')
         policeOff();
      if(state == 'K')
        digitalWrite(led_white, HIGH);
      if(state == 'L')
        digitalWrite(led_white, LOW);
}
