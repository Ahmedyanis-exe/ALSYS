# ALSYS
My first ESP32 project: an ultrasonic alarm system with Telegram bot integration for real-time intrusion alerts.
A simple IoT alarm system built with an ESP32 and an HC-SR04 ultrasonic distance sensor. The system continuously measures the distance to nearby objects. When an object is detected within 10 cm, the ESP32 sends an alert message to a Telegram bot, allowing remote notifications in real time.

This project was my first experience working with the ESP32 and IoT communication.

Features
  Measures distance using the HC-SR04 ultrasonic sensor.
  Detects objects within a configurable threshold (10 cm by default).
  Sends instant notifications through a Telegram bot.
  Includes an LED indicator for local status.
  Built using the ESP32 Wi-Fi capabilities.
 
Hardware
  ESP32 DevKit
  HC-SR04 Ultrasonic Sensor
  LED
  220 Ω resistor (LED)
  2 kΩ and 3 kΩ resistors (Voltage divider for the HC-SR04 ECHO pin since the ESP32 GPIOs are 3.3 V tolerant.)
  Jumper wires
  Breadboard
  
How It Works
  The ESP32 triggers the HC-SR04 sensor.
  The sensor measures the distance to the nearest object.
  If the measured distance is 10 cm or less, the ESP32:
  Turns on the LED.
  Sends an alert message to a Telegram bot over Wi-Fi.
  When the object moves away, the LED turns off and the system continues monitoring.

Technologies Used
  ESP32
  Arduino IDE
  Wi-Fi
  Telegram Bot API
  HC-SR04 Ultrasonic Sensor

Learning Outcomes
This was my first ESP32 project, and it helped me learn:
  ESP32 GPIO programming
  Reading ultrasonic sensor data
  Voltage level shifting for 3.3 V microcontrollers
  Wi-Fi communication
  Using the Telegram Bot API for IoT notifications
  Designing electronic schematics in KiCad
