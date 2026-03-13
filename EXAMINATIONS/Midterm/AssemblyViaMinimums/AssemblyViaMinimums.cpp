#include <iostream>
#include <cmath>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int t; cin >> t; // Input the number of test cases
    for (int test = 0; test < t; test++) {
        int n; cin >> n; // Input the length of array a
        int lenb = n * (n - 1) / 2; // Calculate the length of array b
        int skip = 0, counter = 0, step = n - 1;

        int* array_a = new int[n](); // Initialize the array a
        int* array_b = new int[lenb + 1](); // Initialize the array b

        // Input array
        for (int i = 0; i < lenb; i++) {
            cin >> array_b[i];
        }

        // Sort the array b
        MergeSort(array_b, 0, lenb - 1);

        if (n != 2) { // If n == 2, we guarantee that the size of array b is 1
            while (counter <= n - 1) {
                array_a[counter] = array_b[skip]; // Assign the current element after skips

                skip += step; // Adjust the skip to find new element
                step--;

                counter++;
            }
            array_a[n - 1] = 1000000000; // Set the last element to the 1000000000. We guarantee the result will always be valid
        }
        else {
            // Because the size of array is 1, we just duplicate the elements to get the array a
            array_a[0] = array_b[0];
            array_a[1] = array_b[0];
        }   

        // Print out
        for (int i = 0; i < n; i++) {
            cout << array_a[i] << " ";
        }

        cout << endl;

        delete[] array_a;
        delete[] array_b;
    }

    return 0;
}