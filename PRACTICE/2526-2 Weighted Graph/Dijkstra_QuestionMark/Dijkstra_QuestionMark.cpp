#include <iostream>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;
const int MAX_HEAP = 1000005;
const long long INF = 1e18;

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

long long heap_d[MAX_HEAP];
int heap_u[MAX_HEAP];
int heap_size = 0;

void push_heap(long long d, int u)
{
    heap_size++;
    int i = heap_size;
    while (i > 1 && d < heap_d[i / 2])
    {
        heap_d[i] = heap_d[i / 2];
        heap_u[i] = heap_u[i / 2];
        i /= 2;
    }
    heap_d[i] = d;
    heap_u[i] = u;
}

void pop_heap()
{
    if (heap_size == 0)
        return;
    long long last_d = heap_d[heap_size];
    int last_u = heap_u[heap_size];
    heap_size--;
    if (heap_size == 0)
        return;

    int i = 1;
    while (2 * i <= heap_size)
    {
        int j = 2 * i;
        if (j < heap_size && heap_d[j + 1] < heap_d[j])
            j++;
        if (last_d <= heap_d[j])
            break;

        heap_d[i] = heap_d[j];
        heap_u[i] = heap_u[j];
        i = j;
    }
    heap_d[i] = last_d;
    heap_u[i] = last_u;
}

long long dist[MAXN];
int trace[MAXN];
bool visited[MAXN];
int path[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    for (int i = 1; i <= n; ++i)
    {
        dist[i] = INF;
        trace[i] = -1;
        visited[i] = false;
    }

    dist[1] = 0;
    push_heap(0, 1);

    while (heap_size > 0)
    {
        long long d = heap_d[1];
        int u = heap_u[1];
        pop_heap();

        if (visited[u])
            continue;
        visited[u] = true;

        for (int i = head[u]; i != 0; i = nxt[i])
        {
            int v = to[i];
            long long w = weight[i];

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                trace[v] = u;
                push_heap(dist[v], v);
            }
        }
    }

    if (dist[n] == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        int current = n;
        int path_len = 0;
        while (current != -1)
        {
            path[++path_len] = current;
            current = trace[current];
        }
        for (int i = path_len; i >= 1; --i)
        {
            cout << path[i] << (i == 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}