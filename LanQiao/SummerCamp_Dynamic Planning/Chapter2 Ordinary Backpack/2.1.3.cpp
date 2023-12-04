#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int f[N], w[N], v[N];
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
        for (int j = V; j >= 0; j--)
        {
            if (j >= w[i])
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[V];
}