#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

int temperature = 0;
String weather = "weather";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Wire.begin(17,16);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.cp437(true);
  display.clearDisplay();
  display.display();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1.3);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.println("");
  display.print(temperature);
  display.write(0xF8);
  display.print("F");
  display.println(" ");
  display.print("Conditions: ");
  display.println("");
  display.print(weather);
  display.display();
}
