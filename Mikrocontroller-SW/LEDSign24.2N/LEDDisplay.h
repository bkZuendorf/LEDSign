#include <arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class LEDDisplay {   
  byte          value;
  unsigned int  buttonCnt=0;
  unsigned int  anasum=0;
  byte          duty=255;
  float         temperature;

public:
  static LEDDisplay* TheDisplay;
  void   onButton();
  void   onTimer();

public:  
  LEDDisplay();
  
  void init();

  // direktes Setzen von Werten einschl. Übertragung an die Ausgänge
  void allOn();
  void allOff();
  void invert();
  
  void on(int index);
  void off(int index);

  // Werte ermitteln
  int   getBrightness() const  { return anasum/10;   } // 0 ... 1023 -> hell ... dunkel 
  float getTemperature() const { return temperature; } // in °C
  int   getFullTemperature() const { return round(temperature); } // in ganzen °C
  bool  isButtonHit()          { bool ret=buttonCnt!=0; buttonCnt=0; return ret; } 
  byte  getDuty() const        { return this->duty; }


  void debugPrint();

  // Setzen von Werten ohne Übertragung an den Ausgang
  void unsetAll();
  void setAll();
  void set(int index);
  void unset(int index);
  
  // Übertragen des Werts an den Ausgang
  void commit();
};
