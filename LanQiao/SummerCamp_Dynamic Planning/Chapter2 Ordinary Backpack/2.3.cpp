#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, M = 1e2 + 10;

int f[N][M][M], v[N], m[N], w[N];
int n, V, P;

int main()
{
    cin >> n >> V >> P;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> m[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            for (int k = 0; k <= P; k++)
            {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= v[i] && k >= m[i])
                {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - v[i]][k - m[i]] + w[i]);
                }
            }
        }
    }
    cout << f[n][V][P];
}
