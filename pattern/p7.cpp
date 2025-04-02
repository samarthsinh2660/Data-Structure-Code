#include<iostream>
using namespace std;

int main(){
    
   int n;  
   cin >> n;

   for(int i = 1; i <= n; i++){
       for (int j = 1; j <= n; j++) {
        char hc = 'A' + j -1;
           cout << hc<< " ";
           
       }
       cout << endl;
  
   }
 
   return 0;
}
