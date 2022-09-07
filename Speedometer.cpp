#include "Speedometer.h"
#include "Arduino.h"

Speedometer::Speedometer() {
  this.pulses  = 0;
  this.rpm     = 0;
  this.timeOld = 0;
  this.pulsesAround = 20;
}

Speedometer::Speedometer(unsigned int pulsesAround) {
  this.pulses  = 0;
  this.rpm     = 0;
  this.timeOld = 0;
  this.pulsesAround = pulsesAround;  
}

// --- Interrupção ---
void Speedometer::incrementCounterValue()
{
  //Incrementa contador
  pulses++;
}

void Speedometer::attach() {
  //Interrupcao 0 - pino digital 2
  //Aciona o contador a cada pulso
  attachInterrupt(0, incrementCounterValue, RISING);
}

unsigned long Speedometer::delta() {
  return millis() - timeOld;
}

void Speedometer::detach() {
  detachInterrupt(0);
}

void Speedometer::setup() {
  Serial.begin(115200);
  pinMode(2, INPUT);   

  attach();
}

int Speedometer::getSpeed() {
  //Atualiza contador a cada segundo
  unsigned long diff = this.delta();
  if (diff >= 1000)
  {
    //Desabilita interrupcao durante o calculo
    detach();
    rpm = (60 * 1000 / pulsesAround ) / diff * pulses;
    timeOld = millis();
    pulses = 0;

    //Habilita interrupcao
    attach();    
  }

  return rpm;
}