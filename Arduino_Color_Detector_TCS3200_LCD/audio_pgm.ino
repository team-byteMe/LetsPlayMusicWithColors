//TMRpcm library is needed

#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"
#include "stationDefines.h"


TMRpcm tmrpcm;
File myfile;
char trackname[]="1.wav";
int tracknumber;
int noteToPlay = -1;

void setup()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); //out from sensor becomes input to arduino

    // Setting frequency scaling to 100%
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);

  tmrpcm.speakerPin=9;
  Serial.begin(9600);
  if(!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  tmrpcm.setVolume(6);
  //tmrpcm.play("1.wav");
  sprintf(trackname,"%d.wav",1);
}

void loop() {
  Serial.println("In the loop");
//  tmrpcm.play(trackname);
  int i=1;
  noteToPlay = readRGB(2, 3, 4);
  delay(300);
  //while(i<10){
  Serial.println(noteToPlay);
    sprintf(trackname,"%d.wav",noteToPlay);
    tmrpcm.play(trackname);
    //i++;
    delay(500);
  //}
}
