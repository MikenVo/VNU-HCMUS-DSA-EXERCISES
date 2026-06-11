// Problem: Given n students with k scores. Sort the list of students based on the scores.
// - Constraint: The algorithm must have the time complexity O(n)

#include <iostream>
using namespace std;

void sort(double arr[], int n) {
    int* arr2 = new int[101]();
    for (int i = 0; i < n; i++) {
        int index = (double)(arr[i] * 10);
        arr2[index]++;
    }

    int counter = 0;
    int counter2 = 0;
    while (counter < 101) {
        while(arr2[counter] != 0) {
            arr[counter2++] = (double)(counter / 10.0);
            arr2[counter]--;
        }
        counter++;
    }

    delete[] arr2;
}

int main() {
    int n; cin >> n; // Input the number of students
    double* arr = new double[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}