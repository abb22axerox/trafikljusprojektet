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

// int input_direction;

void display_setup() {
  Wire.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();

  display.setTextColor(WHITE);

  // Loading fish
  display.setTextSize(1);
  display.setCursor(5, 40);
  display.println(F("Waiting for input..."));

  // Display station number in the upper left corner
  update_station();

  display.display();
}

void update_station() {
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F("Infart: "));
  if(Btn != -1){
    display.print(Btn);
    displayBtn = Btn;
  } else {
    display.print(displayBtn);
  }
}

void update_direction(int text_size_x, int text_size_y, int cursor_x, int cursor_y, String direction) {
  delay(1);
  display.setTextSize(text_size_x, text_size_y);
  display.setCursor(cursor_x, cursor_y);
  display.println(direction);
}

void display_loop() {
  display.clearDisplay();

  update_station();

  switch (Turn) {
    case 0:
      update_direction(5, 5, 50, 20, "<");
      break;
    case 1:
      update_direction(6, 7, 50, 30, "^");
      break;
    case 2:
      update_direction(5, 5, 50, 20, ">");
      break;
    default:
      Serial.println("Def");
      break;
  }
  display.display();
}
