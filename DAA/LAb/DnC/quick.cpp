#include <bits/stdc++.h>
using namespace std;

static int comparisons = 0;
static int swaps = 0;

void doSwap(int &a, int &b) {
    std::swap(a, b);
    ++swaps;
}

int partition(vector<int> &a, int low, int high) {
    int pivot = a[low];
    int left  = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= right && a[left] <= pivot) {
            ++comparisons;
            ++left;
        }
        while (left <= right && a[right] > pivot) {
            ++comparisons;
            --right;
        }
        if (left < right) {
            doSwap(a[left], a[right]);
        }
    }
    doSwap(a[low], a[right]);
    return right;
}

void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Original Array: ";
    for (auto &x : a) cout << x << ' ';
    cout << "\n";

    quickSort(a, 0, n - 1);

    cout << "Sorted Array:   ";
    for (auto &x : a) cout << x << ' ';
    cout << "\n\n";

    cout << "Total Comparisons: " << comparisons << "\n";
    cout << "Total Swaps:       " << swaps << "\n";

    return 0;
}
