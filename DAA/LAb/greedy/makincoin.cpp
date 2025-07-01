#include <bits/stdc++.h>
using namespace std;

void sort(vector<int>& coins ,int n){
    for(int i = 0 ; i< n-1 ; i++){
        for(int j = 0 ; j < n-1-i ; j++){
            if(coins[j] > coins[j+1]){
                swap(coins[j],coins[j+1]);
            }
        }
    }
}
void makingchange(int sum , vector<int>& coins){
    vector<int> ans;
    while (sum != 0){
       for(int i = coins.size()-1 ; i >=0 ; i--){
         if(sum >= coins[i]){
             sum -= coins[i];
             ans.push_back(coins[i]);
         }
         if( sum < 0){
            cout<<"Not possible";
            break;
         }
       }
    }
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int val,n;
    cout<<"Enter the value of the coins ";
    cin>>val;
    cout<<"Enter the number of coins ";
    cin>>n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cout<<"Enter the value of coin "<<i<<" ";
        cin>>coins[i];
    }
    sort(coins, n);
    makingchange(val,coins);
    return 0;
}