//TMRpcm library is needed

#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
File myfile;
char trackname[]="1.wav";
int tracknumber;

void setup()
{
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
//  tmrpcm.play(trackname);
  int i=1;
  while(i<10){
    sprintf(trackname,"%d.wav",i);
    tmrpcm.play(trackname);
    i++;
    delay(500);
    }
}
