#include "NANOReklame.h"

NANOReklame* NANOReklame::TheReklame=NULL;

ISR(TIMER2_OVF_vect) {
  if(!NANOReklame::TheReklame) return;
  NANOReklame::TheReklame->onPWM();
}

NANOReklame::NANOReklame() {
  TheReklame=this;
}

void NANOReklame::init() {   
  pinMode(ENABLEOUTPUT, OUTPUT);   
  pinMode(SHIFTREGCLR, OUTPUT);   
  pinMode(SERIN, OUTPUT);   
  pinMode(SHIFTREGCLK, OUTPUT);   
  pinMode(REGCLK, OUTPUT);   
  pinMode(BUTTON, INPUT);

  digitalWrite(ENABLEOUTPUT, HIGH); // active low!
  digitalWrite(SHIFTREGCLR, HIGH); // active low!
  
  cli();//stop all interrupts
  
  TCCR2A = 0; // Normaler Modus
  TCCR2B = (1 << CS10); // System clock
  
  TCNT2  = 0; // initialisierungswert
    
  TIMSK2 |= (1 << TOIE2);  // interrupt timer overflow
  
  sei();//allow interrupts

  anasum = 5*analogRead(LDR);
}

void NANOReklame::onPWM() {
  this->cnt++;  // überlauf bei 255
  if(this->cnt < this->duty)
    digitalWrite(ENABLEOUTPUT, LOW);
  else
    digitalWrite(ENABLEOUTPUT, HIGH);
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
  const byte del=1;
  
  for(int i=0; i<8; i++) {
    digitalWrite(SERIN, (temp>>i) & 0x01); // Lege Pegel des jeweiligen Bits an Eingang
    delay(del);
    // aktiviere Schiebeaktion
    digitalWrite(SHIFTREGCLK, HIGH); 
    delay(del);
    digitalWrite(SHIFTREGCLK, LOW);       
    delay(del);
  }
  // schalte Ausgang aus -  führt zum blinken
  // digitalWrite(ENABLEOUTPUT, HIGH); // active low!
  // Übertrage Schiebregisterinhalt an Ausgangsregister
  digitalWrite(REGCLK, HIGH); 
  delay(del);
  digitalWrite(REGCLK, LOW); 
  // schalte Ausgang ein
  delay(del);
  digitalWrite(ENABLEOUTPUT, LOW); // active low!
}  

byte NANOReklame::getLDRValue() {
  int anaval = anasum/5;
  anasum += analogRead(LDR)-anaval; // gleitender Mittelwert über 5 Werte
  return anaval;
}

void NANOReklame::defaultDiming() {
  // je heller -> kleinerer LDR Widerstand -> geringerer Digitalwert (gut nutzbarer Bereich ca. 120-180)
  byte a=this->getLDRValue();
  float f=0;
  if(a<20)
    f=0;
  else if(a>230) 
    f=1;
  else 
    f = (float)(a-20)/(230-20);

  this->duty = (1.f-f)*(255-30)+30;
}
