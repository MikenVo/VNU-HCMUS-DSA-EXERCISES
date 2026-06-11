#include <iostream>

using namespace std;

struct Edge
{
    int u, v, w;
};

Edge edges[2000005];
int parent_node[1000005];

int find_set(int i)
{
    if (parent_node[i] == i)
        return i;
    return parent_node[i] = find_set(parent_node[i]);
}

void quick_sort(int left, int right)
{
    if (left >= right)
        return;
    int pivot = edges[left + (right - left) / 2].w;
    int i = left, j = right;

    while (i <= j)
    {
        while (edges[i].w < pivot)
            i++;
        while (edges[j].w > pivot)
            j--;
        if (i <= j)
        {
            Edge temp = edges[i];
            edges[i] = edges[j];
            edges[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort(left, j);
    quick_sort(i, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    for (int i = 1; i <= n; i++)
    {
        parent_node[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    quick_sort(0, m - 1);

    long long total_weight = 0;
    int edges_used = 0;

    for (int i = 0; i < m; i++)
    {
        int root_u = find_set(edges[i].u);
        int root_v = find_set(edges[i].v);

        if (root_u != root_v)
        {
            total_weight += edges[i].w;
            parent_node[root_u] = root_v;
            edges_used++;
            if (edges_used == n - 1)
                break;
        }
    }

    if (edges_used == n - 1)
    {
        cout << total_weight << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}