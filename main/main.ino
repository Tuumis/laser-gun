#include <LiquidCrystal.h>

int sensorPin = 10;
int irPin = 6;
int triggerPin = 7;
int magPin = 8;
int fireModPin = 9;
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

int triggerState = 0;
int magState = 0;

int hp = 3;
int mags = 7;
int magAmmo = 30;


void setup() {
  //Selecting fire mode etc.
  
  
  lcd.begin(16, 2); // set up number of columns and rows
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Arduino");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("GetStarted.com"); // print message at (2, 1)

  pinMode(irPin, OUTPUT);
  pinMode(triggerPin, INPUT);
  pinMode(magPin, INPUT);
}


void loop() {
  triggerState = digitalRead(triggerPin);
  magState = digitalRead(magPin);
  if (triggerState == HIGH && magAmmo > 0) {
    shoot();
  } else if (magState == HIGH && mags > 0) {
    reload();
  }
}

void shoot() {
  digitalWrite(irPin, HIGH);
  magAmmo--;
  delay(500);
  digitalWrite(irPin, LOW);
}

void reload() {
  magAmmo = 30;
  mags--;
}

void damage() {
  hp--;
  delay(3000);
  if (hp < 1) {
    death();
  }
}

void death() {
  while(true);
}
