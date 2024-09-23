#include "BluetoothControl.hpp"




void BluetoothControl() 
{
    auto BlueChoice;
    while (true) {
        ShowBluetoothMenu();
        cin >> BlueChoice;
        switch (BlueChoice) 
        {
            case 1:
                displayBluetoothStatus();
                break;
            case 2:
                turnBluetoothOn();
                break;
            case 3:
                turnBlutoothOff();
                break;
            case 4:
                connectToBluetoothDevice();
                break;
            case 5: 
                ScanBluetoothDevices();
                break;
            case 6: 
                DisplayActiveConnection();
                break;
            case 7: 
                ConnectionQuality();
                break;
            case 8: // Exit to Main Menu 
                return;                
            default:
                cout << "Invalid choice, Please try again" << endl;
        }
    }
}


void ShowBluetoothMenu() 
{
    cout << "  Bluetooth Control Menu:  " << endl ;
    cout << "1 - Display Bluetooth Status  " << endl ;
    cout << "2 - Turn Bluetooth On  " << endl ;
    cout << "3 - Turn Bluetooth Off  " << endl ;
    cout << "4 - Connect to Bluetooth Device  " << endl ;
    cout << "5 - Scan Bluetooth Devices  " << endl ;
    cout << "6 - Display Active Bluetooth Devices  " << endl ; 
    cout << "7 - Display Connection Quality  " << endl ;   
    cout << "8 - Back to Main Menu  " << endl ;
    cout << "Choose an option: " << endl ;
}

void displayBluetoothStatus() {
    int status = system("bluetoothctl show | grep -q 'Powered: yes' && echo 'Bluetooth is ON' || echo 'Bluetooth is OFF'");
    if (status != 0) {  // you can use man -k "keyword" to search for command related to what you want -- bluetoothctl show this command shows many factors of 
                        // blutooth status so we pass it to "|" operator the grep what we search for "power" -- then if this command success the command 
                        // after && will excute and the command after || will be ignored and vise versa 
        cerr << "Failed to check Bluetooth status"<<endl;//if the return status of system not equal 0 this means that it fails 
    }
}

void turnBluetoothOn() {
    int status = system("bluetooth on");
    if (status != 0) {  
        cerr << "Failed to turn Bluetooth ON"<<endl;//if the return status of system not equal 0 this means that it fails 
    }
}


void turnBluetoothOff() {
    int status = system("bluetooth off");
    if (status != 0) {  
        cerr << "Failed to turn Bluetooth OFF"<<endl;//if the return status of system not equal 0 this means that it fails 
    }
}


void ScanBluetoothDevices()
{
    cout << "Scanning for Bluetooth devices"<<endl;
    int scanStatus = system("bluetoothctl scan on & sleep 5; bluetoothctl scan off");//you can also use hcitool scan , as we know the & run the command in the background
    if (scanStatus != 0) {
        cerr << "Failed to scan for Bluetooth devices"<<endl;
        return;
    }

    cout << "Available devices :"<<endl;
    system("bluetoothctl devices");
}



void connectToBluetoothDevice() {
    ScanBluetoothDevices();

    string macAddress;
    cout << "Enter the MAC address of the device to connect: ";
    cin >> macAddress;

    string Command = "bluetoothctl connect " + macAddress;
    int connectStatus = system(Command.c_str());
    if (connectStatus == 0) {
        cout << "Connected to device " << macAddress << endl;
    } 
    else 
    {
        cerr << "Failed to connect to device " << macAddress << endl ;
    }
}



void DisplayActiveConnection()
{
    cout << "Display Connected Bluetooth devices"<<endl;
    int Status = system("hcitool con");
    if (Status != 0) {
        cerr << "Failed to Display Connected Devices"<<endl ;
    }

}


void ConnectionQuality()
{
    ScanBluetoothDevices();
    string macAddress;
    cout << "Enter the MAC address of the device : ";
    cin >> macAddress;

    string Command = "hcitool lq " + macAddress;

    int Status = system(Command.c_str());
    if (Status != 0) {
        cerr << "Failed to Display Connection Quality"<<endl ;
    }

}



