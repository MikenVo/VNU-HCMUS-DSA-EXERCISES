// Read README.md in https://github.com/MikenVo/VNU-HCMUS-DSA-EXERCISES/tree/main/PRACTICE/2526-2%20Search/LessorEqual to know the problem

#include <iostream>
#include <algorithm>
using namespace std;

void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        }
        else {
            arr[k] = R[j++];
        }
        k++;
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    // Inputs
    int n; cin >> n;
    int k; cin >> k;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array to find the largest number much easier
    mergeSort(arr, 0, n - 1);

    int largestnumber = 0;

    // Check if the (k-1)th position is in the array range
    if (k - 1 >= 0) {
        largestnumber = arr[k - 1]; // Set the largest number to the (k-1)th element
    }
    else {
        largestnumber = 1; // If the position is out of range, set the largest number to 1
    }

    // If the k-th element is equal to the largest number, then we print out -1.
    // - We cannot choose any number that k elements are less or equal to because k+1 elements will also be less or equal to.
    if (largestnumber == arr[k]) {
        cout << -1 << endl;
    }
    else {
        cout << largestnumber << endl;
    }

    // Example:
    // 7 4
    // 3 7 5 1 10 3 20
    
    // n = 7, k = 4
    // Sorted: 1 3 3 5 7 10 20
    // k - 1 = 4 - 1 = 3 (in the range)
    // largestnumber = arr[k-1] == 5
    // largestnumber != arr[k] (= 7)
    // Therefore, the largest number is 5

    return 0;
}