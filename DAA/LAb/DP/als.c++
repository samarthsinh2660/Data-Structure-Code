#include <bits/stdc++.h>
using namespace std;

/*
 Assembly Line Scheduling
 Input:
   n             = number of stations per line
   e1, e2        = entry times for line 1 and line 2
   x1, x2        = exit times for line 1 and line 2
   a1[1..n], a2[1..n] = processing times at each station on line 1 and 2
   t1[2..n], t2[2..n] = transfer times from previous station on opposite lines
 Output:
   Minimum total time and optimal line choices
*/

int main() {
    int n;
    cin >> n;

    int e1, e2, x1, x2;
    cin >> e1 >> e2;        // entry times
    cin >> x1 >> x2;        // exit times

    vector<int> a1(n+1), a2(n+1);
    for(int j = 1; j <= n; j++) cin >> a1[j];  // line 1 times
    for(int j = 1; j <= n; j++) cin >> a2[j];  // line 2 times

    vector<int> t1(n+1), t2(n+1);
    for(int j = 2; j <= n; j++) cin >> t1[j];  // transfer to line 1
    for(int j = 2; j <= n; j++) cin >> t2[j];  // transfer to line 2

    // f[i][j] = min time to reach station j on line i
    vector<vector<int>> f(3, vector<int>(n+1));
    // l[i][j] = line chosen at station j-1 to get here
    vector<vector<int>> l(3, vector<int>(n+1));

    // Initialization for station 1
    f[1][1] = e1 + a1[1];
    f[2][1] = e2 + a2[1];

    // Build up DP for stations 2..n
    for(int j = 2; j <= n; j++) {
        // line 1: either stay on 1, or transfer from 2
        if (f[1][j-1] + a1[j] <= f[2][j-1] + t2[j] + a1[j]) {
            f[1][j] = f[1][j-1] + a1[j];
            l[1][j] = 1;
        } else {
            f[1][j] = f[2][j-1] + t2[j] + a1[j];
            l[1][j] = 2;
        }
        // line 2: either stay on 2, or transfer from 1
        if (f[2][j-1] + a2[j] <= f[1][j-1] + t1[j] + a2[j]) {
            f[2][j] = f[2][j-1] + a2[j];
            l[2][j] = 2;
        } else {
            f[2][j] = f[1][j-1] + t1[j] + a2[j];
            l[2][j] = 1;
        }
    }

    // Add exit times and choose best line at station n
    int T1 = f[1][n] + x1;
    int T2 = f[2][n] + x2;
    int bestLine = (T1 <= T2 ? 1 : 2);
    int bestTime = min(T1, T2);

    // Backtrack to find optimal path
    vector<int> path(n+1);
    path[n] = bestLine;
    for(int j = n; j > 1; j--) {
        path[j-1] = l[path[j]][j];
    }

    // Output results
    cout << "Minimum time: " << bestTime << "\n";
    cout << "Optimal path: ";
    for(int j = 1; j <= n; j++) {
        cout << "(" << path[j] << "," << j << ") ";
    }
    cout << "\n";
    return 0;
}
