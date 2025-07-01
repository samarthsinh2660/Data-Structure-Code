#include <bits/stdc++.h>
using namespace std;

// Check if placing at (newRow, newCol) is safe
bool isSafe(const vector<int>& colForRow, int newRow, int newCol) {
    for(int row = 0; row < newRow; row++) {
        int col = colForRow[row];
        // check col and dig
        if (col == newCol ||
            abs(col - newCol) == abs(row - newRow)) {
            return false;
        }
    }
    return true;
}

// Backtracking 
bool solveNQ(int N, int row, vector<int>& colForRow) {
    if (row == N) {
        // All N queens placed successfully
        return true;
    }
    for(int c = 0; c < N; c++) {
        if (isSafe(colForRow, row, c)) {
            colForRow[row] = c;          // place queen
            if (solveNQ(N, row + 1, colForRow))
                return true;             // success! unwind
            // else backtrack: try next column
        }
    }
    return false;  // no valid column found in this row
}

int main(){
    int N;
    cout << "Enter N (size of board): ";
    cin >> N;
    //It places one queen per row, uses a 1D array colForRow[] where colForRow[r] = c means “queen in row r at column c
    vector<int> colForRow(N, -1);
    if (!solveNQ(N, 0, colForRow)) {
        cout << "No solution exists.\n";
        return 0;
    }


    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cout << (colForRow[r] == c ? 'Q' : '.') << ' ';
        }
        cout << "\n";
    }
    return 0;
}
