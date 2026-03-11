#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int testcases; cin >> testcases;

    for (int test = 0; test < testcases; test++) {
        // Initalization
        int len; cin >> len;
        int* arr = new int[len];
        int* arr2 = new int[len];
        int global_smallest;
        bool non_decreasing = true;

        // Input
        for (int turn = 0; turn < len; turn++) {
            cin >> arr[turn];
            arr2[turn] = arr[turn];
        }

        // We all know that the GCD between a smallest element with its multiples is always itself
        // Example: GCD(2, 8) = 2

        // Even if two numbers that have GCD != the smallest element, as long as they are divisible by it
        // We can still swap the positions of the two numbers.
        // Example:
        // An array has 4 and 8 and smallest element is 2
        // GCD(4, 8) = 4 != 2. However, 4 % 2 == 0 & 8 % 2 == 0 so we can swap the positions of 4 and 8 with 2

        // Algorithm:
        // - Create another array (has same elements), sort and use it as reference
        // - Check through each element in each array
        // - - If they are multiples of the smallest element, we can swap
        // - - Else there are two scenarios
        // - - - 1. The element is sorted -> we can skip
        // - - - 2. The element is not sorted -> we guarantee that we cannot sort the array with the operation

        // -----------------------------------------------

        // Example:
        // Test case 2
        // - Array 1: 4 3 6 6 2 9
        // - Array 2: 4 3 6 6 2 9 -> (Sorted) 2 3 4 6 6 9

        // - The smallest number: 2

        // - Check each element in each array:
        // - - Index 0: 4 (A1) != 2 (A2)
        // - - - Is 4 a multiple of 2? Yes, we can swap
        // - - Index 1: 3 (A1) == 3 (A2) -> Skip
        // - - Index 2: 6 (A1) != 4 (A2)
        // - - - Is 6 a multiple of 2? Yes, we can swap
        // - - Index 3: 6 (A1) != 6 (A2)
        // - - - Is 6 a multiple of 2? Yes, we can swap
        // - - Index 4: 2 (A1) != 6 (A2)
        // - - - Is 2 a multiple of 2? Yes, we can swap
        // - - Index 5: 9 (A1) == 9 (A2) -> Skip
        // => Print out "YES"

        // Test case 4
        // - Array 1: 7 5 2 2 4
        // - Array 2: 7 5 2 2 4 -> (Sorted) 2 2 4 5 7

        // - Check each element in each array:
        // - - Index 0: 7 (A1) != 2 (A22)
        // - - - Is 7 a multiple of 2? No, we are sure that we can't sort this array
        // => Print out "NO"

        // -----------------------------------------------

        // Find the smallest element in the array using linear search
        global_smallest = arr[0];
        for (int cur = 0; cur < len; cur++) {
            if (arr[cur] < global_smallest) {
                global_smallest = arr[cur];
            }
        }

        // Sort the second array to use it as reference
        mergeSort(arr2, 0, len - 1);

        // Compare each element from each array
        for (int cur = 0; cur < len; cur++) {
            if (arr[cur] == arr2[cur]) { // If the element is sorted, we skip
                continue;
            }
            else { // If not, we need to check if the element is divisible by the smallest element
                if (arr[cur] % global_smallest != 0) {
                    // If it cannnot be divisible, we immediately print out "NO"
                    // Because we are sure, we cannot swap its position
                    non_decreasing = false;
                    cout << "NO" << endl;
                    break;
                }
            }
        }

        if (non_decreasing) { // If everything is ok when reaches the end of the array, print out "YES"
            cout << "YES" << endl;
        }

        // Ending
        delete[] arr;
        delete[] arr2;
    }

    return 0;
}