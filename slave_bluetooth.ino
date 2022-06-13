#include <Adafruit_NeoPixel.h>
#ifdef AVR
#include <avr/power.h>
#endif

#define LED_BACK    5
#define LED_LEFT    4
#define LED_RIGHT   7

#define LED_COUNT 64

char state = 0;
int light_delay = 50;

Adafruit_NeoPixel strip_back(LED_COUNT, LED_BACK, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_left(LED_COUNT, LED_LEFT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_right(LED_COUNT, LED_RIGHT, NEO_GRB + NEO_KHZ800);

int RX_PIN=0;
int TX_PIN=1;

#include<SoftwareSerial.h>

SoftwareSerial Slave_BTDevice(RX_PIN,TX_PIN);

char flag_turns_slave;//Left=-1.Right=1.Nothing=0
void setup() 
{
  strip_back.begin();
  strip_back.show();
  strip_back.setBrightness(150);

  strip_left.begin();
  strip_left.show();
  strip_left.setBrightness(150);

  strip_right.begin();
  strip_right.show();
  strip_right.setBrightness(150);

  Serial.begin(9600);
 // delay(1000);
  
  Slave_BTDevice.begin(9600);
  flag_turns_slave='0';
}
void loop() 
{  
  if(Slave_BTDevice.available()>0)
  {
    flag_turns_slave = Slave_BTDevice.read();
    //Serial.println("working");
  
  //Serial.println(flag_turns_slave);
  delay(200);
  }
  /*if(flag_turns_slave=='0')
  {noBlink();}*/
  
  

 if(flag_turns_slave=='1')
  {
    //Serial.print('Right');
    rightBlink();
   // delay(300);
  }

  else if(flag_turns_slave=='3')
  {
 //Serial.print("Left"); 
  leftBlink();
  //delay(300);
    
  }
  else if(flag_turns_slave=='2')
  {
    //Serial.print("Stop");
    stopStop();
    //noBlink();
    //delay(300);
  }
 /* else if(flag_turns_slave=='0')
  {delay(1000);
    //Serial.print("helo");
  }*/
  flag_turns_slave='0';
}

  void rightBlink() {
  for (int i = 0; i < 4; i++){
    colorBlinkersRight(strip_right.Color(255,   100,   0), 50);
    delay(120);
    colorBlinkersRight(strip_right.Color(0,   0,   0), 25);
    delay(60);
  }
}
void colorBlinkersRight(uint32_t c, int wait){
  for(int i = 0; i<=14; i++){
    strip_right.setPixelColor(i, c);
  }
  for(int i = 0; i<=14; i++){
    strip_back.setPixelColor(i, c);
  }
  
  strip_right.show();
  strip_back.show();
  delay(wait);
  strip_right.clear();
  strip_back.clear();
  delay(wait);
}



void leftBlink() {
  for (int i = 0; i < 4; i++){
    colorBlinkersLeft(strip_left.Color(255,   100,   0), 50);
    delay(120);
    colorBlinkersLeft(strip_left.Color(0,   0,   0), 25);
    delay(60);
  }
}
void colorBlinkersLeft(uint32_t c, int wait){
  for(int i = 0; i<=14; i++){
    strip_left.setPixelColor(i, c);
  }
  for(int i = 15; i<=29; i++){
    strip_back.setPixelColor(i, c);
  }
  
  strip_left.show();
  strip_back.show();
  delay(wait);
  strip_left.clear();
  strip_back.clear();
  delay(wait);
}

int i;
void stopStop(){
  for(i=0;i<1;i++)
  {
  colorStop(strip_left.Color(255, 0, 0), 400);}
  colorStop(strip_left.Color(0, 0, 0), 20);
  //colorStop(strip_right.Color(255, 0, 0), 2000);
  
}

void colorStop(uint32_t c, int wait){
  for(int i = 0; i<=14; i++){
    strip_left.setPixelColor(i, c);
    strip_right.setPixelColor(i, c);
  }
  for(int i = 0; i<=29; i++){
    strip_back.setPixelColor(i, c);
  }
  
  strip_left.show();
  strip_right.show();
  strip_back.show();
  delay(wait);
  strip_left.clear();
  strip_right.clear();
  strip_back.clear();
  delay(wait);}



  void noBlink() {
  for (int i = 0; i < 4; i++){
    colorBlinkersno(strip_left.Color(0,   0,   0), 50);
    colorBlinkersno(strip_right.Color(0,   0,   0), 50);
    delay(400);
  }
}
void colorBlinkersno(uint32_t c, int wait){
  for(int i = 0; i<=14; i++){
    strip_left.setPixelColor(i, c);
    strip_right.setPixelColor(i, c);
  }
  for(int i = 0; i<=29; i++){
    strip_back.setPixelColor(i, c);
  }
  
  strip_left.show();
  strip_right.show();
  strip_back.show();
  delay(wait);
  strip_left.clear();
  strip_right.clear();
  strip_back.clear();
  delay(wait);
}
