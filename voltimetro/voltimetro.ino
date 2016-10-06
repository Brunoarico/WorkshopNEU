#include <EEPROM.h>

#define S_speed 9600
#define R1 100.0
#define R2 49.0
const int B_read = 3;
const int B_show = 2;

void setup() {
  pinMode(B_read, INPUT_PULLUP);
  pinMode(B_show, INPUT_PULLUP);
  Serial.begin (S_speed);
  analogReference (DEFAULT);
}

float real_value (float in_Ard) {
  return (R1 + R2) / R2 * in_Ard;
}

float signalTovoltage (float signl, float ref) {
  return ref * (float)signl / 1024.0;
}

void read_voltage() {
  int voltage, BL, BH;
  Serial.println ("Lendo...");
  voltage = analogRead (A0);
  BL = lowByte (voltage);
  BH = highByte (voltage);
  EEPROM.write (1, BL);
  EEPROM.write (2,BH);
}

float Show () {
  float stored;
  stored = word(EEPROM.read(2), EEPROM.read(1));
  stored = signalTovoltage (stored, 5);
  return real_value (stored);
}

void loop () {
  
  if (!digitalRead (B_show)){
    Serial.print (Show());
    Serial.println ("V");
    while(!digitalRead (B_show)) {}
  }
  
  if (!digitalRead (B_read)){
    read_voltage();
    while(!digitalRead (B_read)) {}
  }
  
}
