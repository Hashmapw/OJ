#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int f[2][N], w[N], v[N];
int n, V;

int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    int idx = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            f[idx][j] = f[!idx][j];
            if (j >= w[i])
                f[idx][j] = max(f[i][j], f[!idx][j - w[i]] + v[i]);
        }
        idx = !idx;
    }
    cout << f[!idx][V];
}