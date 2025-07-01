#include <bits/stdc++.h>
using namespace std;

class City {
public:
    string name;
    int x, y;
    City* next;

    City(string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
        this->next = NULL;
    }
};

void insertH(City*& head, string name, int x, int y) {
    City* n = new City(name, x, y);
    n->next = head;
    head = n;
}

void insertt(City*& tail, string name, int x, int y) {
    City* n = new City(name, x, y);
    if (tail) {
        tail->next = n;
        tail = n;
    } else {
        tail = n;
    }
}

void searchCity(City* head, const string& cityName) {
    City* temp = head;
    while (temp != NULL) {
        if (temp->name == cityName) {
            cout << "City Found: " << temp->name << " at coordinates (" << temp->x << ", " << temp->y << ")\n";
            return;
        }
        temp = temp->next;
    }
    cout << "No city found with name: " << cityName << endl;
}

void deleteCity(City*& head, const string& cityName) {
    City* temp = head;
    City* prev = nullptr;

    while (temp != NULL) {
        if (temp->name == cityName) {
            if (temp == head) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "City '" << cityName << "' deleted successfully\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "No city found with name: " << cityName << endl;
}

void printAllCities(City* head) {
    City* temp = head;
    if (temp == NULL) {
        cout << "No cities in the list.\n";
        return;
    }

    while (temp != NULL) {
        cout << "City Name: " << temp->name << ", Coordinates: (" << temp->x << ", " << temp->y << ")\n";
        temp = temp->next;
    }
}

int main() {
    City* node = new City("Ahmedabad", 25, 36);
    City* head = node;
    City* tail = node;

    int choice;
    do {
        cout << "\n1. Insert at head\n";
        cout << "2. Insert at tail\n";
        cout << "3. Search by city name\n";
        cout << "4. Delete by city name\n";
        cout << "5. Print all cities\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name;
        int x, y;

        switch (choice) {
            case 1:
                cout << "Enter city name, x, and y coordinates: ";
                cin >> name >> x >> y;
                insertH(head, name, x, y);
                break;

            case 2:
                cout << "Enter city name, x, and y coordinates: ";
                cin >> name >> x >> y;
                insertt(tail, name, x, y);
                break;

            case 3:
                cout << "Enter city name to search: ";
                cin >> name;
                searchCity(head, name);
                break;

            case 4:
                cout << "Enter city name to delete: ";
                cin >> name;
                deleteCity(head, name);
                break;

            case 5:
                printAllCities(head);
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
