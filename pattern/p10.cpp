#include<iostream>
using namespace std;

int main(){
    int n;
    cin>> n;

    for(int i = 1; i<= n ; i++){
        for (int j = 1; j<=i ; j++)
        {
            char ch = 'A' + i -1; // for  a bc def ghihj use counting var c = 1 then c++ in 2nd loop
            cout<<ch << " ";   // for a bc cde defg char ch = 'A' - 1 + i +j-1
        }
        cout<<endl;
    }
}