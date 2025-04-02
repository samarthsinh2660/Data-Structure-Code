#include<iostream>
using namespace std;

int main(){
    
   int n, c = 65; 
   cin >> n;

   for(int i = 1; i <= n; i++){
       char ch = static_cast<char>(c);
       for (int j = 1; j <= n; j++) {
           cout << ch << " "; // or char hc = 'A' + i -1
       }
       cout << endl;
       c++; // Increment 'c' to get the next character
   }
 
   return 0;
}
