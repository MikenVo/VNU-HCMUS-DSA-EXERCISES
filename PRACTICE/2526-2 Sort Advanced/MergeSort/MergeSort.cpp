#include <iostream>
using namespace std;

// void merge(int arr[], int left, int mid, int right, int num) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     int* LEFT = new int[n1];
//     int* RIGHT = new int[n2];

//     for (int i = 0; i < n1; i++) {
//         LEFT[i] = arr[left + i];
//     }

//     for (int j = 0; j < n2; j++) {
//         RIGHT[j] = arr[mid + 1 + j];
//     }

//     int i = 0, j = 0, k = left;
//     int firstindex = 0, secondindex = 0;
//     while (i < n1 && j < n2) {
//         if (LEFT[i] <= RIGHT[j]) {
//             for (int i1 = 0; i1 < num; i1++) {
//                 if (arr[i1] == LEFT[i]) {
//                     firstindex = i1;
//                     break;
//                 }
//             }
//             arr[k++] = LEFT[i++];
//         }
//         else {
//             for (int i2 = 0; i2 < num; i2++) {
//                 if (arr[i2] == RIGHT[j]) {
//                     secondindex = i2;
//                     break;
//                 }
//             }
//             arr[k++] = RIGHT[j++];
//         }

//         if (firstindex > secondindex) {
//             cout << secondindex << " " << firstindex << endl;
//         }
//         else if (firstindex < secondindex) {
//             cout << firstindex << " " << secondindex << endl;
//         }
//     }

//     while (i < n1) {
//         arr[k++] = LEFT[i++];
//     }

//     while (j < n2) {
//         arr[k++] = RIGHT[j++];
//     }

//     delete[] LEFT;
//     delete[] RIGHT;
// }

// void mergeSort(int arr[], int left, int right, int num) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergeSort(arr, left, mid, num);
//         mergeSort(arr, mid + 1, right, num);
//         merge(arr, left, mid, right, num);
//     }
// }

void mergeSort(int arr[], int left, int right, int num) {
    int mid = left + (right - left) / 2;
    if (left < right) {
        mergeSort(arr, left, mid, num);
        mergeSort(arr, mid + 1, right, num);
    }
    else {
        if (arr[left] > arr[right + 1]) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
}

int main() {
    int num; cin >> num;
    int* arr = new int[num];

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    int left = 0, right = num - 1;
    mergeSort(arr, left, right, num);

    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}