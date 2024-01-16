// Axel

//# INPUT #​
// Btn: int, in range 1-4
// Walk: boolean
// Turn: int,  in range 0-2

//# OUTPUT #​
// ingen, visar pil och stationsnummer på skärmen

#include "variables.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define InputPin 30
// bool ButtonState;

void setup() {
  Serial.begin(9600);
  pinMode(InputPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.pins(14, 12);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();

  display.setTextColor(WHITE);
  display.setTextSize(2, 3);
}

void loop() {
  ButtonState = digitalRead(InputPin);
  digitalWrite(LED_BUILTIN, ButtonState);

  if (ButtonState) {
    display.clearDisplay();
    display.setCursor(10, 20);
    display.println(F("Grattis!"));

    for (int16_t i = 0; i < display.height() / 2 - 2; i += 40) {
      display.drawRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i,
                            display.height() / 4, SSD1306_WHITE);
      display.display();
      delay(1);
    }
  } 
  else {
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println(F("Tryck nu!"));

    for (int16_t i = 0; i < display.height() / 2 - 2; i += 40) {
      display.drawRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i,
                            display.height() / 4, SSD1306_WHITE);
      display.display();
      delay(1);
    }
    delay(200);
  }
}
