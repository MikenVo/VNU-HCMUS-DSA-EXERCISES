#include <iostream>
using namespace std;

void ShellSort(int arr[], int n) {
    int gap = n / 2;
    
    while (gap >= 1) {
        for (int i = gap; i < n; i += gap) {
            int j = i;
            while (j >= gap && arr[j] < arr[j - gap]) {
                int temp = arr[j];
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
                j -= gap;
            }
        }

        gap /= 2;
    }
}

int main() {
    int n; cin >> n;
    int* arr = new int[n];
    bool should_accept = false;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ShellSort(arr, n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j] && arr[j] + arr[k] > arr[i]) {
                    should_accept = true;
                    break;
                }
            }

            if (should_accept) {
                break;
            }
        }

        if (should_accept) {
            break;
        }
    }

    if (should_accept) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    delete[] arr;

    return 0;
}