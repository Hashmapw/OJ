#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int f[N][N], w[N], v[N];
int n, V;

int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= w[i])
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << f[n][V];
}