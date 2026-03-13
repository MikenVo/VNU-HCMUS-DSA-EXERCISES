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
        int cur = 0;
        int counter = 0;

        int* array_a = new int[n](); // Initialize the array a
        int* array_b = new int[lenb + 1](); // Initialize the array b

        for (int i = 0; i < lenb; i++) {
            cin >> array_b[i];
        }

        MergeSort(array_b, 0, lenb - 1);

        cur = array_b[0];
        array_a[counter] = cur;

        for (int i = 0; i < lenb + 1; i++) {
            if (array_b[i] != cur) {
                counter++;
                cur = array_b[i];
                array_a[counter] = cur;
            }
        }

        array_a[counter] = array_a[n - 2] + array_a[n - 1];

        for (int i = 0; i < n; i++) {
            cout << array_a[i] << " ";
        }

        cout << endl;

        delete[] array_a;
        delete[] array_b;
    }

    return 0;
}