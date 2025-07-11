// Broches des LED
const int led1 = 8;
const int led2 = 9;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);  // allume LED1
  digitalWrite(led2, HIGH);  // allume LED2
  delay(500);                // pause 500 ms

  digitalWrite(led1, LOW);   // éteint LED1
  digitalWrite(led2, LOW);   // éteint LED2
  delay(500);                // pause 500 ms
}
