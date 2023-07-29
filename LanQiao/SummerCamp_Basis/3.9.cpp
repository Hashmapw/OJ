#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

ll n, k;
ll a[N], pre[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = 0x3f3f3f3f3f3f3f3f3f, now = 0;
    for (int i = 0; i <= k; i++)
    {
        now = (pre[n] - pre[n - (k - i)]) + (pre[i * 2] - pre[0]);
        if (now < ans)
            ans = now;
    }
    cout << ans << endl;
}
