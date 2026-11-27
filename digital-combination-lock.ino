
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {8, 9, 10, 11};
byte colPins[COLS] = {12, 13, A0, A1};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo lockServo;

const int servoPin = A2;
const int buzzerPin = A3;
const int redLED = A4;
const int greenLED = A5;

String password = "7777";
String enteredPassword = "";

void setup() {
  lcd.begin(16, 2);

  pinMode(buzzerPin, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  lockServo.attach(servoPin);
  lockServo.write(0);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);

  lcd.setCursor(0, 0);
  lcd.print("DIGITAL LOCK");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");

  delay(2000);
  showPrompt();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '*') {
      enteredPassword = "";
      showPrompt();
    }
    else if (key == '#') {
      checkPassword();
    }
    else if (key >= '0' && key <= '9') {
      if (enteredPassword.length() < 4) {
        enteredPassword += key;

        lcd.setCursor(0, 1);
        for (int i = 0; i < enteredPassword.length(); i++) {
          lcd.print("*");
        }
      }
    }
  }
}

void showPrompt() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ENTER PASSWORD");
  lcd.setCursor(0, 1);
}

void checkPassword() {
  lcd.clear();

  if (enteredPassword == password) {
    lcd.print("ACCESS GRANTED");

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

    tone(buzzerPin, 1000, 150);

    lockServo.write(90);
    delay(3000);
    lockServo.write(0);

    digitalWrite(greenLED, LOW);
  }
  else {
    lcd.print("WRONG PASSWORD");

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

    tone(buzzerPin, 500, 1000);
    delay(1500);

    digitalWrite(redLED, LOW);
  }

  noTone(buzzerPin);

  enteredPassword = "";
  delay(500);
  showPrompt();
}
