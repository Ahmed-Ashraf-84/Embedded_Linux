# Bluetooth & WiFi Control Program

![Static Badge](https://img.shields.io/badge/Embedded%20Linux-30%25-blue?style=plastic&logo=github&logoColor=white&label=Embedded%20Linux&labelColor=Black&color=blue) ![Static Badge](https://img.shields.io/badge/C%2B%2B-%2B20-orange?style=plastic&logo=c%2B%2B&logoColor=white&label=C%2B%2B&labelColor=grey&color=red)



## Overview

This program allows users to interact with Bluetooth and WiFi networks on Linux systems. It features a menu-driven interface that provides multiple options for managing Bluetooth and WiFi connections.

## Table of Contents

- [Requirements](#requirements)
  - [WiFi Requirements](#wifi-requirements)
  - [Bluetooth Requirements](#bluetooth-requirements)
- [Files](#files)
- [Installation](#installation)
- [Usage](#usage)
## Requirements

### Main Menu

The program welcomes the user and displays three options:
1. WiFi Control
2. Bluetooth Control
3. Exit

### WiFi Requirements

1. **Display WiFi Status**
   - Checks and displays the current status of WiFi (on/off).

2. **Turn WiFi On/Off**
   - Options to turn WiFi on or off using system commands.

3. **Connect to WiFi Network**
   - Divided into two sub-sections:
     - **Connect using a saved network:** Prompts the user to select from a list of previously saved networks.
     - **Connect using a new network:** Allows the user to enter a new SSID and password, and saves the new network for future use.

4. **Save WiFi Networks**
   - Mechanism to store and retrieve saved networks using an STL map, with persistence for SSID and password.

5. **Optional Features**
   - Remove a Saved Network: Allow users to delete a saved network.
   - Modify a Saved Network: Allow users to update the SSID or password.
   - Search for a Network: Provide the ability to search for a network by SSID.

### Bluetooth Requirements

1. **Display Bluetooth Status**
   - Checks and displays the current status of Bluetooth (on/off).

2. **Turn Bluetooth On/Off**
   - Options to turn Bluetooth on or off using system commands.

3. **Connect to Bluetooth Network**
   - Displays available Bluetooth devices and prompts the user to select a device to connect to.

## Files

- **main.cpp**: The entry point of the program that initializes the application.
- **App.cpp / App.hpp**: Contains the main application logic and menu display functions.
- **Wifi_control.cpp / Wifi_control.hpp**: Manages WiFi functionalities including connecting to networks, turning WiFi on/off, and managing saved networks.
- **BluetoothControl.cpp / BluetoothControl.hpp**: Manages Bluetooth functionalities such as connecting to devices and displaying connection status.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Ahmed-Ashraf-84/Embedded_Linux.git
   ```
2. Navigate to the project directory:
   ```bash
   cd cpp_project
   ```
3. Compile the program:
   ```bash
   g++ main.cpp App.cpp Wifi_control.cpp BluetoothControl.cpp -o wifi_bluetooth_control -std=c++11
   ```

## Usage

Run the program:
```bash
./wifi_bluetooth_control
```
Follow the on-screen instructions to manage WiFi and Bluetooth connections.

