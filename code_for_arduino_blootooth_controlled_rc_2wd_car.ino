char t;
 
void setup() {
pinMode(13,OUTPUT);   //left motors - move forward
pinMode(12,OUTPUT);   //left motors - move reverse
pinMode(11,OUTPUT);   //right motors - move forward
pinMode(10,OUTPUT);   //right motors - move reverse
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available())
{
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //All the moters rotate in forward direction thus rover moves forward
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'B'){      //All the moters rotate in reverse direction thus rover moves backward
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'L'){      //Motors on the left rotate in forward direction and right side motors are still thus the rover turns right
  digitalWrite(13,HIGH);
}
 
else if(t == 'R'){      //Motors on the left are still and right side motors rotate in forward direction thus the rover turns left
  digitalWrite(11,HIGH);
}

else if(t == 'S'){      //Stops all the motors thus the rover stops
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);
}
