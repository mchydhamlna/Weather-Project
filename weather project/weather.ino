#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "changeme";
const char* password = "changeme";
const char* apiKey = "changeme";
const char* city = "changeme";
const char* countryCode = "changeme";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor((SCREEN_WIDTH - 7 * 6) / 2, 16);
  display.println("Weather");
  display.setCursor((SCREEN_WIDTH - 7 * 6) / 2, 26);
  display.println("Project");
  display.setCursor((SCREEN_WIDTH - 3 * 6) / 2, 36);
  display.println("1.0");
  display.display();
  delay(2000);
  display.clearDisplay();

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://api.openweathermap.org/data/2.5/weather?q=" + String(city) + "," + String(countryCode) + "&appid=" + String(apiKey) + "&units=metric";
    http.begin(client, url);

    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      DynamicJsonDocument doc(2048);
      deserializeJson(doc, payload);

      float temperature = doc["main"]["temp"];
      int humidity = doc["main"]["humidity"];
      float windSpeed = doc["wind"]["speed"];

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);

      String cityStr = "changeme";
      int16_t x1, y1;
      uint16_t w, h;
      display.getTextBounds(cityStr, 0, 0, &x1, &y1, &w, &h);
      display.setCursor((SCREEN_WIDTH - w) / 2, 20);
      display.println(cityStr);

      String tempStr = "T: " + String(temperature) + "C";
      display.getTextBounds(tempStr, 0, 0, &x1, &y1, &w, &h);
      display.setCursor((SCREEN_WIDTH - w) / 2, 30);
      display.println(tempStr);

      String humStr = "H: " + String(humidity) + "%";
      display.getTextBounds(humStr, 0, 0, &x1, &y1, &w, &h);
      display.setCursor((SCREEN_WIDTH - w) / 2, 40);
      display.println(humStr);

      String windStr = "W: " + String(windSpeed) + "m/s";
      display.getTextBounds(windStr, 0, 0, &x1, &y1, &w, &h);
      display.setCursor((SCREEN_WIDTH - w) / 2, 50);
      display.println(windStr);

      display.display();
    } else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
  delay(60000); // Update every 60 seconds
}