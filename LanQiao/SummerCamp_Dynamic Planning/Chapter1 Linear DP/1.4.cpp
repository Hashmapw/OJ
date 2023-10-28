#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 60, M = 3000, MOD = 1e9 + 7;

int n, m, k;
int dp[N][M];

signed main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i <= k ; i ++) dp[0][i] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int l = i; l <= k; l++)
            {
                dp[i + 1][j + l] += dp[i][l] % MOD;
                dp[i + 1][j + l] %= MOD;
            }
        }
    }
    cout << dp[n][k];
}