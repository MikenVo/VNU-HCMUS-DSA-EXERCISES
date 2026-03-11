// Problem: Implement Shell Sort

#include <iostream>
using namespace std;

void ShellSort(int arr[], int n) {
    int gap = n / 2; // Store the initial gap
    while (gap >= 1) { // The loop stops when the gap < 1
        // Insertion sort between elements stand gap intervals
        for (int i = gap; i < n; i += gap) {
            int j = i;
            while (arr[j] < arr[j - gap] && j > 0) {
                int temp = arr[j];
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
                j -= gap;
            }
        }

        // Reduce the gap
        gap /= 2;
    }
}

int main() {
    // Initialization
    int n; cin >> n; // Input the number of elements
    int* arr = new int[n]; // Initialize the array

    // Input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ---

    // Shell Sort
    ShellSort(arr, n);

    // Print out
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