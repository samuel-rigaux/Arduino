# 🔌 Projet Arduino – Introduction et Applications

> **Arduino**, c’est comme une relation électrique parfaite : une connexion bien établie, sans jamais trop de résistance. ⚡

## 🛠️ Introduction

Bienvenue dans ce projet d’initiation à Arduino. Ici, tu vas explorer les bases de l’électronique et de la programmation en réalisant une série de 15 petits projets appelés **Jobs**.

Avant de commencer :
- Inscris-toi sur **[Tinkercad](https://www.tinkercad.com/)** pour concevoir et tester virtuellement tes montages.
- Pour chaque job :
  - Crée un **schéma sur Tinkercad**
  - Exporte-le au **format PNG**
  - Intègre ton **code Arduino**
  - Réalise le **montage réel avec le kit Arduino**
---

## 🧪 Job 1 – Mise sous tension de l’Arduino

🔋 **Objectif :** alimenter correctement l'Arduino avec le matériel fourni.

📷 **Image du montage :**  
![](Jobs\Job1\Job1.png)


---

## 🔢 Job 2 – Calcul de résistance pour LED

🧮 **Énoncé :**  
- Tension LED : 2V  
- Tension Arduino : 5V  
- Courant souhaité : 10 mA  

**Formule utilisée :**

R = (V_Alimentation - V_LED) / I

**Calcul :**

R = (5 - 2) / 0.01 = 300 ohms

**Résultat :**

Il faut une résistance de 300 ohms pour obtenir un courant de 10 mA à travers la LED

## 💡 Job 3 – LED toujours allumée

🔌 **Sans code :** réalise le montage d’une LED allumée en permanence.

📷 **Image du montage :**  
![](Jobs\Job3\Job3.png)

---

## 🔗 Job 4 – Montage série et parallèle

🔋 **Montage 1 :** LED en série  
![](Jobs\Job4\Job4-1.png)

🔋 **Montage 2 :** LED en parallèle  
![](Jobs\Job4\Job4-2.png)

---

## 🧰 Job 5 – Installation de l’IDE Arduino

🖥️ **Objectif :** installer et configurer l’IDE Arduino.

📎 _Lien vers l’IDE : [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)_


---

## ✨ Job 6 – LED synchrones et asynchrones

🧠 **Synchrones :**

```
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
```


**🧠 Asynchrones :**
```
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
```

**📷 Montage commun :**
![](Jobs\Job6\Job6.png)

## 🔁 Job 7 – Clignotement séquentiel de 8 LED

**code :**

```
// Tableau contenant les broches des 8 LEDs
int leds[8] = {1, 2, 3, 4, 5, 6, 7, 8};  // change les numéros si besoin

void setup() {
  // Définir chaque broche comme sortie
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(leds[i], HIGH);  // allume la LED
    delay(200);                   // attend 200 ms
    digitalWrite(leds[i], LOW);   // éteint la LED
  }
}
```

📷 Image du montage :
![](Jobs\Job7\Job7.png)


## 🔄 Job 8 – Allumage progressif d’une LED

**code :**

```
const int ledPin = 4;  // La LED est connectée à une broche PWM (ex : 9)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Fade in (augmentation progressive de la luminosité)
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);  // PWM : de 0 (éteint) à 255 (plein)
    delay(10);  // délai pour rendre la montée visible
  }

  delay(1000); // pause quand c’est allumé à fond (facultatif)

  // (optionnel) fade out si tu veux aussi une extinction progressive :
  /*
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(10);
  }
  delay(1000);
  */
}
```


## 🔘 Job 9 – LED multifonction avec bouton

**📋 Fonctions :**

Appui 1x : LED ON

Appui 2x : LED reste allumée

Appui 3x : LED clignote

Appui long : LED OFF

code :

```
const int ledPin = 9;
const int buttonPin = 2;

int buttonState;
int lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

unsigned long clickTimer = 0;
int clickCount = 0;
bool ledOn = false;
bool ledBlink = false;

unsigned long blinkTimer = 0;
int blinkInterval = 500;

unsigned long buttonPressStart = 0;
bool longPressDetected = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // bouton actif LOW
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Appui détecté
    if (reading == LOW && lastButtonState == HIGH) {
      buttonPressStart = millis();
      longPressDetected = false;
    }

    // Relâchement
    if (reading == HIGH && lastButtonState == LOW) {
      unsigned long pressDuration = millis() - buttonPressStart;

      if (pressDuration > 1000) { // appui long
        ledOn = false;
        ledBlink = false;
        clickCount = 0;
        longPressDetected = true;
      } else {
        clickCount++;
        clickTimer = millis();
      }
    }
  }

  // Gestion des clics multiples
  if (clickCount > 0 && (millis() - clickTimer > 400) && !longPressDetected) {
    if (clickCount == 1) {
      // Rien de spécial, juste LED allumée pendant appui (déjà géré)
    } else if (clickCount == 2) {
      ledOn = true;
      ledBlink = false;
    } else if (clickCount == 3) {
      ledBlink = true;
      ledOn = false;
    }
    clickCount = 0;
  }

  // Affichage LED selon l’état
  if (reading == LOW && clickCount == 0) {
    // Appui unique : LED allumée temporairement
    digitalWrite(ledPin, HIGH);
  } else if (ledOn) {
    digitalWrite(ledPin, HIGH);
  } else if (ledBlink) {
    if (millis() - blinkTimer >= blinkInterval) {
      blinkTimer = millis();
      digitalWrite(ledPin, !digitalRead(ledPin));
    }
  } else {
    digitalWrite(ledPin, LOW);
  }

  lastButtonState = reading;
}
``` 
**📷 Image du montage :**

![](Jobs\Job9\Job9.png)


## 🎚️ Job 10 – Potentiomètre + 2 LED

**🎛️ Fonction :** Une LED s’allume pendant que l’autre s’éteint progressivement, selon la position du potentiomètre.

**code :**
```
const int potPin = A0;     // Broche analogique pour le potentiomètre
const int led1 = 9;        // LED 1 sur pin PWM
const int led2 = 10;       // LED 2 sur pin PWM

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);           // Lecture du potentiomètre (0 à 1023)
  int led1Brightness = map(potValue, 0, 1023, 0, 255);         // LED 1 augmente
  int led2Brightness = map(potValue, 0, 1023, 255, 0);         // LED 2 diminue

  analogWrite(led1, led1Brightness);
  analogWrite(led2, led2Brightness);
}
```


## 🌀 Job 11 – LED + ventilateur contrôlés par bouton

**code:**
```const int buttonPin = 2;
const int ledPin = 9;
const int fanPin = 10;

bool ledActive = false;
bool fanActive = false;

unsigned long ledStartTime = 0;
bool sequenceStarted = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Bouton actif à LOW
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Appui sur le bouton (flanc descendant)
  static bool lastButtonState = HIGH;
  if (buttonState == LOW && lastButtonState == HIGH) {
    if (!sequenceStarted && !fanActive) {
      // Démarrage de la séquence
      digitalWrite(ledPin, HIGH);
      ledActive = true;
      ledStartTime = millis();
      sequenceStarted = true;
    } else if (fanActive) {
      // Bouton pressé pendant que le ventilateur tourne => l'éteindre
      digitalWrite(fanPin, LOW);
      fanActive = false;
      sequenceStarted = false;
    }
    delay(50); // anti-rebond rapide
  }

  lastButtonState = buttonState;

  // Gestion du temps de la LED
  if (ledActive && (millis() - ledStartTime >= 15000)) {
    digitalWrite(ledPin, LOW);       // éteindre LED
    digitalWrite(fanPin, HIGH);      // allumer ventilateur
    ledActive = false;
    fanActive = true;
  }
}
```

**📋 Fonctionnement :**

Bouton pressé → LED ON

15 sec après → LED OFF + ventilateur ON

Appui → ventilateur OFF

**📷 Image du montage :**

![](Jobs\Job11\Job11.png)

## 🖥️ Job 12 – Affichage “Hello World !” sur LCD

**code :**
```
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Adresse I2C la plus courante pour un LCD : 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);  // (adresse, colonnes, lignes)

void setup() {
  lcd.init();              // initialisation de l’écran
  lcd.backlight();         // allume le rétroéclairage
  lcd.setCursor(0, 0);     // position : colonne 0, ligne 0
  lcd.print("Hello World !");
}

void loop() {
  // rien ici, le message reste affiché
}
```
**📷 Image du montage :**

![](Jobs\Job12\Job12.png)


## 🖥️ Job 12 bis (perso) – Jouer CIEL de GIMS

**code :**

```
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
```

**📷 Image et vidéo du montage :**

![](Jobs\Job12\CIEL_GIMS\job12.JPG)

![](Jobs\Job12\CIEL_GIMS\vidéo.mov)



## 😊 Job 13 – Smiley sur LCD

**code :**

```
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Définition du smiley
byte smiley[8] = {
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

void setup() {
  lcd.begin(16, 2);

  // Création du caractère personnalisé en position 0
  lcd.createChar(0, smiley);

  // Affichage
  lcd.setCursor(0, 0);
  lcd.print("Hello :)");

  lcd.setCursor(0, 1);
  lcd.write(byte(0)); // Écrit le smiley
}

void loop() {
  // Rien ici
}
```

**📷 Résultat à l’écran :**
![](Jobs\Job13\Job13.png)

## 🧮 Job 14 – Nom du groupe + compteur LCD
**📋 Fonction :**

Ligne 1 : RIGAUX SAMUEL

Ligne 2 : compteur

Bouton : start / stop compteur

**code : **
```
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adresse I2C, colonnes, lignes

const int buttonPin = 2;             // Broche du bouton
bool paused = false;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
unsigned long previousMillis = 0;
unsigned long counter = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(buttonPin, INPUT_PULLUP);  // Bouton actif LOW

  lcd.setCursor(0, 0);
  lcd.print("GROUPE CYBER01");       // Remplace par ton nom de groupe
}

void loop() {
  // Lecture bouton avec anti-rebond
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastButtonState == HIGH) {
      paused = !paused; // inverse l’état (pause/reprise)
    }
  }
  lastButtonState = reading;

  // Mise à jour du compteur si pas en pause
  if (!paused && millis() - previousMillis >= 1000) {
    previousMillis = millis();
    counter++;

    lcd.setCursor(0, 1);
    lcd.print("Temps : ");
    lcd.print(counter);
    lcd.print("s      ");  // espace pour effacer les chiffres précédents
  }
}
```

**📷 LCD + bouton :**
![](Jobs\Job14\Job14.png)


## 🌈 Job 15 – LED RGB + potentiomètre

**🎨 Effet :** intensité d'une couleur augmente pendant que l'autre diminue.

**code :**

```
const int potPin = A0;

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin); // 0 à 1023

  // Divise la plage en 3 zones pour gérer R → G → B
  int zone = potValue / 341; // 1023 / 3 ≈ 341
  int value = potValue % 341;

  int red = 0, green = 0, blue = 0;

  if (zone == 0) {
    red = map(341 - value, 0, 341, 0, 255);
    green = map(value, 0, 341, 0, 255);
    blue = 0;
  } else if (zone == 1) {
    red = 0;
    green = map(341 - value, 0, 341, 0, 255);
    blue = map(value, 0, 341, 0, 255);
  } else {
    red = map(value, 0, 341, 0, 255);
    green = 0;
    blue = map(341 - value, 0, 341, 0, 255);
  }

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
```

📷 Montage :

![](Jobs\Job15\Job15.png)