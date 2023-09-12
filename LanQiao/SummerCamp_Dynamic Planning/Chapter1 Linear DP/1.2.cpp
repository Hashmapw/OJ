#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 3e5 + 10;

ll n;
ll a[N], f[N];

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 0x3f3f3f3f, sizeof f);

    ll len = 0;
    f[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] > f[len])
        {
            f[++len] = a[i];
            continue;
        }

        ll l = 1, r = len, mid, pos;

        while (l <= r)
        {
            mid = l + r >> 1;
            if (f[mid] >= a[i])
                pos = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        f[pos] = a[i];
    }
    cout << len;
}
