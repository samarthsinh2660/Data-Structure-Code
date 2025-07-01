#include <bits/stdc++.h>
using namespace std;

using matrix = vector<vector<int>>;

matrix add(matrix A, matrix B, int n){
    matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++){
           C[i][j] = A[i][j] + B[i][j];
        }

    }
    return C;
}
 
matrix sub(matrix A, matrix B, int n){
    matrix C(n, vector<int>(n));
    for(int i =0 ; i< n ; i++){
        for(int j = 0 ; j < n ; j++){
           C[i][j] =  A[i][j] - B[i][j];
        }
    }
    return C;
}

matrix strassen(matrix A, matrix B, int n){
 if(n==1){
    return matrix{{ A[0][0] * B[0][0] }};
 }

 int m = n/2;
 matrix A11(m, vector<int>(m)), A12(m, vector<int>(m)),
        A21(m, vector<int>(m)), A22(m, vector<int>(m));
 matrix B11(m, vector<int>(m)), B12(m, vector<int>(m)),
        B21(m, vector<int>(m)), B22(m, vector<int>(m));

    for(int i =0 ; i< m; i++){
        for(int j=0; j<m; j++){
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i+m][j];
            B22[i][j] = B[i+m][j+m];
        }
    }

    for(int i =0 ; i< m; i++){
        for(int j=0; j<m; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i+m][j];
            A22[i][j] = A[i+m][j+m];
        }
    }

    matrix P = strassen(add(A11, A22, m), add(B11, B22, m), m);
    matrix Q = strassen(add(A21, A22, m), B11, m);  
    matrix R = strassen(A11 , sub(B12,B22,m), m);
    matrix S = strassen(A22 , sub(B21, B11, m), m);
    matrix T = strassen(add(A11, A12 , m), B22 , m);
    matrix U = strassen(sub(A21, A11, m),add(B11, B12 , m), m);
    matrix V = strassen(sub(A12 , A22 , m) , add(B21 , B22 , m), m);

   matrix C11 = add(sub(add(P, S, m), T, m), V, m);
   matrix C12 = add(R, T, m);
   matrix C21 = add(Q, S, m);
   matrix C22 = add(sub(add(P, R, m), Q, m), U, m);
    
   matrix C(n, vector<int>(n));
   for(int i = 0 ; i < m ; i++){
    for(int j =0 ; j < m ; j++){
        C[i][j] = C11[i][j];
        C[i][j + m] = C12[i][j];
        C[i+m][j] = C21[i][j];
        C[i+m][j+m]= C22[i][j];
    }
   }
   return C;
}

int main(){
    int n;
    cout<< "enter the size of the matrix:- ";
    cin>> n;
    cout<< "enter the matrix A: " <<endl;
    matrix A(n, vector<int>(n)), B(n, vector<int>(n));
    for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> A[i][j];
        }
    }
    cout<< "enter the matrix B: " <<endl;
    for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> B[i][j];
        }
    }

    matrix C = strassen(A, B, n);
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++){
            cout << C[i][j] << " ";
        }
        cout<< endl;
    }
    
    return 0;
}