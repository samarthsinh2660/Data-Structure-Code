#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print asterisks
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        // Move to the next line
        cout << endl;
    }

    return 0;
}
