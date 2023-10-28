#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2000 + 10, MOD = 1e9 + 7;

int n, k;
int f[N][N];
vector<int> e[N];

int main()
{
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= k; j += i)
        {
            e[j].push_back(i); // j的倍数是i
        }
    }
    for (int i = 1; i <= k; i++)
        f[1][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int  p : e[j])
            {
                f[i][j] = (f[i][j] + f[i - 1][p]) % MOD;
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += f[n][i] % MOD; // 长度为n,第n个数为i
        ans %= MOD;
    }
    cout << ans << endl;
}