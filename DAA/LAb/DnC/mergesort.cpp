#include <iostream>
#include <vector>
using namespace std;

static int comparisons = 0;
static int movements = 0;
static int recursion_calls = 0;

void merge_sort_merge(vector<int>& arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Temporary buffers
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; ++i)
        left[i] = arr[p + i];
    for (int j = 0; j < n2; ++j)
        right[j] = arr[q + 1 + j];

    int i = 0, j = 0;
    for (int k = p; k <= r; ++k) {
        ++comparisons;
        if (i < n1 && (j >= n2 || left[i] <= right[j])) {
            arr[k] = left[i++];
        } else {
            arr[k] = right[j++];
        }
        ++movements;
    }
}

void merge_sort(vector<int>& arr, int p, int r) {
    if (p < r) {
        ++recursion_calls;
        int q = p + (r - p) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge_sort_merge(arr, p, q, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    merge_sort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int x : arr)
        cout << x << ' ';
    cout << "\n\n";

    cout << "Total comparisons: " << comparisons << "\n";
    cout << "Total movements:   " << movements   << "\n";
    cout << "Total recursive calls: " << recursion_calls << "\n";

    return 0;
}
