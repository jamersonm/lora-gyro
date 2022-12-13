#ifndef COMPASS_H
#define COMPASS_H

#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
float yaw = 0;
int divider;
unsigned long timer = millis();

void calibrateCompass()
{
    mpu.calcOffsets(true, true);
}

void configureCompass()
{
    Wire.begin();
    mpu.begin();
    calibrateCompass();
}

float getYawrate(){return mpu.getAngleZ();}
float getYaw(){return yaw;}

void loopCompass()
{
  mpu.fetchData();
  unsigned long timer_new = millis();
  float dt = (timer_new - timer)*0.001;
  yaw += mpu.getGyroZ()*dt;
  timer = timer_new;
  
  //set interval 0 <= angle < 360
  if(yaw >= 360)
  {
    divider = yaw / 360;
    for(int i = 0; i < divider; i++)
        yaw = yaw - 360;
  }
  else if(yaw < 0)
  {
    divider = yaw / 360;
    yaw = yaw + 360;
    for(int i = 0; i < divider; i++)
        yaw = yaw + 360;
  }
}

void printCompass()
{
    Serial.print("Compass: ");
    Serial.print(yaw);
    Serial.println("°");
}

int getCompass()
{
    if(yaw >= 338 || yaw <= 22){return 1;}
    else if(yaw >= 23 && yaw <= 67){return 2;}
    else if(yaw >= 68 && yaw <= 112){return 3;}
    else if(yaw >= 113 && yaw <= 157){return 4;}
    else if(yaw >= 158 && yaw <= 202){return 5;}
    else if(yaw >= 203 && yaw <= 247){return 6;}
    else if(yaw >= 248 && yaw <= 292){return 7;}
    else if(yaw >=293 && yaw <= 337){return 8;}
    return 0;
}

#endif