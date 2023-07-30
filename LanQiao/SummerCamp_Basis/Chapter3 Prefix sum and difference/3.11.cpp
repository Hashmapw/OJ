#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e6 + 10;

ll n;
ll a[N], diff[N];

int main()
{
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (diff[i] > 0)
            ans += diff[i];
    }
    cout << ans -1 ;
}