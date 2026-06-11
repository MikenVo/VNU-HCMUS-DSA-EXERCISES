#include <iostream>
using namespace std;

void ShellSort(int arr[], int n) {

    int gap = n / 2;
    while (gap >= 1) {
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
    // Students are not allowed to use <string>
    // - Memory-allocated arrays
    // - Stack-memory arrays

    int testcases; cin >> testcases; // Get the number of test cases
    for (int i = 0; i < testcases; i++) {
        int num_arrays; cin >> num_arrays; // Get the number of arrays
        int num_elements; // Get the number of elements

        int **twodp = new int *[num_arrays]; // Pointer to the 2D array

        // Get inputs
        for (int i = 0; i < num_arrays; i++) {
            cin >> num_elements; // Get the number of elements
            twodp[i] = new int[num_elements](); // Create an array with full zeros

            for (int j = 0; j < num_elements; j++) {
                cin >> twodp[i][j];
            }

            ShellSort(twodp[i], num_elements);
        }

        // Because of the rules, the player can only move integers from on array once
        // Therefore, we are sure that the second minimum element will contribute to the beauty

        // In the arrays, it is guaranteed that the smallest element in the whole test case is joined in the beauty
        // We can conclude to maximize the beauty, the remaining operands must be the largest in their array

        // ------

        // Example: Test case 3
        // 1001 7 1007 5
        // 8 11 6
        // 2 9

        // We sort the arrays:
        // 5 7 1001 1007
        // 6 8 11
        // 2 9
        
        // We have the smallest minimum element in the arrays is 2
        // Therefore, beauty = 2 + ...
        
        // Because we want the maximum possible beauty, the two other operands (because there are only three arrays) must be the
        // second minimum elements

        // Because the arrays are sorted, we can easily extract these numbers.


        // Find the smallest minimum element
        long long smallest = twodp[0][0];
        for (int i = 0; i < num_arrays; i++) {
            if (twodp[i][0] < smallest) {
                smallest = twodp[i][0];
            }
        }

        long long second_smallest = twodp[0][1];
        long long total = 0;
        for (int i = 0; i < num_arrays; i++) {
            if (twodp[i][1] < second_smallest) {
                second_smallest = twodp[i][1];
            }
            total += twodp[i][1];
        }

        // Because three second minimum element sum up we need to minus the smallest second minimum and add the smallest minimum element
        total = total - second_smallest + smallest;
        cout << total << endl;

        // Deallocation
        for (int i = 0; i < num_arrays; i++) {
            delete[] twodp[i];
        }
        delete[] twodp;
    }

    return 0;
}