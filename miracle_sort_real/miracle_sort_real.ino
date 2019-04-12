#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <SD.h>
#define SD_ChipSelectPin 4
TMRpcm tmrpcm;
void setup() {
  Serial.begin(9600);
  tmrpcm.speakerPin=9;
  if(!SD.begin(SD_ChipSelectPin)){
    Serial.println("SD fails");
    return;
  }
  tmrpcm.setVolume(5); 
}

void play(){
  tmrpcm.stopPlayback();

  tmrpcm.play("1.wav");

  delay(240000);
  return;
  }

void loop() {
  // put your main code here, to run repeatedly:
  play();
}
