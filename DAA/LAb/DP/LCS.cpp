#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cout<<"enter the strings:- ";
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;

    string lcs;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            // This character is part of the LCS
            lcs.push_back(s1[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            // Move in the direction of the larger subproblem
            i--;
        }
        else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    // 4) Print the LCS string
    cout << lcs << "\n";
    return 0;
}