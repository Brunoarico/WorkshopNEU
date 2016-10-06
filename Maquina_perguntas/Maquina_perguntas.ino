const byte pin_player_1 = 2;
const byte pin_player_2 = 3;

const byte led_player_1 = 12;
const byte led_player_2 = 11;
const byte led_pilot = 10;

bool flag = false;


void setup() {
  //DDRB = B00011100;
  for(int i = 10; i<=12; i++) pinMode(i, OUTPUT);
  for(int i = 2; i<=3; i++) pinMode(i, INPUT_PULLUP);
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
