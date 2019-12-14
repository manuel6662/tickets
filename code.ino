/*
Sensor de Color     Arduino
----------------------------
 VCC               5V
 GND               GND
 s0                7
 s1                6
 s2                8
 s3                9
 OUT               10  

Salida RELE
_____________________
PINOUT 6
VCC arduino
GND arduino

*/
const int s0 = 7;  
const int s1 = 6;  
const int s2 = 8;  
const int s3 = 9;  
const int out = 10; 
const int rele =5;  
int rojo = 0;  
int verde = 0;  
int azul = 0;  
//////////////////////////////////////////////////////////////////////////////////////VOID SETUP    
void setup(){  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);   
  pinMode(rele, OUTPUT);
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,  HIGH);  
}  
//////////////////////////////////////////////////////////////////////////////////////VOID LOOP    
void loop(){  
  color(); 
  Serial.print("  rojo: ");  
  Serial.print(rojo, DEC);  
  Serial.print("  verde: ");  
  Serial.print(verde, DEC);  
  Serial.print("  azul: ");  
  Serial.print(azul, DEC);  


if (  rojo <20 && rojo < verde && verde <azul  )
{
   Serial.println(" - AMARILLO"); 
    digitalWrite(rele, LOW);
}else if (  rojo <20 && rojo < verde && verde >azul && verde >35 )
{
   Serial.println(" - NARANJA"); 
    digitalWrite(rele, LOW);
}
else if (  rojo <20 && rojo < verde && verde >azul &&verde >20)
{
   Serial.println(" - ROSA"); 
   digitalWrite(rele, HIGH);
}

else if (rojo < 16 && azul < 16 && verde < 16)
  {
     Serial.println(" - BLANCO");  
      digitalWrite(rele, LOW);
  }
 else if (rojo > 35 && azul >35 && verde > 35)
  {
     Serial.println(" - NEGRO");  
      digitalWrite(rele, LOW);
  }
  
  else  if (rojo < azul && rojo < azul ) 
  {  
   Serial.println(" - ROJO");    
    digitalWrite(rele, LOW);
  }   
  else if (azul < rojo && azul < verde)  
  {  
   Serial.println(" - AZUL");  
    digitalWrite(rele, LOW);      
  }  
  else if (verde < rojo && verde < azul)  
  {  
   Serial.println(" - VERDE");    
    digitalWrite(rele, LOW);   
  }  
  else{
  Serial.println("-");  
  }
  delay(300);     
  }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
