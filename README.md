# Weather-Project
This Weather Project is an IoT-based application using an ESP8266 microcontroller and an OLED display to fetch and display weather information from the OpenWeatherMap API. It provides real-time weather updates including temperature, humidity, and wind speed for the specified city
![weatherproject1](https://github.com/user-attachments/assets/46bbdbc8-4d1f-4d46-85d6-fa6bec779d89)
# Features
- Real-Time Weather Data: Fetches current weather data from the OpenWeatherMap API.
- OLED Display: Utilizes a 128x64 pixel OLED display to present weather information.
- WiFi Connectivity: Connects to the internet via WiFi to retrieve weather data.
- User-Friendly Display: Displays temperature, humidity, and wind speed in a clear and readable format.
# Hardware Requirements
- ESP8266 (e.g., Wemos D1 Mini)
- 128x64 OLED display (e.g., Oled Shield 0.66)
- Connecting wires and breadboard
# Software Requirements
- Arduino IDE
- ESP8266 Board Package
- Adafruit GFX Library
- Adafruit SSD1306 Library
- ArduinoJson Library
# Installation
## 1. Clone the repository
```sh
https://github.com/mchydhamlna/Weather-Project.git
```
## 2. Install necessary libraries:
Ensure you have the following libraries installed via the Arduino Library Manager:
- ESP8266WiFi
- ESP8266HTTPClient
- ArduinoJson
- Adafruit GFX
- Adafruit SSD1306
## 3. Configure WiFi and API credentials:
Update the ssid, password, apiKey, city, and countryCode variables in the weather_project.ino file with your WiFi credentials and OpenWeatherMap API key.
## 4. Upload the code:
Connect your ESP8266 to your computer and upload the code using the Arduino IDE.
# Usage
Once the ESP8266 is powered on and connected to the WiFi, it will fetch the weather data from the OpenWeatherMap API and display it on the OLED screen. The display will show:
- City name
- Temperature in Celsius
- Humidity percentage
- Wind speed in meters per second
The weather data will update every 60 seconds.
# Contributions
Contributions, issues, and feature requests are welcome! Feel free to check the [issues](https://github.com/mchydhamlna/Weather-Project/issues) page if you want to contribute.
# License
This project is licensed under the MIT License. See the [LICENSE](https://github.com/mchydhamlna/Weather-Project/blob/main/LICENSE) file for details.
