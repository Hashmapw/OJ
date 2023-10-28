#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10, M = 1e4 + 10;

int n;
int t[N];
bool f[N][M];

int main()
{
    int s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        s += t[i];
    }
    f[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            f[i][j] = f[i - 1][j];
            if (t[i] <= j)
                f[i][j] |= f[i - 1][j - t[i]];
        }
    }
    int ans = s;
    for (int i = 0; i <= s; i++)
    {
        if (f[n][i])
        {
            ans = min(ans, max(i, s - i));
        }
    }
    cout << ans;
}