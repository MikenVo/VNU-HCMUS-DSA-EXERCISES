#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* LEFT = new int[n1];
    int* RIGHT = new int[n2];

    for (int i = 0; i < n1; i++) {
        LEFT[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        RIGHT[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (LEFT[i] <= RIGHT[j])
            arr[k++] = LEFT[i++];
        else
            arr[k++] = RIGHT[j++];
    }
    while (i < n1)
        arr[k++] = LEFT[i++];
    while (j < n2)
        arr[k++] = RIGHT[j++];

    delete[] LEFT;
    delete[] RIGHT;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + (right - left)) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int num; cin >> num;
    int* arr = new int[num];

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, num - 1);

    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}