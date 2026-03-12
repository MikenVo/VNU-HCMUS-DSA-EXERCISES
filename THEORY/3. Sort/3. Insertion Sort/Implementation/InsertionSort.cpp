// Problem: Implement Insertion sort

#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    // Example: [4, 13, 5, 3]
    
    // [4 (sorted), 13 - current, 5, 3] - i = 1, j = 1
    // (arr[1] = 13 > arr[0] = 4) && 1 > 0 => False => Skip
    
    // [4 (sorted), 13 (sorted), 5 - current, 3] - i = 2, j = 2
    // (arr[2] = 5 < arr[1] = 13) && 2 > 0 => True => Swap arr[2] and arr[1]
    // j = 1
    // [4 (sorted), 5 - current, 13, 3] - i = 2, j = 1
    // (arr[1] = 5 > arr[0] = 4) && 1 > 0 => False => Skip
    
    // [4 (sorted), 5 (sorted), 13, 3 - current] - i = 3, j = 3
    // (arr[3] = 3 < arr[2] = 13) && 3 > 0 => True => Swap arr[3] and arr[2]
    // j = 2
    // [4 (sorted), 5 (sorted), 3 - current, 13] - i = 3, j = 2
    // (arr[2] = 3 < arr[1] = 5) && 2 > 0 => True => Swap arr[2] and arr[1]
    // j = 1
    // [4 (sorted), 3 - current, 5, 13] - i = 3, j = 1
    // (arr[1] = 3 < arr[0] = 4) && 1 > 0 => True => Swap arr[1] and arr[0]
    // j = 0
    // [3 - current, 4, 5, 13] - i = 3, j = 0
    // (arr[0] = 3 ? arr[-1]) && 0 == 0 => False => Skip

    // [3, 4, 5, 13] - i = 4 => End

    for (int i = 1; i < n; i++) { // Compare the current element with the last sorted element
        int j = i; // Take the current element to compare to all the sorted element in the array
        while (arr[j] < arr[j - 1] && j > 0) { // If the before element > the current element, swap
            // Swap the two elements
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            --j; // Reduce to ensure the current element is fully sorted
        }
    }
}

int main() {
    // Initialization
    int n; cin >> n; // Initialize the variable to get the number of elements in the array
    int* arr = new int[n]; // Initialize a memory-allocated array

    // Input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ---

    // Insertion Sort
    InsertionSort(arr, n);

    // Print out the array
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << arr[i];
            break;
        }
        cout << arr[i] << ", ";
    }
    cout << "]";

    // ---

    // Ending
    delete[] arr;

    return 0;
}