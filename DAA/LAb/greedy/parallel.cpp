#include <bits/stdc++.h>
using namespace std;

// A simple struct to hold an interval's start and end.
struct Interval {
    int start, end;
};

// Perform interval scheduling: select the maximum number of non‐overlapping intervals.
vector<Interval> intervalScheduling(vector<Interval>& activities) {
    // 1. Sort by end time
    sort(activities.begin(), activities.end(),
         [](const Interval& a, const Interval& b) {
             return a.end < b.end;
         });

    vector<Interval> chosen;
    int lastEnd = -1;

    // 2. Greedily pick each activity if it starts after the last selected end
    for (auto& act : activities) {
        if (act.start >= lastEnd) {
            chosen.push_back(act);
            lastEnd = act.end;
        }
    }
    return chosen;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end;
    }

    auto result = intervalScheduling(activities);

    // Output the count and the selected intervals
    cout << "Maximum number of non-overlapping intervals: " 
         << result.size() << "\n";
    cout << "Selected intervals (start, end):\n";
    for (auto& act : result) {
        cout << act.start << " " << act.end << "\n";
    }
    return 0;
}
