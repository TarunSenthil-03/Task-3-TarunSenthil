# Cloud-Connected Security Node (IoT Telemetry)

## 📌 Project Overview

The **Cloud-Connected Security Node (IoT Telemetry)** is an IoT-based security monitoring system developed using an **ESP32** and an **HC-SR04 ultrasonic sensor**. The project continuously measures the distance of nearby objects and uploads the sensor data to **Adafruit IO** for real-time cloud visualization and telemetry.

The system was designed and tested using the **Wokwi Simulator**, enabling virtual hardware simulation before deployment. During operation, the ESP32 monitors the measured distance, displays live readings on the **Serial Monitor**, uploads the data to **Adafruit IO**, and activates an **LED** and **buzzer** whenever an object is detected within the predefined threshold.

---

## 🎯 Project Objectives

- Design and implement an IoT-based security monitoring system using ESP32.
- Measure object distance using an HC-SR04 ultrasonic sensor.
- Detect nearby objects based on a predefined distance threshold.
- Upload real-time sensor data to Adafruit IO using MQTT.
- Provide local alerts using an LED and buzzer.
- Display live sensor readings through the Serial Monitor.
- Demonstrate cloud telemetry using a simulated IoT environment.

---

## ✨ Features

- Real-time object distance measurement.
- Wireless communication using ESP32 Wi-Fi.
- Cloud-based telemetry with Adafruit IO.
- Real-time data visualization on a cloud dashboard.
- Intrusion detection using configurable distance thresholds.
- LED indication during intrusion events.
- Audible buzzer alarm for immediate alerts.
- Serial Monitor output for monitoring and debugging.
- Fully simulated using the Wokwi IoT Simulator.

---

## 🔧 Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 Development Board | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Piezo Buzzer | 1 |
| Jumper Wires | As Required |

---


## 💻 Software Requirements

- Arduino IDE
- Wokwi IoT Simulator
- Adafruit IO Platform
- ESP32 Board Package
- WiFi Library
- Adafruit MQTT Library
- Embedded C/C++

---

## 🔌 Pin Connections


| Component | ESP32 Pin |
|-----------|-----------|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 Trigger | GPIO 5 |
| HC-SR04 Echo | GPIO 18 |
| LED Anode (+) | GPIO 2 (through 220 Ω resistor) |
| LED Cathode (-) | GND |
| Buzzer (+) | GPIO 13 |
| Buzzer (-) | GND |

---

## ⚙️ Working Principle

1. The ESP32 sends a trigger pulse to the HC-SR04 ultrasonic sensor.
2. The ultrasonic sensor measures the distance of nearby objects.
3. The measured distance is displayed on the Serial Monitor.
4. The distance value is uploaded to Adafruit IO.
5. When the measured distance falls below **20 cm**:
   - LED turns ON.
   - Buzzer sounds.
   - ">>> INTRUDER DETECTED <<<" is displayed on the Serial Monitor.
6. When the object moves away, the LED and buzzer turn OFF, and normal monitoring resumes.

---

## 📊 Experimental Results

The project was successfully implemented and tested using the **Wokwi Simulator**. Distance readings were monitored through the **Serial Monitor** and simultaneously uploaded to **Adafruit IO** for real-time visualization.

### Summary Table

| Distance (cm) | Intruder Detected | LED | Buzzer | Cloud Upload |
|--------------:|:-----------------:|:---:|:------:|:------------:|
| 210.54 | No | OFF | OFF | Yes |
| 165.88 | No | OFF | OFF | Yes |
| 98.22 | No | OFF | OFF | Yes |
| 45.71 | No | OFF | OFF | Yes |
| 19.56 | Yes | ON | ON | Yes |
| 11.92 | Yes | ON | ON | Yes |
| 30.46 | No | OFF | OFF | Yes |
| 95.13 | No | OFF | OFF | Yes |

---

## 🖥️ Sample Serial Monitor Output

```text
ESP32 Security Node Started

Distance: 210.54 cm
Uploaded to Adafruit IO

Distance: 165.88 cm
Uploaded to Adafruit IO

Distance: 98.22 cm
Uploaded to Adafruit IO

Distance: 45.71 cm
Uploaded to Adafruit IO

Distance: 19.56 cm
Uploaded to Adafruit IO
>>> INTRUDER DETECTED <<<

Distance: 11.92 cm
Uploaded to Adafruit IO
>>> INTRUDER DETECTED <<<

Distance: 30.46 cm
Uploaded to Adafruit IO

Distance: 95.13 cm
Uploaded to Adafruit IO
```

---

## 📈 Results and Observations

- Successfully simulated the complete system using Wokwi.
- Distance values were accurately measured using the HC-SR04 ultrasonic sensor.
- Sensor readings were displayed on the Serial Monitor in real time.
- All measured values were uploaded successfully to Adafruit IO.
- LED and buzzer remained OFF during normal conditions.
- LED and buzzer were activated when the distance dropped below 20 cm.
- The Adafruit IO dashboard displayed live telemetry data and historical distance measurements.

---

## 👨‍💻 Author

**Tarun Senthil**

B.E. Electronics and Communication Engineering

---

## 📄 License

This project is intended for educational and learning purposes.
