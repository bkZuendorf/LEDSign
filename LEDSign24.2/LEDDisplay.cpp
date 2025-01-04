#include "LEDDisplay.h"

// Pinbelegung v24.2
#define ENABLEOUTPUT  6 
#define SHIFTREGCLR   7
#define SERIN         8
#define SHIFTREGCLK   5 
#define REGCLK        4 
#define BUTTON        2
#define LDR           A0
#define TEMPSENSOR    9

OneWire oneWire(TEMPSENSOR);
DallasTemperature tempSensor(&oneWire);

LEDDisplay* LEDDisplay::TheDisplay=NULL;

ISR(TIMER1_COMPA_vect) {
  LEDDisplay::TheDisplay->onTimer();
}

void ISR_onButton() {
  LEDDisplay::TheDisplay->onButton();
}

LEDDisplay::LEDDisplay() {
  TheDisplay=this;
}

void LEDDisplay::init() {   
  pinMode(ENABLEOUTPUT, OUTPUT);   
  pinMode(SHIFTREGCLR, OUTPUT);   
  pinMode(SERIN, OUTPUT);   
  pinMode(SHIFTREGCLK, OUTPUT);   
  pinMode(REGCLK, OUTPUT);   
  pinMode(BUTTON, INPUT);

  analogWrite(ENABLEOUTPUT, 255); // active low!
  digitalWrite(SHIFTREGCLR, HIGH); // active low!

  // Timer 1 - 16 bit Timer, for conversion
  cli();//stop all interrupts

  TCCR1A = 0; //Register definiert zurücksetzen
  TCCR1B = 0; //zuerst Register definiert zurücksetzen
  TCNT1 = 0; // reset counter value

  // Compare Wert für Auslösung alle halbe Sekunde
  OCR1A = 6250; //rechne 16MHz / 256 / 10Hz = 6250
  TCCR1B |= (1 << CS12) | (0 << CS11) | (0 >> CS10); //Prescale auf 256
  TCCR1B |= (1 << WGM12); // turn on CTC mode
  
  TIMSK1 |= (1 << OCIE1A); // aktiviert den Interrupt

  sei();//allow interrupts

  // button interrupt
  attachInterrupt(digitalPinToInterrupt(BUTTON), ISR_onButton, RISING);

  // no blocking temp conversion
  tempSensor.setWaitForConversion(false);
  anasum = 10*analogRead(LDR);
}

void LEDDisplay::onButton() {
  this->buttonCnt++;
}

void LEDDisplay::onTimer() { 
  // je heller -> kleinerer LDR Widerstand -> geringerer Digitalwert (gut nutzbarer Bereich ca. 200-1000)
  int anaval = this->getBrightness();
  anasum += analogRead(LDR) - anaval; // gleitender Mittelwert über 10 Werte

  // entscheidet über diming effekt!
  this->duty = map(constrain(anaval, 200, 900), 200, 900, 0, 250); 
  
  analogWrite(ENABLEOUTPUT, this->duty);

  if(tempSensor.isConversionComplete()) {
    this->temperature = tempSensor.getTempCByIndex(0);
    tempSensor.requestTemperatures(); 
  }
}

void LEDDisplay::unsetAll() {
  this->value = 0;
}

void LEDDisplay::setAll() {
  this->value=0xFF;
}

void LEDDisplay::allOn() {
  this->setAll();
  this->commit();
}
  
void LEDDisplay::allOff() {
  this->unsetAll();
  this->commit();
}
  
void LEDDisplay::on(int index) {
  this->set(index);
  this->commit();
}

void LEDDisplay::off(int index) {
  this->unset(index);
  this->commit();
}

void LEDDisplay::invert() {
  this->value = ~this->value;
  this->commit();
}

void LEDDisplay::set(int index) {
  if(index>=0 && index<8)
    this->value |= (1 << index);
}

void LEDDisplay::unset(int index) {
  if(index>=0 && index<8)
    this->value &= ~(1 << index);
}

void LEDDisplay::debugPrint() {
  
  Serial.print("Temperatur: ");
  Serial.print(this->getTemperature());
  Serial.println("°C");

  Serial.print("Helligkeit (raw): ");
  Serial.print(analogRead(LDR));
  Serial.println(" (0..1023)");
  
  Serial.print("Helligkeit: ");
  Serial.print(this->getBrightness());
  Serial.println(" (0..1023)");

  Serial.print("Duty: ");
  Serial.print(this->getDuty());
  Serial.println(" (0..255)");

  Serial.print("Taster: ");
  Serial.print(this->isButtonHit());
  Serial.println(" (0/1)");
}

void LEDDisplay::commit() {
  byte temp = this->value;
  const byte del=10;
  
  for(int i=0; i<8; i++) {
    digitalWrite(SERIN, (temp>>i) & 0x01); // Lege Pegel des jeweiligen Bits an Eingang
    delayMicroseconds(del);
    // aktiviere Schiebeaktion
    digitalWrite(SHIFTREGCLK, HIGH); 
    delayMicroseconds(del);
    digitalWrite(SHIFTREGCLK, LOW);       
    delayMicroseconds(del);
  }
  // Übertrage Schiebregisterinhalt an Ausgangsregister
  digitalWrite(REGCLK, HIGH); 
  delayMicroseconds(del);
  digitalWrite(REGCLK, LOW); 
  // schalte Ausgang ein
  delayMicroseconds(del);
}  
