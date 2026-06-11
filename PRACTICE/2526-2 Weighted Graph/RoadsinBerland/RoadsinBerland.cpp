#include <iostream>

using namespace std;

long long d[305][305];

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
            cin >> d[i][j];
        }
    }

    int k;
    cin >> k;

    for (int step = 0; step < k; ++step)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        if (w < d[u][v])
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    long long path1 = d[i][u] + w + d[v][j];
                    long long path2 = d[i][v] + w + d[u][j];

                    if (path1 < d[i][j])
                        d[i][j] = path1;
                    if (path2 < d[i][j])
                        d[i][j] = path2;
                }
            }
        }

        long long total_sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                total_sum += d[i][j];
            }
        }

        cout << total_sum << (step == k - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}