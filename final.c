#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"
#include "stationDefines.h"

#define t0 6
#define t1 5
#define t2 2
#define t3 3
#define outPin 4

File song;
TMRpcm tmrpcm;
char aud_name[]="1.wav";
int aud_num;
int node_index=-1;
int red;
int grn;
int blu;
String color ="";
int count = 0;
long startTiming = 0;
long elapsedTime =0;


int getColor(int red, int grn, int blu)
{
  int ans = -1;
  if (red > 230 && red < 255 && grn > 230 && grn <= 255 && blu > 230 && blu < 255) ans = 1;
  else if (red >= 230 && red < 255 && grn > 0 && grn < 30 && blu > 0 && blu < 30) ans = 2;
  else if (red > 0 && red < 30 && grn > 0 && grn < 30 && blu > 230 && blu < 255) ans = 3;
  else if (red > 0 && red < 30 && grn > 230 && grn < 255 && blu > 0 && blu < 30) ans = 4;
  else if (red > 230 && red < 255 && grn > 230 && grn < 255 && blu > 0 && blu < 30) ans = 5;
  else if (red > 0 && red < 30 && grn > 230 && grn < 255 && blu > 0 && blu < 255) ans = 6;
  else if (red > 230 && red < 255 && grn > 0 && grn < 30 && blu > 230 && blu < 255) ans = 7;
  else if (red > 170 && red < 200 && grn > 170 && grn < 200 && blu > 170 && blu < 200) ans = 8;
  else if (red > 120 && red < 140 && grn > 120 && grn < 140 && blu > 120 && blu < 140) ans = 9;
  else  ans = 10;
  return ans;
}

int readRGB(int s2, int s3, int outPin){
    int red = 0;
    int green = 0;
    int blue = 0;
    int n = 10;
    for (int i = 0; i < n; ++i)
    {
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
        red = red + pulseIn(outPin, LOW);

        digitalWrite(s2, HIGH);
        digitalWrite(s3, HIGH);
        green = green + pulseIn(outPin, LOW);

        digitalWrite(s2, LOW);
        digitalWrite(s3, HIGH);
        blue = blue + pulseIn(outPin, LOW);
        delay(50);
    }
    red = red/n;
    green = green/n;
    blue = blue/n;
    return getColor(red, grn, blu);
 }



void setup(){
    pinMode(t0, OUTPUT);
    pinMode(t1, OUTPUT);
    pinMode(t2, OUTPUT);
    pinMode(t3, OUTPUT);
    pinMode(outPin, INPUT); //out from sensor becomes input to arduino

    // Setting frequency scaling to 100%
    digitalWrite(t0,HIGH);
    digitalWrite(t1,HIGH);

    tmrpcm.speakerPin=9;
    Serial.begin(9600);
    if(!SD.begin(SD_ChipSelectPin))
    {
        return;
    }
    tmrpcm.setVolume(6);
    sprintf(aud_name,"%d.wav",1);
}


void loop() {
    int i=1;
    node_index = readRGB(t2, t3, outPin);
    delay(300);
    sprintf(aud_name,"%d.wav",node_index);
    tmrpcm.play(aud_name);
    delay(500);
}
