// Read README.md in https://github.com/MikenVo/VNU-HCMUS-DSA-EXERCISES/tree/main/PRACTICE/2526-2%20Search/CountingWrongPairs to know the problem

#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unsigned int result = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                result++;
            }
            else {
                continue;
            }
        }
    }

    cout << result << endl;

    delete[] arr;
    return 0;
}