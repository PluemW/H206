#include <H206.h>
H206::H206;

void setup()
{
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), COUNT, CHANGE);
  Serial.begin(9600);
}
 
void H206::readspeed()
{
  // put your main code here, to run repeatedly:
  if ((millis() - gulStart_Read_Timer) >= 500)
  {
    gsRPM = usRead_RPM();
 
    if (gsRPM >= 300)
    {
      gsRPM = gsRPM - 230;
    }
    Serial.print("RPM: ");
    Serial.println(gsRPM);
    gulStart_Read_Timer = millis();
    }
}
 
short H206::usRead_RPM(void)
{
  unsigned long ulRPM = 0;
  unsigned long ulTimeDif = 0;
 
  detachInterrupt(digitalPinToInterrupt(ENCODER_PIN));
 
  ulTimeDif = millis() - gulStart_Timer;
  ulRPM = 60000 * gulCount;
  ulRPM = ulRPM / ulTimeDif;
  ulRPM = ulRPM / RESOLUTION;c
  //usRPM = ((60*1000*gulCount)/ulTimeDif)/RESOLUTION;
 
  gulCount = 0;
  gulStart_Timer = millis();
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), COUNT, CHANGE);
 
  return (short)ulRPM;
}
 
void H206::COUNT(void)
{
  gulCount++;
  gusChange = 1;
}
