#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
void dp(int n,vector<int>d ,int amount,vector<vector<int>> &c){
    int v = 1;

    for(int i=0; i<=n; i++){
        c[i][0] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=amount; j++){
            if(i == 1 && j<d[i]){
               c[i][j] = INF;
            }
            else if (i ==1)
            {
                c[i][j] = 1+c[i][j-d[i]];
            }
            else if(j<d[i]){
                c[i][j] = c[i-1][j];
            }
            else{
                c[i][j] = min(c[i-1][j],1+c[i][j-d[i]]);
            }
            
        }
    }

}

int main(){
    int n;
    cout<<"enter the no of coins:- ";
    cin>>n;
    vector<int> coins(n);
    for(int i= 0; i<n; i++){
        cout<<"enter the coin "<<i<<":- ";
        cin>>coins[i];
    }

    int amount;
    cout<<"enter the amount:- ";
    cin>>amount;

    vector<vector<int>> c(n+1,vector<int>(amount+1,0));
    dp(n,coins,amount,c);
    int ans = c[n][amount];
    if(ans >= INF) {
        cout << "No solution possible\n";
        return 0;
    }
    cout << "Minimum coins required = " << ans << "\n";

    // Backtracking to list coins used
    vector<int> used;
    int i = n, j = amount;
    while(i > 0 && j > 0){
        // If this value came from c[i][j-coin] + 1, we used coin i-1
        if(j >= coins[i-1] && c[i][j] == c[i][j-coins[i-1]] + 1) {
            used.push_back(coins[i-1]);
            j -= coins[i-1];            // reduce remaining sum
        } else {
            i--;                        // move to previous coin
        }
    }

    cout << "Coins used: ";
    for(int c : used) cout << c << " ";
    cout << "\n";
    return 0;
}