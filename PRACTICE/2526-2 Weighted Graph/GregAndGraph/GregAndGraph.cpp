#include <iostream>

using namespace std;

long long dist[505][505];
int del_order[505];
long long ans[505];
bool active[505];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> dist[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> del_order[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        active[i] = false;
    }

    for (int step = n; step >= 1; --step)
    {
        int k = del_order[step];
        active[k] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        long long current_sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (active[i] && active[j])
                {
                    current_sum += dist[i][j];
                }
            }
        }
        ans[step] = current_sum;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}