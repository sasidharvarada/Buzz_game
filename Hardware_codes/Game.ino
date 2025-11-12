#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// === Pin Definitions ===
#define BUZZER_PIN 14
#define LED_PIN    25
#define START_PIN  16
#define MID_PIN    17
#define END_PIN    19

// === Game Variables ===
bool gameRunning = false;
bool finished = false;
unsigned long startTime = 0;
unsigned long elapsed = 0;
unsigned long lastMidLow = 0;
int collisions = 0;

// === Timing Constants ===
const unsigned long DEBOUNCE_MS = 30;
const unsigned long BEEP_MS = 80;
const unsigned long BLINK_MS = 80;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(START_PIN, INPUT_PULLUP);
  pinMode(MID_PIN, INPUT_PULLUP);
  pinMode(END_PIN, INPUT_PULLUP);

  Wire.begin(21, 22); // SDA, SCL
  display.begin(i2c_Address, true);
  display.display();
  delay(1000);

  splashScreen();
}

void splashScreen() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(20, 20);
  display.print("Buzz");
  display.setCursor(20, 45);
  display.print("Game");
  display.display();
  delay(1500);
}

void loop() {
  unsigned long now = millis();

  // Start Game
  if (!gameRunning && !finished && digitalRead(START_PIN) == LOW) {
    delay(DEBOUNCE_MS);
    if (digitalRead(START_PIN) == LOW) {
      gameRunning = true;
      collisions = 0;
      startTime = millis();
      elapsed = 0;
    }
  }

  if (gameRunning) {
    elapsed = millis() - startTime;

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Running...");
    display.setCursor(0, 15);
    display.print("Time: ");
    display.print(elapsed / 1000.0, 2);
    display.setCursor(0, 30);
    display.print("Hits: ");
    display.print(collisions);
    display.display();

    if (digitalRead(MID_PIN) == LOW && (millis() - lastMidLow > DEBOUNCE_MS)) {
      collisions++;
      lastMidLow = millis();
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      delay(BEEP_MS);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
    }

    if (digitalRead(END_PIN) == LOW) {
      delay(DEBOUNCE_MS);
      if (digitalRead(END_PIN) == LOW) {
        finished = true;
        gameRunning = false;
        elapsed = millis() - startTime;
        showResult();
      }
    }
  }

  // Reset when holding START after finishing
  if (finished && digitalRead(START_PIN) == LOW) {
    static unsigned long holdStart = 0;
    if (holdStart == 0) holdStart = now;
    if (now - holdStart > 2000) {
      finished = false;
      splashScreen();
    }
  } else {
    static unsigned long holdStart = 0;
    holdStart = 0;
  }
}

void showResult() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("=== Result ===");
  display.setCursor(0, 15);
  display.print("Time: ");
  display.print(elapsed / 1000.0, 2);
  display.setCursor(0, 30);
  display.print("Hits: ");
  display.print(collisions);
  display.setCursor(0, 50);
  display.print("Hold Start to Reset");
  display.display();

  for (int i = 0; i < 3; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}
