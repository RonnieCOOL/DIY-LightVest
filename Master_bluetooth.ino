#define x A0
#define y A1
#define z A2

int Some_specific_Angle_at_which_one_turns=30;
int x_val;
int y_val;
int z_val;

int x_val2=0;//intitialise these values
int y_val2=0;
int z_val2=0;

int Gyrovalue;
int Accvalue;

int RX_PIN=0;
int TX_PIN=1;

#include<SoftwareSerial.h>

SoftwareSerial Master_BTDevice(RX_PIN,TX_PIN);

int flag_turns_master;//Left=-1.Right=1.Nothing=0

void setup() 
{
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(z, INPUT);
  Serial.begin(9600);
   
  Master_BTDevice.begin(38400);
}

void loop() {


   x_val = analogRead(x);
  y_val = analogRead(y);
  z_val = analogRead(z);

  int x_axis = x_val - x_val2;
  int y_axis = y_val - y_val2;
  int z_axis = z_val - z_val2;

  int x_g_value = ( ( ( (double)(x_axis * 5)/1024) - 1.65 ) / 0.330 ); 
  int y_g_value = ( ( ( (double)(y_axis * 5)/1024) - 1.65 ) / 0.330 );  
  int z_g_value = ( ( ( (double)(z_axis * 5)/1024) - 1.80 ) / 0.330 );

  int roll = ( ( (atan2(y_g_value,z_g_value) * 180) / 3.14 ) + 180 ); 
  int pitch = ( ( (atan2(z_g_value,x_g_value) * 180) / 3.14 ) + 180 );
  
  Serial.print("| aX = "); Serial.print(x_axis);
  Serial.print(" | aY = "); Serial.print((y_axis));
  Serial.print(" | aZ = "); Serial.print((z_axis));
  Serial.print(" Pitch = "); Serial.print((roll));
  Serial.print(" Roll = "); Serial.print((pitch));
  Serial.println();
  
  // delay
  delay(1000);
  
  Gyrovalue=pitch;
  Accvalue=z_axis;
  
if(Accvalue<0)
{
  flag_turns_master=2;
  Master_BTDevice.print(2);
}

if(Gyrovalue>Some_specific_Angle_at_which_one_turns)
{
  flag_turns_master=1;    
  Master_BTDevice.print(1);
}
else if(Gyrovalue<-Some_specific_Angle_at_which_one_turns)
{
  flag_turns_master=-1;    
  Master_BTDevice.print(-1);
}
else
{
  flag_turns_master=0;    
  Master_BTDevice.print(0);
}


}
