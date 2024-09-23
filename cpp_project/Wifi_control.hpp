#ifndef __WIFI_CONTROL__H__
#define __WIFI_CONTROL__H__

#include<iostream>
#include<cstdlib> // For system()
#include<map>
#include<string>

using namespace std ;

map<string,string> savedNetworks ; //we use map container because we need key which represent name of wifi and value which represent password of wifi

void WiFiControl();
void showWiFiMenu();
void displayWiFiStatus();
void turnWiFiOn();
void turnWiFiOff();
void connectToSavedNetwork();
void connectToNewNetwork();
void removeNetwork();
void modifyNetwork();
void searchNetwork();
void handleWiFiControl();

#endif  //!__WIFI_CONTROL__H__

