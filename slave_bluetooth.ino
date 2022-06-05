int MAX_GYROSCOPE_TILT_VALUE_po = 5000; //I'm assuming that both are like positive and negative, else we can shift them ig.
int MAX_GYROSCOPE_TILT_VALUE_ne = -5000;
int GYROSCOPE_ZERO=0;
int Some_specific_Angle_at_which_one_turns=30;

int RX_PIN=0;
int TX_PIN=1;

#include<SoftwareSerial.h>

SoftwareSerial Slave_BTDevice(RX_PIN,TX_PIN);

int flag_turns_slave;//Left=-1.Right=1.Nothing=0
void setup() 
{
  Serial.begin(9600);
  Slave_BTDevice.begin(38400);
  flag_turns_slave=0;
}
void loop() 
{  
  if(Slave_BTDevice.available()>0)
  {flag_turns_slave = Slave_BTDevice.read();
  Serial.write(flag_turns_slave);
  delay(10);
  }

  if(flag_turns_slave==1)
  {
    //turn right code
  }

  else if(flag_turns_slave==-1)
  {
  
  //turn left code
  }

  else if(flag_turns_slave=0)
  {
  
  //no turn code
  }
  
}
