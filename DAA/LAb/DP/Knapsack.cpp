#include <bits/stdc++.h>
using namespace std;

void DP(vector<vector<int>> &B, int n, int W, vector<int> &value, vector<int> &weight) {
   
   for (int i = 0; i <= W; i++) {
       B[0][i] = 0;
   }
   for (int i = 0; i <= n; i++) {
       B[i][0] = 0;
   }

   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= W; j++) {
           if (weight[i-1] <= j) {
               B[i][j] = max(value[i-1] + B[i-1][j - weight[i-1]], B[i-1][j]);
               

           } else {
               B[i][j] = B[i-1][j];
               
           }
       }
   }

   cout << "Knapsack Table:\n";
   for (int i = 0; i <= n; i++) {
       for (int j = 0; j <= W; j++) {
           cout << B[i][j] << " ";
       }
       cout << endl;
   }

   for (int i = n; i > 0 && W > 0; i--) {
    if (B[i][W] != B[i - 1][W]) {  
        cout << "Item " << i << " (Weight: " << weight[i - 1] << ", Value: " << value[i - 1] << ")\n";
        W -= weight[i - 1];  
    }
}
   
}

int main() {
    int n, W;
    cout << "Enter the number of items and the total weight of the knapsack: ";
    cin >> n >> W;

    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }

    vector<vector<int>> B(n + 1, vector<int>(W + 1, 0));
    DP(B, n, W, value, weight);

    cout << "Maximum value achievable B[n][W]: " << B[n][W] << " Where n = " << n << " and W = "<< W  << endl;

    return 0;
}
