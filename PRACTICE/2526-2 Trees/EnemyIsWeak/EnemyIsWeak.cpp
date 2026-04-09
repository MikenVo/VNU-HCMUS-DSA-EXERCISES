#include <iostream>
#include <algorithm>
using namespace std;

void update(long long *tree, int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] += val;
        return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid)
        update(tree, 2 * node, start, mid, idx, val);
    else
        update(tree, 2 * node + 1, mid + 1, end, idx, val);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Truy vấn tổng trên Cây Phân Đoạn
long long query(long long *tree, int node, int start, int end, int l, int r) {
    if (r < start || end < l || l > r) return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = start + (end - start) / 2;
    return query(tree, 2 * node, start, mid, l, r) + query(tree, 2 * node + 1, mid + 1, end, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Add the occurence of the current element
    // Check how many number greater/smaller than the current element
    // Multiply the left and right

    long long n; // The number of men in Roman army
    cin >> n;

    long long MAX_VALUE = 1000001;
    long long* saveRank = new long long[n + 1];

    for (int i = 1; i <= n; ++i) {
        long long val; cin >> val; // Input the power
        saveRank[i] = val * MAX_VALUE + i; // Save the position of the man in the army
    }
    sort(saveRank + 1, saveRank + n + 1); // Sort the 

    long long* indices = new long long[n + 1];
    for (int i = 1; i <= n; ++i) {
        int original_idx = saveRank[i] % MAX_VALUE; // saveRank[i] is in the form of qd + r. Therefore, we just need to modulo the max value
        indices[original_idx] = i;
    }
    delete[] saveRank;

    long long* tree = new long long[4 * n]();
    // The reason why choosing 4 * n is an optimal memory for tree
    // - Take n as the number of leaf nodes
    // - In the last level, the number of nodes is exactly equal to n.
    // - The number of internal nodes is n - 1
    // => The number of nodes cannot be greater than 2n (because n + n - 1 = 2n - 1)
    // However some n can break this statement.
    // To find the upper bound, take X is the exponent of base 2 (2^X), and X <= N.
    // - The maximum number of nodes is 2X - 1 (1)
    // - We get this proposition: X < 2n (2)
    // Substitute (2) to (1), we got the maximum number of nodes < 2(2N) - 1 = 4N - 1
    long long* R = new long long[n]();

    for (int i = n; i >= 1; --i) {
        R[i] = query(tree, 1, 1, n, 1, indices[i] - 1);
        update(tree, 1, 1, n, indices[i], 1);
    }

    for (int i = 0; i <= 4 * n; ++i) tree[i] = 0;
    long long total = 0;

    for (int i = 1; i <= n; ++i) {
        int left_greater = query(tree, 1, 1, n, indices[i] + 1, n);
        total += 1LL * left_greater * R[i];
        update(tree, 1, 1, n, indices[i], 1);
    }
    
    cout << total << "\n";

    delete[] indices;
    delete[] tree;
    delete[] R;
    return 0;
}