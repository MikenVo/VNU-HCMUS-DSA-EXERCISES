# <p align="center"> C. Binary Search (STL sort allowed)</p>
<p align="center">time limit per test: 1 s.</p>
<p align="center">memory limit per test: 16 MB</p>

Given an integer array of length n and q query values x<sub>1</sub>, x<sub>2</sub>, … , x<sub>q</sub>, your task is to find, for each query x<sub>j</sub>, the element in the array whose value is closest to x<sub>j</sub>. If two or more elements are equally close (i.e., their absolute difference to x<sub>j</sub> is the same), you must select the largest such element by value.  
  
## Input
The input begins with a line containing two integers: n and q.  
The next line contains n space-separated integers a<sub>1</sub>, a<sub>2</sub>, … , a<sub>n</sub>.  
Each of the following q lines contains one integer x<sub>j</sub>.  

## Output
For each query x<sub>j</sub> (in the order given), output on its own line the value from the array that is closest to x<sub>j</sub>, breaking ties by selecting the largest value among those tied.

### Example
*Input*  
```
21 21  
0 14 12 -1 -16 40 -24 -1 1 -8 50 -43 7 -17 21 2 -24 13 12 22 -17  
24 9 -6 -2 -37 5 11 1 -1 -26 -35 -5 -44 -10 -19 39 36 14 19 -12 -4  
```
*Output*
```
22  
7  
-8  
-1  
-43  
7  
12  
1  
-1  
-24  
-43  
-8  
-43  
-8  
-17  
40  
40  
14  
21  
-8  
-1  
```
---

### Note
You are ALLOWED to use built-in sort function from STL of C++.  
You must implement your own searching logic (e.g., binary search or two-pointer scan). Use of built-in algorithms such as std::lower_bound, or std::binary_search is strictly prohibited.  
Constraints: 1 ≤ n, q ≤ 105 and all array values and query values lie within [−10<sup>9</sup>,10<sup>9</sup>].    

#### Template:
```cpp
#include <iostream>
#include <vector>

using namespace std;

int binarySearchNearest(const vector<int>& a, int n, int x) {
    // TODO: your Binary Search code here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    if (n <= 0) return 0;

    vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }

    quickSort(vals, 0, n - 1);

    while (q–) {
        int x;
        cin >> x;
        int nearest = binarySearchNearest(vals, n, x);
        cout << nearest << endl;
    }

    return 0;
}
```