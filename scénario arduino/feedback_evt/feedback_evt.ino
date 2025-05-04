
//test2
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adresse I2C 0x27, écran 16x2

// Configuration des boutons (identique à votre test fonctionnel)
const byte boutonPlus = 2;    // Broche 2
const byte boutonMoins = 3;   // Broche 3
const byte boutonMixte = 4;   // Broche 4
const byte buzzerPin = 8;     // Broche 8

// Structure pour le vote
struct {
  int plus = 0;
  int moins = 0;
  int mixte = 0;
  int total = 0;
  int maxParticipants = 0;
  String eventName = "";
  bool actif = false;
} vote;

// Détection d'appui
struct {
  bool plusPressed = false;
  bool moinsPressed = false;
  bool mixtePressed = false;
  unsigned long lastDebounceTime = 0;
} boutons;

// Déclarations des fonctions (PROTOTYPES)
void bipCourt();
void envoyerScore(bool finished = false);
void demarrerVote(String cmd);
void detecterAppuisBoutons();
void traiterVote(int type);
int calculerScore();
void afficherStatut();
void terminerVote();

void setup() {
  Serial.begin(9600);
  
  // Configuration identique à votre test fonctionnel
  pinMode(boutonPlus, INPUT);    // Pull-up EXTERNE
  pinMode(boutonMoins, INPUT);   // Pull-up EXTERNE
  pinMode(boutonMixte, INPUT);   // Pull-up EXTERNE
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH);

  lcd.init();
  lcd.backlight();
  lcd.print("Lancer le vote");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    
    if (command.startsWith("START:")) {
      demarrerVote(command);
    }
    else if (command == "GETSCORE") {
      envoyerScore();
    }
  }

  if (vote.actif) {
    detecterAppuisBoutons();
  }
}

// Implémentation des fonctions

void bipCourt() {
  digitalWrite(buzzerPin, LOW);
  delay(100);
  digitalWrite(buzzerPin, HIGH);
}

void envoyerScore(bool finished) {
  int currentScore = calculerScore();
  if (finished) {
    Serial.print("FINISHED:");
  } else {
    Serial.print("SCORE:");
  }
  Serial.println(currentScore);
}

void demarrerVote(String cmd) {
  int firstColon = cmd.indexOf(':');
  int secondColon = cmd.indexOf(':', firstColon + 1);
  
  if (firstColon == -1 || secondColon == -1) {
    Serial.println("ERR:FORMAT");
    return;
  }

  vote.eventName = cmd.substring(firstColon + 1, secondColon);
  vote.maxParticipants = cmd.substring(secondColon + 1).toInt();

  // Réinitialisation
  vote.plus = 0;
  vote.moins = 0;
  vote.mixte = 0;
  vote.total = 0;
  vote.actif = true;

  afficherStatut();
  bipCourt(); // Bip de confirmation
  Serial.println("ACK:START");
}

void detecterAppuisBoutons() {
  const unsigned long debounceDelay = 50;

  // Lecture actuelle (inversée comme dans votre test)
  bool plusState = !digitalRead(boutonPlus);
  bool moinsState = !digitalRead(boutonMoins);
  bool mixteState = !digitalRead(boutonMixte);

  if ((millis() - boutons.lastDebounceTime) > debounceDelay) {
    if (plusState && !boutons.plusPressed) {
      boutons.plusPressed = true;
      traiterVote(1);
    }
    else if (!plusState) {
      boutons.plusPressed = false;
    }

    if (moinsState && !boutons.moinsPressed) {
      boutons.moinsPressed = true;
      traiterVote(-1);
    }
    else if (!moinsState) {
      boutons.moinsPressed = false;
    }

    if (mixteState && !boutons.mixtePressed) {
      boutons.mixtePressed = true;
      traiterVote(0);
    }
    else if (!mixteState) {
      boutons.mixtePressed = false;
    }

    boutons.lastDebounceTime = millis();
  }
}

void traiterVote(int type) {
  if (vote.total >= vote.maxParticipants) return;

  bipCourt();
  
  switch(type) {
    case 1: vote.plus++; break;
    case -1: vote.moins++; break;
    case 0: vote.mixte++; break;
  }
  vote.total++;

  // Debug
  Serial.print("Vote:");
  Serial.print(type);
  Serial.print(" Total:");
  Serial.println(vote.total);

  afficherStatut();
  envoyerScore();

  if (vote.total >= vote.maxParticipants) {
    terminerVote();
  }
}

int calculerScore() {
  if (vote.total == 0) return 0;
  return (vote.plus * 100 + vote.mixte * 50) / vote.total;
}

void afficherStatut() {
  lcd.clear();
  lcd.print(vote.eventName);
  lcd.setCursor(0, 1);
  lcd.print(calculerScore());
  lcd.print("% ");
  lcd.print(vote.total);
  lcd.print("/");
  lcd.print(vote.maxParticipants);
}

void terminerVote() {
  vote.actif = false;
  envoyerScore(true);
  
  // Bip de fin
  for (int i = 0; i < 3; i++) {
    bipCourt();
    delay(150);
  }
  //affichage d'un message 
  lcd.clear();
  delay(2000);
  lcd.print("fin de vote");
  lcd.setCursor(0, 1);
  lcd.print(vote.eventName);
  lcd.print(":");
  lcd.print(calculerScore());
  lcd.print("%");
  delay(5000);
  lcd.clear();
  lcd.print("Lancer le vote");




}
/*
const int boutonPin = 4;     // Pin du bouton avec pull-up externe
const int buzzerPin = 8;     // Pin du buzzer
boolean etatBouton = false;  // Variable pour stocker l'état du bouton

void setup() {
  pinMode(boutonPin, INPUT);    // Le pin du bouton est en entrée (pull-up externe)
  pinMode(buzzerPin, OUTPUT);   // Le pin du buzzer est en sortie
  Serial.begin(9600);           // Initialisation de la communication série
  Serial.println("Test bouton avec pull-up externe et buzzer");

}

void loop() {
    digitalWrite(buzzerPin, HIGH);

  
  // Lecture de l'état du bouton (inversé car pull-up)
  etatBouton = !digitalRead(boutonPin);
  
  if (etatBouton) {
    // Si le bouton est relâché
    Serial.println("Bouton relache - Buzzer OFF");
  digitalWrite(buzzerPin, HIGH);
   

  } else {
    // Si le bouton est pressé
     Serial.println("Bouton presse - Buzzer ON");
     digitalWrite(buzzerPin, LOW);
     delay(100);
     digitalWrite(buzzerPin, HIGH);
    
  }
   digitalWrite(buzzerPin, HIGH);

  
  //delay(100);  // Petit délai pour éviter les rebonds et stabiliser la
}*/