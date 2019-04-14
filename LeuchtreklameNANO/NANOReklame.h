#include "arduino.h"

// Aktiviere hier die genutzte Hardwareplattform
#include "doubleSide.h"
//#include "singleSide.h"
//#include "timVersion.h"

class NANOReklame {
  const int ENABLEOUTPUT = D_ENABLEOUTPUT; 
  const int SHIFTREGCLR = D_SHIFTREGCLR;
  const int SERIN = D_SERIN;
  const int SERCLR = D_SERCLR;
  const int SHIFTREGCLK = D_SHIFTREGCLK; 
  const int REGCLK = D_REGCLK; 
  const int BUTTON = D_BUTTON;
  const int LDR = D_LDR;
  byte value;

public:
  
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
};
