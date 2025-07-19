#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
n
// Initialize the OLED display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Replace with your network credentials
const char *ssid     = "wifi name";
const char *password = "wifi password;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "time.google.com", 19800); // Using Google NTP server with IST offset

// Week Days
String weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Month names
String months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.ssd1306_command(0xA0); // Flip screen on Y-axis
  display.clearDisplay();
  display.display();
  
  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected! IP address: " + WiFi.localIP().toString());

  // Initialize a NTPClient to get time
  timeClient.begin();

  // Force update multiple times to ensure correct time
  for (int i = 0; i < 5; i++) {
    timeClient.update();
    delay(1000);
  }
}

void loop() {
  timeClient.update();

  time_t epochTime = timeClient.getEpochTime();
  String formattedTime = timeClient.getFormattedTime();
  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  int currentSecond = timeClient.getSeconds();
  String weekDay = weekDays[timeClient.getDay()];

  struct tm *ptm = gmtime((time_t *)&epochTime); 
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon + 1;
  String currentMonthName = months[currentMonth - 1];
  int currentYear = ptm->tm_year + 1900;
  String currentDate = String(monthDay) + "-" + currentMonthName + "-" + String(currentYear);

  // Display on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(10, 10);
  display.print("Time: ");
  display.println(formattedTime);
  
  display.setCursor(10, 20);
  display.print("Date:");
  display.println(currentDate);
  
  display.setCursor(10, 30);
  display.print("Day: ");
  display.println(weekDay);
  
  display.display();
  delay(1000);
}
