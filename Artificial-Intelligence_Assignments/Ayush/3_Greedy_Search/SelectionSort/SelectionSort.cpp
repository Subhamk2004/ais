#include <bits/stdc++.h>
using namespace std;

// Function to perform Selection Sort on vector 'arr'
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Assume the minimum is the first element of unsorted subarray
        int minIndex = i;
        // Find the actual minimum element in the unsorted portion
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum with the first unsorted element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements separated by spaces:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Perform Selection Sort
    selectionSort(arr);

    // Output the sorted array
    cout << "Sorted array in ascending order:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}