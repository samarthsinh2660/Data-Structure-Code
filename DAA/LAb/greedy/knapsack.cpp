#include <bits/stdc++.h>
using namespace std;

// Each item has a value and a weight
struct Item {
    double value, weight;
};

int main() {

    int n;
    double capacity;
    cin >> n >> capacity;  

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    // Sort items by decreasing value/weight ratio
    sort(items.begin(), items.end(),
         [](const Item &a, const Item &b) {
             return (a.value / a.weight) > (b.value / b.weight);
         });  

    double maxValue = 0.0;

    // Greedily take as much as possible from highest ratio first
    for (auto &it : items) {
        if (capacity == 0) break;

        double take = min(it.weight, capacity);
        maxValue += take * (it.value / it.weight);
        capacity -= take;
    }

    // Print result with two decimal places
    cout << fixed << setprecision(2) << maxValue << "\n";
    return 0;
}
