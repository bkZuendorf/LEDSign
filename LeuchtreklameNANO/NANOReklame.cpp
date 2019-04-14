#include "NANOReklame.h"

void NANOReklame::init() {   
  pinMode(ENABLEOUTPUT, OUTPUT);   
  pinMode(SHIFTREGCLR, OUTPUT);   
  pinMode(SERIN, OUTPUT);   
  pinMode(SHIFTREGCLK, OUTPUT);   
  pinMode(REGCLK, OUTPUT);   
  pinMode(BUTTON, INPUT);
  pinMode(SERCLR, OUTPUT);   

  digitalWrite(SERCLR, HIGH);   // active low!
  digitalWrite(ENABLEOUTPUT, HIGH); // active low!
  digitalWrite(SHIFTREGCLR, HIGH); // active low!
}
  
void NANOReklame::unsetAll() {
  this->value = 0;
}

void NANOReklame::setAll() {
  this->value=0xFF;
}

void NANOReklame::allOn() {
  this->setAll();
  this->commit();
}
  
void NANOReklame::allOff() {
  this->unsetAll();
  this->commit();
}
  
void NANOReklame::on(int index) {
  this->set(index);
  this->commit();
}

void NANOReklame::off(int index) {
  this->unset(index);
  this->commit();
}

void NANOReklame::set(int index) {
  if(index>=0 && index<8)
    this->value |= (1 << index);
}

void NANOReklame::unset(int index) {
  if(index>=0 && index<8)
    this->value &= ~(1 << index);
}

void NANOReklame::commit() {
  byte temp = reorderBits(this->value);
  
  for(int i=0; i<8; i++) {
    digitalWrite(SERIN, (temp>>i) & 0x01); // Lege Pegel des jeweiligen Bits an Eingang
    // aktiviere Schiebeaktion
    digitalWrite(SHIFTREGCLK, HIGH); 
    delay(1);
    digitalWrite(SHIFTREGCLK, LOW);       
    delay(1);
  }
  // schalte Ausgang aus -  führt zum blinken
  // digitalWrite(ENABLEOUTPUT, HIGH); // active low!
  // Übertrage Schiebregisterinhalt an Ausgangsregister
  digitalWrite(REGCLK, HIGH); 
  delay(1);
  digitalWrite(REGCLK, LOW); 
  // schalte Ausgang ein
  delay(1);
  digitalWrite(ENABLEOUTPUT, LOW); // active low!
}  
