#include <iostream>

using namespace std;

const int MAXN = 100005;
const int MAXM = 400005; // 2 * 200,000 do là đồ thị vô hướng

// --- Cấu trúc Danh sách kề (Adjacency List) ---
int head[MAXN], to[MAXM], nxt[MAXM];
long long weight[MAXM];
int edge_cnt = 0;

void add_edge(int u, int v, long long w)
{
    to[++edge_cnt] = v;
    weight[edge_cnt] = w;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt;
}

// --- Cấu trúc Min Heap ---
// Tách 2 mảng thay vì dùng struct để tối ưu padding memory (giữ < 16MB)
long long heap_w[MAXM];
int heap_u[MAXM];
int heap_size = 0;

void push_heap(long long w, int u)
{
    heap_size++;
    int i = heap_size;
    // Sift-up: Nổi phần tử lên nếu nó nhỏ hơn nút cha
    while (i > 1 && w < heap_w[i / 2])
    {
        heap_w[i] = heap_w[i / 2];
        heap_u[i] = heap_u[i / 2];
        i /= 2;
    }
    heap_w[i] = w;
    heap_u[i] = u;
}

void pop_heap()
{
    if (heap_size == 0)
        return;
    long long last_w = heap_w[heap_size];
    int last_u = heap_u[heap_size];
    heap_size--;
    if (heap_size == 0)
        return;

    int i = 1;
    // Sift-down: Chìm phần tử xuống vị trí hợp lý
    while (2 * i <= heap_size)
    {
        int j = 2 * i;
        if (j < heap_size && heap_w[j + 1] < heap_w[j])
            j++;
        if (last_w <= heap_w[j])
            break;

        heap_w[i] = heap_w[j];
        heap_u[i] = heap_u[j];
        i = j;
    }
    heap_w[i] = last_w;
    heap_u[i] = last_u;
}

// --- Thuật toán chính ---
bool inMST[MAXN];

int main()
{
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    if (!(cin >> n >> m >> s))
        return 0;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    // Bắt đầu Prim từ đỉnh s
    push_heap(0, s);

    long long total_weight = 0;
    int nodes_connected = 0;

    while (heap_size > 0 && nodes_connected < n)
    {
        long long w = heap_w[1];
        int u = heap_u[1];
        pop_heap();

        if (inMST[u])
            continue; // Bỏ qua nếu đỉnh đã có trong mạng lưới

        inMST[u] = true;
        total_weight += w;
        nodes_connected++;

        // Quét các đỉnh kề
        for (int i = head[u]; i != 0; i = nxt[i])
        {
            int v = to[i];
            if (!inMST[v])
            {
                push_heap(weight[i], v);
            }
        }
    }

    if (nodes_connected == n)
    {
        cout << total_weight << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}