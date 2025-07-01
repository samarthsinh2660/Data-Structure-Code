#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    double budget;
    cout << "Enter number of food items: ";
    cin >> n;

    vector<double> food_cost(n);
    vector<int> food_qty(n);

    cout << "Enter quantity and cost of each food item:\n";
    for (int i = 0; i < n; i++) {
        cin >> food_qty[i] >> food_cost[i];
    }

    cout << "Enter number of decoration items: ";
    cin >> m;

    vector<double> decor_cost(m);
    vector<int> decor_qty(m);

    cout << "Enter quantity and rate of each decoration item:\n";
    for (int j = 0; j < m; j++) {
        cin >> decor_qty[j] >> decor_cost[j];
    }

    cout << "Enter total budget: ";
    cin >> budget;

    // Combined item list: (cost, quantity, index, type)
    vector<pair<double, pair<int, pair<int, char>>>> items;

    for (int i = 0; i < n; i++) {
        items.push_back({food_cost[i], {food_qty[i], {i + 1, 'F'}}});
    }
    for (int j = 0; j < m; j++) {
        items.push_back({decor_cost[j], {decor_qty[j], {j + 1, 'D'}}});
    }

    // Sort by cost per unit (ascending)
    sort(items.begin(), items.end());

    int totalUnits = 0;
    vector<pair<char, int>> boughtItems;

    for (auto &item : items) {
        double cost = item.first;
        int qty = item.second.first;
        int index = item.second.second.first;
        char type = item.second.second.second;

        int canBuy = min(qty, (int)(budget / cost));
        if (canBuy > 0) {
            totalUnits += canBuy;
            budget -= canBuy * cost;
            boughtItems.push_back({type, index});
        }
        if (budget <= 0)
            break;
    }

    cout << "\nMaximum number of items purchased: " << totalUnits << endl;
    cout << "Items purchased (Type, Index):\n";
    for (auto &x : boughtItems) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}