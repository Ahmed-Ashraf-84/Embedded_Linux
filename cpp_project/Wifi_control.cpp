#include"Wifi_control.hpp"








int main()
{
    
    


    
    return 0;
}





void showWiFiMenu()
{
    cout << "------ WiFi Control Menu ------"  << endl ;
    cout << "1. Display WiFi Status " << endl ;
    cout << "2. Turn WiFi On " << endl ;
    cout << "3. Turn WiFi Off " << endl ;
    cout << "4. Connect to a WiFi Network " << endl ;
    cout << "5. Remove a Saved Network " << endl ;
    cout << "6. Modify a Saved Network " << endl ;
    cout << "7. Search for a Network " << endl ;
    cout << "8. Exit to Main Menu " << endl ;
    cout << "Enter your choice: " << endl ;
}


void displayWiFiStatus()
{
    cout << "Checking WiFi status" << endl;     //nmcli is a shell command which display the status of wifi {radio wave [wifi-bluetooth]}
    int result = system("nmcli radio wifi");  // result has the return status of nmcli --> zero it means it excuted successfully otherwise means that it fails
                                                //system is a C function takes a string with yhe shell command to excute
    if (result != 0) {
        cerr << "Error: Unable to check WiFi status" << endl ; 
    }
}

void turnWiFiOn() 
{
    cout << "Turning WiFi on" << endl;
    int result = system("nmcli radio wifi on");  // Use nmcli to turn WiFi on
    if (result != 0) {
        cerr << "Error: Unable to Turn WiFi ON" << endl ; 
    }
}

void turnWiFiOff() 
{
    cout << "Turning WiFi off" << endl;
    int result = system("nmcli radio wifi off");  // Use nmcli to turn WiFi off
    if (result != 0) {
        cerr << "Error: Unable to Turn WiFi OFF" << endl ; 
    }
}

void connectToSavedNetwork()
{
    if (savedNetworks.empty()) 
    {
        cout << "No saved networks available" << endl ;
    }
    else
    {
        cout << "Saved Networks:" << endl ;
        for (const auto& ssid : savedNetworks) 
        {
            cout << "--> " << ssid.first << endl; // print the saved names of wifi
        }

        string ssid;
        cout << "Enter the SSID to connect: ";
        cin >> ssid;

        map<string,string>::iterator map_iterator = savedNetworks.find(ssid);

        if (map_iterator != savedNetworks.end()) { // if the map_iterator reach to the end of map this means that it do not find the required ssid
            string command = "nmcli dev wifi connect \"" + ssid + "\" password \"" + it->second + "\""; //nmcli dev wifi connect "wifi ssid" password "password"
            if (system(command.c_str()) == 0) { //c_str() converts the std::string into const char* [c style] this also means that you can not change the string data 
                cout << "Connected to " << ssid << endl; // if the connection is successful
            } 
            else 
            {
                cout << "Failed to connect to " << ssid << endl;
            }
        } 
        else 
        {
            cout << "Network not found.\n";
        }
    }
    
}

void connectToNewNetwork() {
    string ssid, password;
    cout << "Enter SSID: ";
    cin >> ssid;
    cout << "Enter Password: ";
    cin >> password;

    string command = "nmcli dev wifi connect \"" + ssid + "\" password \"" + password + "\"";
    if (system(command.c_str()) == 0) {
        cout << "Connected to " << ssid << endl ;
        savedNetworks[ssid] = password;  // Save the network
    } 
    else 
    {
        cout << "Failed to connect to " << ssid << endl ;
    }
}

void removeNetwork() {
    string ssid;
    cout << "Enter SSID to remove: " << endl ;
    cin >> ssid;

    if (savedNetworks.erase(ssid)) 
    {
        cout << "Network removed.\n";
    } 
    else 
    {
        cout << "Network not found.\n";
    }
}

void modifyNetwork() {
    string ssid ;
    cout << "Enter SSID to modify: " << endl ;
    cin >> ssid;

    auto it = savedNetworks.find(ssid);
    if (it != savedNetworks.end()) 
    {
        if (savedNetworks.erase(ssid)) 
        {
            string newssid , newPassword ;
            cout << "Enter new SSID: ";
            cin >> newssid;        
            cout << "Enter new password: ";
            cin >> newPassword;

            savedNetworks[newssid] = newPassword;
            cout << "Network updated"<<endl;
        } 
        else 
        {
            cerr << "Error: Network not updated"<<endl;
        }



    } 
    else 
    {
        cout << "Network not found"<<endl;
    }
}

void searchNetwork() {
    string ssid;
    cout << "Enter SSID to search: ";
    cin >> ssid;

    map<string,string>::iterator it = savedNetworks.find(ssid);

    if (it != savedNetworks.end()) 
    {
        std::cout << "Network found: " << ssid << endl;
    } 
    else 
    {
        std::cout << "Network not found" << endl;
    }
}

void WiFiControl() 
{
    auto wifiChoice;
    while (true) {
        showWiFiMenu();
        cin >> wifiChoice;
        switch (wifiChoice) {
            case 1:
                displayWiFiStatus();
                break;
            case 2:
                turnWiFiOn();
                break;
            case 3:
                turnWiFiOff();
                break;
            case 4:
                int connectChoice;
                cout << "1. Connect using a saved network "<<endl;
                cout << "2. Connect using a new network "<<endl ;
                cout << "Enter your choice: "<<endl ;
                
                cin >> connectChoice;
                if (connectChoice == 1) 
                {
                    connectToSavedNetwork();
                }
                else if (connectChoice == 2) 
                {
                    connectToNewNetwork();
                } 
                else 
                {
                    cout << "Invalid choice " << endl;
                }
                break;
            case 5:
                removeNetwork();
                break;
            case 6:
                modifyNetwork();
                break;
            case 7:
                searchNetwork();
                break;
            case 8:
                break;  // Exit to Main Menu
            default:
                cout << "Invalid choice, Please try again" << endl;
        }
    }
}


