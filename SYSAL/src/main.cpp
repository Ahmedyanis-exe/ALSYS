#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// WiFi
const char* ssid = "host";
const char* password = "pwd";

// Telegram
#define BOTtoken "BOT TOKEN"
#define CHAT_ID "CHAT ID"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int ledpin = 32;
int triggerpin = 26;
int echopin= 33;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while ((WiFi.status()!= WL_CONNECTED));
  {

    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wifi");
  client.setInsecure(); // skip certificate check for Telegram

  // Send message when ESP32 starts
  bot.sendMessage(CHAT_ID, "ESP32 is online", "");


  pinMode(ledpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(triggerpin, OUTPUT);
  

}

void loop() {
  
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);

  // Measure echo time
  long duration = pulseIn(echopin, HIGH, 30000); // 30ms timeout (~5m range)

  if (duration == 0) {
    Serial.println("Out of range");
  } else {
    float distance = (duration * 0.0343) / 2; // cm
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");


    if (distance <= 10)
    {

      digitalWrite(ledpin,HIGH);
      bot.sendMessage(CHAT_ID, "LED is ON", "");
    }
    else{
      digitalWrite(ledpin, LOW);
    }
    
  }

  delay(200);



}

