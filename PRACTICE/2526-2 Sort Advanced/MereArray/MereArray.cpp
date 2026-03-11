#include <iostream>
using namespace std;

int main() {
    int testcases; cin >> testcases;

    for (int i = 0; i < testcases; i++) {
        int len; cin >> len;
        int* arr = new int[len];
        int* smallest = arr;

        for (int j = 0; j < len; j++) {
            cin >> arr[j];
            if (j != 0) {
                if (arr[j] < *(smallest)) {
                    smallest += j;
                }
            }
        }

        cout << *(smallest);

        delete[] arr;
    }

    return 0;
}