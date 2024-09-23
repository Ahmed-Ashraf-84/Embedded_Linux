#ifndef BLUETOOTH_CONTROL_HPP
#define BLUETOOTH_CONTROL_HPP

#include <iostream>
#include <cstdlib> // For system()

using namespace std ;

void BluetoothControl();
void ShowBluetoothMenu();
void displayBluetoothStatus();
void turnBluetoothOn();
void turnBlutoothOff();
void ScanBluetoothDevices();
void ConnectionQuality();
void DisplayActiveConnection();
void connectToBluetoothDevice();

#endif 