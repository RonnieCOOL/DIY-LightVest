#define x A0
#define y A1
#define z A2

int Some_specific_Angle_at_which_one_turns=30;
int x_val;
int y_val;
int z_val;

int x_val2;
int y_val2;
int z_val2;

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
   
x_val2 = analogRead(x);
  y_val2 = analogRead(y);
  z_val2 = analogRead(z);
  
  Master_BTDevice.begin(38400);
}

void loop() {


  x_val = analogRead(x);

int Gyrovalue;

int Accvalue;



int RX_PIN=0;

int TX_PIN=1;



#include<SoftwareSerial.h>



SoftwareSerial Master_BTDevice(RX_PIN,TX_PIN);
  y_val = analogRead(y);
  z_val = analogRead(z);

  int x_adc_value = x_val;
  int y_adc_value = y_val;
  int z_adc_value = z_val;

  x_g_value = ( ( ( (double)(x_adc_value * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in x-direction in g units */ 
  y_g_value = ( ( ( (double)(y_adc_value * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in y-direction in g units */ 
  z_g_value = ( ( ( (double)(z_adc_value * 5)/1024) - 1.80 ) / 0.330 ); /* Acceleration in z-direction in g units */ 

  int yaw =  ( ( (atan2(x_g_value,y_g_value) * 180) / 3.14 ) + 180 );
  
  Serial.print("| aX = "); Serial.print(x_adc_value);
  Serial.print(" | aY = "); Serial.print((y_adc_value));
  Serial.print(" | aZ = "); Serial.print((z_adc_value));
  Serial.print(" yaw = "); Serial.print((yaw));
  Serial.println();
  
  // delay
  delay(1000);
  
  Gyrovalue=yaw;
  Accvalue=x_g_value;
  
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
