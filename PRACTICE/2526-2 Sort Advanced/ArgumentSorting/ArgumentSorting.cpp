#include <iostream>
using namespace std;

// Use struct in order to store the value and its prior index
struct element {
    int value;
    int index;
};

// Merge sort
void merge(element arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    element* L = new element[n1];
    element* R = new element[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].value <= R[j].value) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(element arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int len; cin >> len; // Input the number of elements
    element* arr = new element[len]; // Initialize an array

    // Array input
    for (int i = 0; i < len; i++) {
        cin >> arr[i].value;
        arr[i].index = i;
    }

    // Use a struct to save both the value and the prior index
    // When the array is sorted, we can still extract the prior indices

    // Sort the array, but the prior indices are still kept
    mergeSort(arr, 0, len - 1);

    // Print out
    for (int i = 0; i < len; i++) {
        cout << arr[i].index << " ";
    }

    // Ending
    delete[] arr;

    return 0;
}