#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10, M = 10;
const ll Q = 1e9 + 7;

int n, m;
ll a[N], pre[N][M];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= 5; j++)
        {
            pre[i][j] = pre[i - 1][j] + pow(a[i], j);
        }
    }
    ll l, r, k, out;
    while (m--)
    {
        cin >> l >> r >> k;
        out = (pre[r][k] - pre[l - 1][k]) % Q;
        cout << out << endl;
    }
}