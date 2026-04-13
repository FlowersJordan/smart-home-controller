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


void printRoom(Room room) {
    cout << boolalpha << room.roomName << " " << room.lightOn << " " << room.temperature << " " << room.humidity << " " << room.fanOn << " " << room.fanSpeed << endl;
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

    string roomSearch;
    cout << "Enter Room Name: " << "\n";

    getline(cin, roomSearch);

    bool found = false;
    
    for (int i = 0; i < 4; i++) {
        if (rooms[i].roomName == roomSearch) {
            printRoom(rooms[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Room not found\n";
    }


    return 0;
}