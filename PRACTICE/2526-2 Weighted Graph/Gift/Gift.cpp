#include <iostream>

using namespace std;

struct Edge
{
    int u, v;
    long long g, s;
};

Edge all_edges[50005];
Edge active_edges[50005];
Edge tmp[50005];
int parent[205];
int n, m;
long long G_price, S_price;

void merge(int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (all_edges[i].g <= all_edges[j].g)
            tmp[k++] = all_edges[i++];
        else
            tmp[k++] = all_edges[j++];
    }
    while (i <= mid)
        tmp[k++] = all_edges[i++];
    while (j <= right)
        tmp[k++] = all_edges[j++];
    for (i = left; i <= right; i++)
        all_edges[i] = tmp[i];
}

void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m))
        return 0;
    cin >> G_price >> S_price;

    for (int i = 0; i < m; i++)
    {
        cin >> all_edges[i].u >> all_edges[i].v >> all_edges[i].g >> all_edges[i].s;
    }

    merge_sort(0, m - 1);

    int active_cnt = 0;
    long long min_total = -1;

    for (int i = 0; i < m; i++)
    {
        Edge curr = all_edges[i];
        int pos = active_cnt;
        while (pos > 0 && active_edges[pos - 1].s > curr.s)
        {
            active_edges[pos] = active_edges[pos - 1];
            pos--;
        }
        active_edges[pos] = curr;
        active_cnt++;

        for (int j = 1; j <= n; j++)
            parent[j] = j;

        int new_active_cnt = 0;
        int components = n;
        long long max_s_step = 0;

        for (int j = 0; j < active_cnt; j++)
        {
            int root_u = find_set(active_edges[j].u);
            int root_v = find_set(active_edges[j].v);

            if (root_u != root_v)
            {
                parent[root_u] = root_v;
                active_edges[new_active_cnt++] = active_edges[j];
                components--;
                max_s_step = active_edges[j].s;
            }
        }
        active_cnt = new_active_cnt;

        if (components == 1)
        {
            long long current_cost = curr.g * G_price + max_s_step * S_price;
            if (min_total == -1 || current_cost < min_total)
            {
                min_total = current_cost;
            }
        }
    }

    cout << min_total << "\n";

    return 0;
}