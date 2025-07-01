#include <bits/stdc++.h>
using namespace std;

struct City {
    string name;
    int x, y;

    City(string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }
};

vector<City> citys;

void insertCity( string& name, int x, int y) {
    City city = {name, x, y};
    citys.push_back(city);
    cout << "City '" << name << "' added successfully.\n";
}

void searchcity(string& cityname){
    for (int i = 0; i < citys.size(); ++i) {
        if (citys[i].name == cityname) {
            cout << "City Found: " << citys[i].name << " at coordinates (" << citys[i].x << ", " << citys[i].y << ")\n";
            return;
        }
    }
    cout << "No city found with name: " << cityname << endl;
}

void deleteCity( string& cityname) {
    for (int i = 0; i < citys.size(); ++i) {
        if (citys[i].name == cityname) {
            citys.erase(citys.begin() + i);
            cout << "City '" << cityname << "' deleted successfully.\n";
            return;
        }
    }
    cout << "No city found with name: " << cityname << endl;
}

void printRecordWithinDistance(int x, int y, int distance) {
    for (int i = 0; i < citys.size(); ++i) {
        int dx = citys[i].x - x;
        int dy = citys[i].y - y;
        if (dx * dx + dy * dy <= distance * distance) {
            cout << "Name: " << citys[i].name << ", Coordinates: (" << citys[i].x << ", " << citys[i].y << ")\n";
        }
    }
    cout << "No cities found within the given distance.\n";

}
int main() {

    int choice;
    do {
        cout << "\n1. Insert \n";
        cout << "2. Search by name\n";
        cout << "3. Delete by name\n";
        cout << "4. Print the record within a given distance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name;
        int x, y, distance;

        switch (choice) {
            case 1:
                cout << "Enter city name, x, and y coordinates: ";
                cin >> name >> x >> y;
                insertCity( name, x, y);
                break;

            case 2:
                cout << "Enter city name to search: ";
                cin >> name;
                searchcity(name);
                break;

            case 3:
                cout << "Enter city name to delete: ";
                cin >> name;
                deleteCity(name);
                break;


            case 4:
                cout << "Enter x, y coordinates and distance: ";
                cin >> x >> y >> distance;
                printRecordWithinDistance(x, y, distance);
                break;
            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
