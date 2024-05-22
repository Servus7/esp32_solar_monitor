# Solar Powered RC Boat Status Website

This repository contains the code for a website hosted on an ESP32-C3 Supermini that displays the status of a solar-powered RC boat. The website provides real-time data on various parameters such as battery level, solar panel voltage, boat speed, and GPS coordinates.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)
- [Contributing](#contributing)

## Introduction
This project aims to monitor and display the operational status of a solar-powered RC boat. The ESP32-C3 Supermini serves as the web server, gathering data from various sensors on the boat and presenting it through a web interface.

## Features
- Real-time monitoring of:
  - Battery level
  - Solar panel voltage
  - Boat speed
  - GPS coordinates
- Simple and responsive web interface
- Low power consumption, ideal for solar-powered projects

## Hardware Requirements
- ESP32-C3 Supermini
- Li-Po Battery (for powering the ESP32)
- Solar Panel
- Voltage sensor
- Speed sensor (e.g., an encoder)
- GPS module
- RC Boat

## Software Requirements
- PlatformIO
- Additional libraries:
  - `WiFi.h`
  - `WebServer.h`
  - `Adafruit_Sensor.h`
  - `TinyGPS++.h`

## Installation

1. **Set up PlatformIO:**
   - Install PlatformIO from [here](https://platformio.org/install/ide?install=vscode).
   - Open Visual Studio Code and install the PlatformIO IDE extension.

2. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/solar-rc-boat-status.git
   cd solar-rc-boat-status
   ```

3. **Configure PlatformIO project:**
   - Open the cloned project folder in Visual Studio Code.
   - Ensure the `platformio.ini` file contains the following configuration:
     ```ini
     [env:esp32-c3]
     platform = espressif32
     board = esp32-c3-devkitm-1
     framework = arduino
     lib_deps =
       WiFi
       WebServer
       adafruit/Adafruit Unified Sensor @ ^1.1.4
       mikalhart/TinyGPSPlus @ ^1.0.2
     ```

4. **Configure WiFi credentials:**
   - Create a `wifi_config.h` file in the `src` directory with the following content:
     ```cpp
     #define WIFI_SSID "your-SSID"
     #define WIFI_PASSWORD "your-PASSWORD"
     ```

5. **Upload the code:**
   - Connect your ESP32-C3 to the computer.
   - In Visual Studio Code, open the PlatformIO extension and navigate to **PIO Home** -> **Project Tasks** -> **Upload** under the `[env:esp32-c3]` environment.
   - Click on **Upload** to compile and upload the code to the ESP32-C3.

## Usage

1. **Power up the system:**
   - Ensure all sensors and the ESP32-C3 are correctly connected and powered by the solar panel and/or battery.

2. **Connect to the web interface:**
   - Once the ESP32-C3 is powered up and connected to the WiFi network, open a web browser.
   - Enter the IP address assigned to the ESP32-C3 (check the Serial Monitor for the IP address).

3. **Monitor the status:**
   - The website will display real-time data of the RC boat's battery level, solar panel voltage, speed, and GPS coordinates.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

---

**Note:** Ensure all connections are secure and weatherproof, especially since the project involves water. Regularly check the solar panel and battery status to prevent any damage to the components.

---

Happy Sailing! 🚤🌞
