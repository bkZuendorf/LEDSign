/*
 * Use Board Arduino Nano 
 * Import following Libraries
 *  - OneWire
 *  - DallasTemperature
 *  
 *  Für Boards v24.2 und v24.3
 */
 #include "LEDDisplay.h"

LEDDisplay display;

void setup() {
  display.init();  // display initialisieren
  Serial.begin(9600);
}

void loop() {  
  //display.debugPrint();
  // Standardanwendung Temperaturanzeige von 16, 18, 20, 22, 24, 26, 30°C
  float t = display.getTemperature();
  display.unsetAll(); 
  display.set(0);
  if(t>=16) {
    display.set(1);
  }
  if(t>=18) {
    display.set(2);
  }
  if(t>=20) {
    display.set(3);
  }
  if(t>=22) {
    display.set(4);
  }
  if(t>=24) {
    display.set(5);
  }
  if(t>=26) {
    display.set(6);
  }
  if(t>=30) {
    display.set(7);
  }
  display.commit();
  

  // Wenn der Knopf betätigt wurde, Animationsbeispiele einmalig durchfahren
  if(display.isButtonHit()) {
    // invertiere letztes Muster
    display.invert();
    delay(500);
    
    display.allOff();
    
    // mache LED 1 bis LED 8 an
    for(int i=0; i<8; i++) {
      display.on(i);
      delay(100);
    }
    
    // mache LED 8 bis LED 1 aus
    for(int i=7; i>=0; i--) {
      display.off(i);
      delay(100);
    }
      
    // mache alle LEDs an
    display.allOn(); 
    delay(500);
    // mache alle LEDs aus
    display.allOff();
    delay(500);
  
  
    for(int j=0; j<10; j++) {
      // mache LED 1 bis LED 8 schnell an
      for(int i=0; i<8; i++) {
        display.on(i);
        delay(10);
      }
      
      // mache LED 8 bis LED 1 schnell aus
      for(int i=7; i>=0; i--) {
        display.off(i);
        delay(10);
      }  
    }
  
    // mache LED 1 bis LED 8 langsam an
    for(int i=0; i<8; i++) {
      display.on(i);
      delay(1000);
    }
    
    // mache LED 8 bis LED 1 langsam aus
    for(int i=7; i>=0; i--) {
      display.off(i);
      delay(1000);
    }
  
     // mache alle LEDs aus
    display.allOff();
    delay(500);
  }
}
