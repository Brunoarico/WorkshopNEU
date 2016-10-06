const byte pin_player_1 = 2;
const byte pin_player_2 = 3;

const byte led_player_1 = 12;
const byte led_player_2 = 11;
const byte led_pilot = 10;

bool flag = false;

void setup() {
  DDRB = B00011100; //define 10, 11, 12 como saidas
  DDRD = B00000000; //define 2,3 como entradas
  PORTD = B00001100; // ativa o pull_up nos pinos 2, 3 (é o mesmo que escrever HIGH)
  attachInterrupt(digitalPinToInterrupt(pin_player_1), p1, FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_player_2), p2, FALLING);
}
void p1(){
  if(!flag) {
    digitalWrite(led_player_1, HIGH);
    flag = true;
  }
}

void p2(){
  if(!flag) {
    digitalWrite(led_player_2, HIGH);
    flag = true;
  }
}


void loop() {
  
  delay(2000);
  digitalWrite(led_pilot, HIGH);
  delay(2000);
  digitalWrite(led_pilot, LOW);
  if(flag) {
    delay(1000);
    digitalWrite(led_player_1, LOW);
    digitalWrite(led_player_2, LOW);
    flag = false;
  }

}
