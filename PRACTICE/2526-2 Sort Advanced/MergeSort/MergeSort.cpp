#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// TODO: auxiliary function here

void inPlaceMerge(vector<int> &a, int start, int mid, int end) {
    int gap, firstindex, secondindex;

    for (gap = mid + 1; gap >= 1; gap /= 2) {
        for (int i = gap; i < end + 1; i++) {
            int temp = a[i];
            int j;
            for (j = i, firstindex = j; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
                secondindex = j - gap;
            }
            a[j] = temp;

            if (firstindex >= 0 && secondindex >= 0) {
                if (firstindex > secondindex) {
                    cout << secondindex << " " << firstindex << endl;
                }
                else if (firstindex < secondindex) {
                    cout << firstindex << " " << secondindex << endl;
                }
            }
            else {
                continue;
            }
        }
    }
    // TODO: inPlaceMerge logic, swapping and printing swapped positions here
}

void mergeSort(vector<int> &a, int start, int end) {
    int mid = start + (end - start) / 2;
    while (start < end) {
        if (end - start == 1 && mid >= 0) {
            inPlaceMerge(a, start, mid, end);
            
        }
        else {
            mergeSort(a, start, mid);
            mergeSort(a, mid + 1, end);
        }
    }
    // TODO: Merge sort with in-place merge calling here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }

    return 0;
}