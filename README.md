# Surveillance Robot

## Overview

This project is a surveillance robot developed under the **OBC Pilot Project (T26)** at the Egyptian Russian University, Faculty of Engineering – Telecommunication Department, in collaboration with the **Egyptian Space Agency (EgSA)**.

The robot is equipped with a wide array of sensors, communication modules, and live video capabilities, all controlled and monitored using **LabVIEW®**.

---

## 🔍 Project Brochure

![Surveillance Robot Brochure](./Surveillance%20Robot_T26_Brochure%20.png)

---

## 📁 Project Structure

```
Surveillance_Robot/
├── Surveillance_Robot_Arduino_Code/       # Code for ATmega328P microcontroller
├── Surveillance_Robot_NodeMCU_Code/       # Code for NodeMCU (Firebase, WiFi)
├── Surveillance_Robot_LabVIEW/            # LabVIEW GUI and control interface
├── Surveillance_Robot_PCB/                # Altium Designer files: schematics and PCB layouts
├── Documentation/                         # Project report and images
└── README.md
```

---

## 🧠 System Features

- **Dual communication**: Bluetooth and Firebase
- **Live video streaming** via smartphone IP camera
- **Radar subsystem** with ultrasonic sensor and servo motor
- **Lighting subsystem** with LDR and LED
- **LabVIEW GUI** for complete control and data visualization
- **Custom PCB Design** using Altium®

---

## 🔧 Hardware Components

- ATmega328P Microcontroller  
- NodeMCU (ESP8266) WiFi Module  
- HC-05 Bluetooth Module  
- Ultrasonic Sensor (HC-SR04)  
- Servo Motor (MG90S)  
- LDR & LED  
- DC Motors & Motor Driver (L293D)  
- Shift Register (74HC595)  
- USB to TTL (CH340G or FTDI)  
- Custom PCB & Connectors  
- Smartphone (for IP Camera and Hotspot)

---

## 💻 Software Components

- **Altium Designer**: For circuit and PCB design  
- **Arduino IDE**: Microcontroller programming  
- **LabVIEW®**:
  - GUI for robot control
  - Data handling via Bluetooth & Firebase
  - IP camera integration (Vision and Motion Package)

---

## 🎥 Demo Video

[Click here to watch the demo video](https://drive.google.com/file/d/11F5FtCzvLfQu6SFagj_hiVPWTxhxrmC-/view?usp=sharing)

---

## 📊 GUI Highlights

- Motor direction and speed control
- Manual/automatic servo rotation
- LED and LDR interaction
- Real-time radar display
- IP camera feed

---

## 🛠️ Challenges & Solutions

- **PCB VIA limitation**: Resolved by sourcing a compatible manufacturer
- **Firebase/Bluetooth switching**: Implemented via LabVIEW Case Structures
- **Data handling**: Used string manipulation and arrays for efficient parsing
- **IP camera cost**: Used smartphone + IP Webcam app as an alternative

---

## 🚀 Future Enhancements

- Real-time command sync and clock (RTC)
- Subsystem communication & power control
- Full OBC subsystem simulation with file storage and payload management

---

## 👨‍💻 Team Members

- Kerelos Emad Ibrahim  
- Abanoub Factor Samy  
- Bola Joseph Ratep  
- Eman Sameh Abdelrahman  
- Mayar Essam Ahmed  
- Manar Ahmed Hassan  

**Supervisors**:  
Eng. Ibrahim Emam  
Eng. Asmaa Aly

**Date**: September 2022
