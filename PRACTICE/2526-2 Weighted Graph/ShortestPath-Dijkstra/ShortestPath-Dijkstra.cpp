#include <iostream>

using namespace std;

// Maximum expected constraints for Competitive Programming
const int MAXN = 100005;    // Max Waypoints
const int MAXM = 500005;    // Max Flight Paths (generous allocation)
const long long INF = 1e18; // Use long long to prevent distance overflow

// --- 1. MEMORY-EFFICIENT GRAPH (FORWARD STAR) ---
struct Edge
{
    int to, weight, next;
};
Edge edges[MAXM];
int head[MAXN];
int edgeCount = 0;

void addEdge(int u, int v, int w)
{
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;
}

// --- 2. CUSTOM MIN-HEAP (PRIORITY QUEUE) ---
struct Waypoint
{
    long long cost;
    int id;
};

class MinHeap
{
private:
    Waypoint heap[MAXM]; // Sized to handle maximum possible path calculations
    int size = 0;

    void swap(Waypoint &a, Waypoint &b)
    {
        Waypoint temp = a;
        a = b;
        b = temp;
    }

public:
    bool isEmpty() { return size == 0; }
    Waypoint top() { return heap[0]; }

    void push(long long cost, int id)
    {
        heap[size] = {cost, id};
        int curr = size++;
        while (curr > 0 && heap[curr].cost < heap[(curr - 1) / 2].cost)
        {
            swap(heap[curr], heap[(curr - 1) / 2]);
            curr = (curr - 1) / 2;
        }
    }

    void pop()
    {
        if (size <= 0)
            return;
        heap[0] = heap[--size];
        int curr = 0;

        while (true)
        {
            int left = 2 * curr + 1;
            int right = 2 * curr + 2;
            int smallest = curr;

            if (left < size && heap[left].cost < heap[smallest].cost)
                smallest = left;
            if (right < size && heap[right].cost < heap[smallest].cost)
                smallest = right;
            if (smallest == curr)
                break;

            swap(heap[curr], heap[smallest]);
            curr = smallest;
        }
    }
};

// Global distance array
long long dist[MAXN];

int main()
{
    // Fast I/O: Essential for passing the 1-second time limit with large datasets
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    if (!(cin >> n >> m >> s))
        return 0;

    // Initialize all starting points to -1 (empty)
    for (int i = 0; i <= n; i++)
        head[i] = -1;

    // Read all input maneuvers
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    // Initialize all distances to Infinity
    for (int i = 0; i <= n; i++)
        dist[i] = INF;

    // Begin Dijkstra sequence from the source
    dist[s] = 0;
    MinHeap pq;
    pq.push(0, s);

    while (!pq.isEmpty())
    {
        long long d = pq.top().cost;
        int u = pq.top().id;
        pq.pop();

        // Skip stale data if a faster route was already found
        if (d > dist[u])
            continue;

        // Traverse all outgoing paths from the current node
        for (int i = head[u]; i != -1; i = edges[i].next)
        {
            int v = edges[i].to;
            int w = edges[i].weight;

            // Relax the edge if a cheaper fuel path is found
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(dist[v], v);
            }
        }
    }

    // Output formatting precisely as requested
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
        {
            cout << -1 << " "; // Print -1 if unreachable
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}