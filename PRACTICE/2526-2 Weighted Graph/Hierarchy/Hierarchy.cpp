#include <iostream>

using namespace std;

long long min_cost[1005];
int q[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
        min_cost[i] = -1;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (min_cost[b] == -1 || c < min_cost[b])
        {
            min_cost[b] = c;
        }
    }

    long long total = 0;
    int root_count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (min_cost[i] == -1)
        {
            root_count++;
        }
        else
        {
            total += min_cost[i];
        }
    }

    if (root_count > 1)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << total << "\n";
    }

    return 0;
}