# Soil Moisture Monitoring System

## Introduction
The **Soil Moisture Monitoring System** is an IoT-based project designed to monitor soil moisture levels in real-time. It helps farmers and gardeners make informed decisions about irrigation and crop management. This system leverages **Node MCU (ESP8266)**, soil moisture sensors, and the **ThingSpeak** platform to visualize data remotely.

---

## Objectives
- Design a low-cost and efficient soil moisture monitoring system.
- Enable real-time data acquisition and visualization.
- Provide a user-friendly interface for remote access to soil moisture data.
- Utilize IoT principles for connectivity and data transmission.

---

## Components Used
- **Node MCU (ESP8266)** microcontroller
- **Soil moisture sensors**
- Connecting wires
- USB cable for programming and power
- Computer with Arduino IDE
- ThingSpeak platform for data visualization

---

## Working Principle
1. **Data Acquisition**: Soil moisture sensors are placed in the soil to measure moisture content and convert it into electrical signals.
2. **Data Transmission**: The Node MCU reads sensor data and transmits it to the **ThingSpeak** platform via Wi-Fi.
3. **Data Visualization**: ThingSpeak visualizes the data in graphs and charts, enabling real-time monitoring and decision-making.

---

## Implementation
### Hardware Setup
- Soil moisture sensors are connected to the Node MCU using wires.
- Sensors are placed strategically within the soil for accurate moisture measurement.

### Software Development
- The firmware for the Node MCU is developed using **Arduino IDE**.
- Code is designed to:
  - Establish a stable Wi-Fi connection.
  - Read data from soil moisture sensors.
  - Transmit data to ThingSpeak via HTTP requests.

### ThingSpeak Integration
- A ThingSpeak channel is configured to receive and display data in graphical form.
- The channel provides an intuitive interface for monitoring real-time soil moisture levels remotely.

### Power Supply
- The Node MCU is powered using a USB cable connected to a reliable power source.

---

## Results
- Real-time monitoring of soil moisture levels.
- Optimization of irrigation schedules to prevent overwatering or underwatering.
- A web interface for user-friendly visualization accessible from any internet-enabled device.

---

## Conclusion
The **Soil Moisture Monitoring System** is a cost-effective and efficient IoT solution for real-time monitoring of soil moisture levels. It empowers users to optimize irrigation, improve crop yield, and enhance crop management practices.

---

## How to Run
1. Set up the hardware as described in the **Hardware Setup** section.
2. Flash the firmware onto the Node MCU using Arduino IDE.
3. Configure your Wi-Fi credentials and ThingSpeak channel details in the firmware code.
4. Power the Node MCU using a USB cable.
5. Access the ThingSpeak dashboard to monitor soil moisture data.

---

✨ This project is maintained by Khushi Gupta
GitHub:  https://github.com/Khushi0389