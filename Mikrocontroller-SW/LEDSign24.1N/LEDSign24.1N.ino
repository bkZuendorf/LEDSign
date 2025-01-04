#include "NANOReklame.h"

NANOReklame reklame;

void setup() {
  reklame.init();  // Reklame initialisieren
}

void loop() {  
  reklame.defaultDiming(); // Diming der Ausgänge abhängig von Umgebungslicht einstellen

  // mache alle LEDs an
  reklame.allOn(); 
  delay(500);
    
  // mache alle LEDs aus
  reklame.allOff();
  delay(500);

  for(int j=0; j<10; j++) {
    // mache LED 1 bis LED 8 schnell an
    for(int i=0; i<8; i++) {
      reklame.on(i);
      delay(10);
    }
    
    // mache LED 8 bis LED 1 schnell aus
    for(int i=7; i>=0; i--) {
      reklame.off(i);
      delay(10);
    }  
  }

  // mache LED 1 bis LED 8 langsam an
  for(int i=0; i<8; i++) {
    reklame.on(i);
    delay(1000);
  }
  
  // mache LED 8 bis LED 1 langsam aus
  for(int i=7; i>=0; i--) {
    reklame.off(i);
    delay(1000);
  }

   // mache alle LEDs aus
  reklame.allOff();
  delay(500);
}
