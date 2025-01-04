#include "arduino.h"

#define D_ENABLEOUTPUT 5
#define D_SHIFTREGCLR 7
#define D_SERIN 8 
#define D_SHIFTREGCLK 3
#define D_REGCLK 2
#define D_BUTTON 11
#define D_LDR A0

inline int reorderBits(int value) {
  return value;
} 

class NANOReklame {  
  const int ENABLEOUTPUT = D_ENABLEOUTPUT; 
  const int SHIFTREGCLR = D_SHIFTREGCLR;
  const int SERIN = D_SERIN;
  const int SHIFTREGCLK = D_SHIFTREGCLK; 
  const int REGCLK = D_REGCLK; 
  const int BUTTON = D_BUTTON;
  const int LDR = D_LDR;
  byte value;
  byte cnt=0;
  unsigned int anasum=0;
public:
  byte duty=255;
  static NANOReklame* TheReklame;
  void onPWM();

public:  
  NANOReklame();
  void init();

  // Setzen von Werten ohne Übertragung an den Ausgang
  void unsetAll();
  void setAll();
  void set(int index);
  void unset(int index);
  
  // Übertragen des Werts an den Ausgang
  void commit();

  // direktes Setzen von Werten 
  void allOn();
  void allOff();
  
  void on(int index);
  void off(int index);

  void defaultDiming();
  byte getLDRValue();
};
