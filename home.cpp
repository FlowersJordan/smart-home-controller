#include <iostream>
#include <string>
using namespace std;


class Room {
public:
    string roomName;
    bool lightOn;
    int temperature;
    int humidity;
    bool fanOn;
    int fanSpeed;

    Room(string Name, bool light, int temp, int hum, bool fan, int speed) {
        roomName = Name;
        lightOn = light;
        temperature = temp;
        humidity = hum;
        fanOn = fan;
        fanSpeed = speed;
    }

    void setLight(bool light) {
        lightOn = light;
    }

    void setFanSpeed(int speed) {
        if (speed >= 0 && speed <= 5) {
            fanSpeed = speed;
        }
    }
        
};


void printRoom(Room* room) {
    cout << boolalpha << room->roomName << " " << room->lightOn << " " << room->temperature << " " << room->humidity << " " << room->fanOn << " " << room->fanSpeed << endl;
}

bool checkFan(Room room) {
    if (room.temperature > 24 || room.humidity > 65) {
        return true;
    }
    return false;
}

int main() {
    Room livingRoom("Living Room",true, 22, 50, true, 3);
    Room bedroom("Bedroom", false, 18, 40, false, 0);
    Room kitchen("Kitchen", true, 26, 70, true, 1);
    Room bathroom("Bathroom", true, 24, 60, true, 2);


    Room rooms[4] = {livingRoom, bedroom, kitchen, bathroom};

    while(true) {
        cout << "1. Search for a room:\n";
        cout << "2. Toggle Room Light\n";
        cout << "3. Check Fan Alert\n";
        cout << "4. Exit\n";
        
        int choice;
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        if (choice == 1) {
            cout << "Enter room name: ";
            string name;
            getline(cin, name);
            bool found = false;
            for (int i = 0; i < 4; i++) {
                if (rooms[i].roomName == name) {
                    printRoom(&rooms[i]);
                    found = true;
                }
            }
            if (!found) {
                cout << "Room not found\n";
            }
        }
        else if (choice == 2) {
            cout << "Enter room name: ";
            string name;
            getline(cin, name);
            bool found = false;
            for (int i = 0; i < 4; i++) {
                if (rooms[i].roomName == name) {
                    rooms[i].setLight(!rooms[i].lightOn);
                    printRoom(&rooms[i]);
                    found = true;
                }
            }
            if (!found) {
                cout << "Room not found\n";
            }
        }
        else if (choice == 3) {
            for (int i = 0; i < 4; i++) {
                if (checkFan(rooms[i])) {
                    cout << rooms[i].roomName << " has a fan alert!\n";
                }
            }
        }

        else if (choice == 4){
            break;
        }


    }


    return 0;
}