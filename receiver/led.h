float yaw;
int controle;

#define n 17
#define ne 12
#define e 32
#define se 33
#define s 25
#define so 13
#define o 23
#define no 2

void acenderLed(int pin)
{
  digitalWrite(n, LOW);
  digitalWrite(ne, LOW);
  digitalWrite(e, LOW);
  digitalWrite(se, LOW);
  digitalWrite(s, LOW);
  digitalWrite(so, LOW);
  digitalWrite(o, LOW);
  digitalWrite(no, LOW);
  digitalWrite(pin, HIGH);
}

void ALLacenderLed()
{
  acenderLed(n);
  delay(1000);
  acenderLed(ne);
  delay(1000);
  acenderLed(e);
  delay(1000);
  acenderLed(se);
  delay(1000);
  acenderLed(s);
  delay(1000);
  acenderLed(so);
  delay(1000);
  acenderLed(o);
  delay(1000);
  acenderLed(no);
}

void loopLeds()
{
  if(yaw >= 338 || yaw <= 22){acenderLed(n);}
  else if(yaw >= 23 && yaw <= 67){acenderLed(ne);}
  else if(yaw >= 68 && yaw <= 112){acenderLed(e);}
  else if(yaw >= 113 && yaw <= 157){acenderLed(se);}
  else if(yaw >= 158 && yaw <= 202){acenderLed(s);}
  else if(yaw >= 203 && yaw <= 247){acenderLed(so);}
  else if(yaw >= 248 && yaw <= 292){acenderLed(o);}
  else if(yaw >=293 && yaw <= 337){acenderLed(no);}
}

void converterYaw(String* packet)
{
  yaw = packet->toFloat();
  loopLeds();
}

void configureLeds()
{
  pinMode(n, OUTPUT);
  pinMode(ne, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(se, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(so, OUTPUT);
  pinMode(o, OUTPUT);
  pinMode(no, OUTPUT);
  ALLacenderLed();
}
