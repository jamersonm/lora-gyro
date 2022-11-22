#include "heltec.h"
#include "Gyro.h"

#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

unsigned int counter = 0;
String rssi = "RSSI --";
String packSize = "--";
String packet ;

void setup()
{
   //WIFI Kit series V1 not support Vext control
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, false /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  delay(1500);
  Serial.begin(9600);
  configureCompass();
  delay(1000);
}

void loop()
{
  loopCompass();
  printCompass();
  // send packet
  LoRa.beginPacket();
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print("Yaw rate ");
  LoRa.println(getYawrate());
  LoRa.print(" Yaw ");
  LoRa.println(getYaw());
  LoRa.endPacket();                       // wait for a second
}
