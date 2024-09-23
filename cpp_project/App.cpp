#include"App.hpp"




void showMainMenu() 
{    
    cout << "Welcome to the WiFi Control Program" << endl ;
    cout << "1. WiFi Control" << endl ;
    cout << "2. Bluetooth Control" << endl ;
    cout << "3. Exit" << endl ;
    cout << "Enter your choice: " << endl ;
}


void AppHandle()
{
    auto choice{0};

    while (true)
    {
        showMainMenu();
        cin >> choice ;
        switch (choice)
        {
            case 1:
              WiFiControl();
              //cout<<"wifi"<<endl ;
              break;
        
            case 2:
              BluetoothControl();
              //cout<<"bluetooth"<<endl ;
              break;
              
            case 3:
              cout<<"exit"<<endl ;
              return;   
        
            default:
                cout << "Invalid choice. Please try again" << endl;
        }
    }
}


