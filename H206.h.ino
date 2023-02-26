#ifndef H206_H_
#define H206_H_
 
#define ENCODER_PIN 2
#define RESOLUTION 40

class H206{
 private:
  unsigned long gulCount = 0;
  unsigned long gulStart_Timer = 0;
  unsigned short gusChange = 0;
  unsigned long gulStart_Read_Timer = 0;
  short gsRPM = 0;
 public:
  void readspeed();
  short usRead_RPM(void);
  void COUNT(void);
};
#endif
