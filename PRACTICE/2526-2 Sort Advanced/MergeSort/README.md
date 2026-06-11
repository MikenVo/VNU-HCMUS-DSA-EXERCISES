# <p align="center"> A. Merge Sort </p>
<p align="center"> time limit per test: 1 second </p>
<p align="center"> memory limit per test: 16 megabytes </p>

You are given a sequence of **n** distinct integers that forms a permutation of the integers from **1** to **n**. Your task is to sort this permutation into non–decreasing order by repeatedly swapping pairs of elements. Each time you perform a swap, record the two indices involved (always printing the smaller index first). At the end, you should output the entire sequence of recorded swaps in the order they were performed.

## Input
The first line contains a single integer **n** — the length of the permutation. The second line contains **n** space-separated integers **$a_1, a_2, …, a_n$**, denoting the initial permutation of **{1, 2, …, n}**.

## Output
On each line, output two integers **i** and **j** **$(1 \le i < j \le n )$**, indicating that the elements at positions **i** and **j** were swapped. The total number of lines should equal the number of swaps your algorithm performed to sort the array.

### Example
#### Input

```
21
20 11 13 12 9 18 3 4 19 6 7 17 2 14 10 16 1 8 21 5 
```

#### Output
```
0 1
1 2
3 4
0 3
1 4
2 5
1 3
2 4
2 3
8 10
8 9
0 6
1 7
2 8
3 9
4 7
5 8
4 6
7 9
8 10
5 6
8 9
11 12
12 13
12 14
13 15
13 14
17 19
18 20
18 19
11 16
12 17
13 18
14 19
13 16
14 17
15 18
14 16
12 13
15 16
18 19
0 11
1 12
2 13
8 19
5 11
6 12
7 13
8 14
9 15
10 16
2 5
3 6
4 7
10 13
14 17
15 18
16 19
10 12
4 5
7 8
10 11
16 17
```

## Note
- The array is a permutation of the integers from **1** to **n**.
- Swaps must be printed as pairs of 0-based indices **(i,j)** with **$0 \le i < j < n$**.
- After applying all swaps sequentially, the array will be sorted in non–decreasing order.
- Implementation must use the Merge Sort algorithm with constraint n≤105.

### Template:

```cpp
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// TODO: auxiliary function here

void inPlaceMerge(vector<int> &a, int start, int mid, int end)
{
    // TODO: inPlaceMerge logic, swapping and printing swapped positions here
}

void mergeSort(vector<int> &a, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    // TODO: Merge sort with in-place merge calling here
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    return 0;
}
```