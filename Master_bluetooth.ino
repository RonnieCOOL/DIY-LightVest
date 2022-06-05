int MAX_GYROSCOPE_TILT_VALUE_po = 5000; //I'm assuming that both are like positive(right) and negative(left), else we can shift them ig.
int MAX_GYROSCOPE_TILT_VALUE_ne = -5000;
int GYROSCOPE_ZERO=0;
int Some_specific_Angle_at_which_one_turns=30;


int Gyrovalue;

int RX_PIN=;
int TX_PIN=;

#include<SoftwareSerial.h>

SoftwareSerial Master_BTDevice(RX_PIN,TX_PIN);

int flag_turns_master;//Left=-1.Right=1.Nothing=0

void setup() 
{
  Serial.begin(9600);
  Master_BTDevice.begin(38400);
}

void loop() {



//TheGyrocode Goes Here






Gyrovalue=(Gyrovalue-GYROSCOPE_ZERO)*180/(MAX_GYROSCOPE_TILT_VALUE_po-MAX_GYROSCOPE_TILT_VALUE_ne);
if(Gyrovalue>Some_specific_Angle_at_which_one_turns)
{
  flag_turns_master=1;    
  Master_BTDevice.println(1);
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
