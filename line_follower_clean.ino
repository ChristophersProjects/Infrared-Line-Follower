//Line Follower Sketch
#include <Servo.h> 

Servo left;
Servo right; 

int min = 1000;
int max = 0;
int avg = 0;

void setup()
{
left.attach(9, 800, 2200); //left servo motor
right.attach(10, 800, 2200); //right servo motor

Serial.begin(9600);
}

void loop()
{
int s0 = 0;
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;

s0 = analogRead(0);//Signal pin 1 on the board
s1 = analogRead(1);//Signal pin 2 on the board
s2 = analogRead(2);//Signal pin 3 on the board
s3 = analogRead(3);//Signal pin 4 on the board
s4 = analogRead(4);//Signal pin 5 on the board
s5 = analogRead(5);//Signal pin 6 on the board

//prints the values of reflectance

Serial.print(" ");
Serial.print(s0); 
Serial.print(" ");
Serial.print(s1); 
Serial.print(" ");
Serial.print(s2); 
Serial.print(" ");
Serial.print(s3); 
Serial.print(" ");
Serial.print(s4); 
Serial.print(" ");
Serial.print(s5); 
Serial.print(" ");
Serial.println();

Serial.print("Max");
Serial.print(" ");
Serial.print(max);
Serial.print(" ");
Serial.print(min);
Serial.print(" ");
Serial.print(avg);
Serial.println();

right.write(85);//Move forward
left.write(95);//Move forward

delay(1);

int value = 0;
for (int i=0; i<6; i++)
{
  int value = analogRead(i);
  if(value >= max)
  max = value;
  if(value <= min)
  min = value;
}

avg = ((max+min)/2);

if((((s0+s1+s2)/3)>(((s3+s4+s5)/3)+240)))//Move right
{
right.write(85);//180
left.write(90);//90
Serial.print(" RIGHT");
//delay(abs((((s5+s4+s3))-((s0+s1+s2)))/2)); //delay based on correction that needs to be made
}

if((((s0+s1+s2)/3)<(((s3+s4+s5)/3)-240)))//Move left
{
right.write(90);//90
left.write(95);//0
Serial.print(" LEFT");
//delay(abs((((s5+s4+s3))-((s0+s1+s2)))/2)); //delay based on correction that needs to be made
}

if((s0 > avg) && (s5 > avg))//Stop
{
right.write(90);//90
left.write(90);//0
Serial.print(" STOP");
}


}

