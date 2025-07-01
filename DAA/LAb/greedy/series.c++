#include <bits/stdc++.h>
using namespace std;

void bubbleSortActivities(pair<int,int> activities[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if (activities[j].first > activities[j+1].first) {
                swap(activities[j], activities[j+1]);
            }
        }
    }
}

void maxacti(int s[], int f[], int n) {
    vector<int> A;
    A.push_back(0);
    int last = 0;
    for(int i = 1; i < n; i++){
        if (s[i] >= f[last]) {
            A.push_back(i);
            last = i;
        }
    }
    cout << "Max activities are: ";
    for(int idx : A) cout << idx << " ";
    cout << "\n";
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> activities(n);
    for(int i = 0; i < n; i++){
        // read (start, finish) as (second, first)
        cin >> activities[i].second 
            >> activities[i].first;
    }

    // Sort by finish time using Bubble Sort
    bubbleSortActivities(activities.data(), n);

    // Extract start-times and finish-times into arrays
    vector<int> s(n), f(n);
    for(int i = 0; i < n; i++){
        s[i] = activities[i].second;
        f[i] = activities[i].first;
    }

    // Greedy activity selection
    maxacti(s.data(), f.data(), n);
    return 0;
}
