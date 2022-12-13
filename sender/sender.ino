#include "compass.h"
#include "heltec.h"

#define BAND    915E6
String rssi = "RSSI --";
String packSize = "--";
String packet ;
unsigned long tempo = millis();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Heltec.begin(false, true, false, true, BAND);
  configureCompass();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  loopCompass();
  printCompass();
  if((millis() - tempo) < 100){
    digitalWrite(LED, HIGH);
    LoRa.beginPacket();
    LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
    LoRa.print(getYaw());
    LoRa.endPacket();
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  if((millis() - tempo) > 200){
    tempo = millis();
  }
}
