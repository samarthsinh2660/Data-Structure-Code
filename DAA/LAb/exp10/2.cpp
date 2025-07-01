#include <iostream>
#include <vector>
using namespace std;

int findPeak(const vector<int>& A) {
    int lo = 0;
    int hi = int(A.size()) - 1;
   
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
     
        if (A[mid] < A[mid+1]) {
            lo = mid + 1;
        } 
        else {
            
            hi = mid;
        }
    }
    return lo; 
}

int main() {
    

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cerr << "Array size must be positive!\n";
        return 1;
    }

    vector<int> A(n);
    cout << "Enter " << n << " distinct numbers for the unimodal array:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Edge case: if only one element
    if (n == 1) {
        cout << "The peak entry is: " << A[0] << "\n";
        return 0;
    }

    int peakIdx = findPeak(A);
    cout << "The peak entry is: " << A[peakIdx]
         << " at index " << peakIdx << "\n";
    return 0;
}
