#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buzzerPin = 8;

// Fréquences des notes (en Hz)
#define LA5 880
#define MI5 659
#define DO6 1047
#define SI5 988
#define SOL5 784

// Mélodie : "CIEL tu m'avais pas dit que tu étais une magicienne"
int melody[] = {
  LA5, MI5, MI5,
  DO6, MI5,
  DO6, SI5, MI5,
  SOL5, LA5, MI5,
  SOL5, LA5, MI5
};

// Durée de chaque note (en ms)
int durations[] = {
  300, 200, 200,
  300, 200,
  300, 300, 200,
  300, 300, 200,
  300, 400, 500
};

void setup() {
  lcd.begin(16, 2);
  lcd.print("CIEL - GIMS!");

  for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
    tone(buzzerPin, melody[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50); // petite pause entre les notes
  }
}

void loop() {
  // rien à faire ici
}
