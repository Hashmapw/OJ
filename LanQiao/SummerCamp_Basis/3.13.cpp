#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10, M = 32; // int类型4字节 32位
ll n, q;
int a[N], pre[M][N];

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int bit = 0; bit < M; bit++)
    {
        for (int i = 1; i <= n; i++)
        {
            pre[bit][i] = pre[bit][i - 1] + (a[i] >> bit & 1);
        }
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        int ans = 0;
        for (int bit = 0; bit < M; bit++)
        {
            if (pre[bit][r] - pre[bit][l - 1])
                ans |= 1 << bit;
        }
        cout << ans << endl;
    }
}