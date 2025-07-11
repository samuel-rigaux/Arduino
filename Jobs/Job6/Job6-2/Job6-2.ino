// Broches des LED
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);  // allume LED1
  delay(500);                

  digitalWrite(led2, HIGH);  // allume LED2
  delay(500);                

  digitalWrite(led3, HIGH);  // allume LED3
  delay(500);              

  digitalWrite(led1, LOW);   // éteint LED1
  digitalWrite(led2, LOW);   // éteint LED2
  digitalWrite(led3, LOW);   // éteint LED3 
  delay(500);
}

