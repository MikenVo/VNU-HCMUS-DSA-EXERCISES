// Read README.md in https://github.com/MikenVo/VNU-HCMUS-DSA-EXERCISES/blob/main/PRACTICE/2526-2%20Sort%20Advanced/MergeSort to know the problem

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct element {
    int value;
    int index;
};

void inPlaceMerge(vector<element> &a, int start, int mid, int end) {
    int length = end - start + 1;
    int gap = (length / 2) + (length % 2);

    while (gap > 0) {
        for (int i = start; i + gap <= end; i++) {
            int j = i + gap;

            if (a[i].value > a[j].value) {
                element temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                cout << i << " " << j << "\n";
            }
        }

        if (gap == 1)
            break;

        gap = (gap / 2) + (gap % 2);
    }
}

void mergeSort(vector<element> &a, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        inPlaceMerge(a, start, mid, end);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<element> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].value;
        a[i].index = i;
    }

    mergeSort(a, 0, n - 1);

    return 0;
}