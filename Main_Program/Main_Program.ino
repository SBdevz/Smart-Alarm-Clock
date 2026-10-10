#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

const char ssid = "wifi";
const char password = "password";

const char weatherURL = "URL";
const char timeURL = "URL";

int temperature = 0;
String weather = "weather";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Wire.begin(17,16);
  WiFi.begin(ssid, password);
  while (Wifi.status() != WL_CONNECTED) {
    Serial.println("Wifi is connecting...");
    delay(1000);
  }
  Serial.println(WiFi Connected);
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
  if (WiFi.staus() == WL_CONNECTED) {
    http.begin("URL")
    int httpCODE = http.GET();
    if (httpCODE > 0) {
      String payload = http.getString();
      Serial.println(httpCode);
      Serial.println(payload);
    } else {
      Serial.print("HTTP Request Error");
    }
  }
  display.print("Temperature: ");
  display.println("");
  display.print(temperature);
  display.write(0xF8);
  display.print("F");
  display.println(" ");
  display.print("Conditions: ");
  display.println(" ");
  display.print(weather);
  display.display();
}
