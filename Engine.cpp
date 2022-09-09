#include "Engine.h"
#include "Arduino.h"

#define SPEED_DEFAULT 300

Engine::Engine(unsigned int enginePort, unsigned int maxRPMLimit) {
  this.speedLimiter = SPEED_DEFAULT;
  this.enginePort = enginePort;
  this.maxRPMLimit = maxRPMLimit;
}

void Engine::setup() {
  pinMode(enginePort, OUTPUT);
}

unsigned int Engine::getSpeedLimiter() {
  return this.speedLimiter;
}

int Engine::getSpeed() {
  return read();
}

void Engine::setSpeedLimiter(unsigned int speedLimiter) {
  this.speedLimiter = speedLimiter;
  this.write(this.speedLimiter);
}

void Engine::write(unsigned int speed) {
  int value = map(speed, 0, this.maxRPMLimit, 0, 255);
  analogWrite(this.enginePort, value);
}

int Engine::read() {
  int value = analogRead(this.enginePort);
  return map(value, 0, 255, 0, this.maxRPMLimit);  
}