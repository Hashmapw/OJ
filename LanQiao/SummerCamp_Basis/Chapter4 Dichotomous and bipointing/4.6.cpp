#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll n, L, R;
ll a[N];

ll calc(int v)
{
    int l = 1, r = n;
    ll ans = 0;
    while (l < r)
    {
        while (l < r && a[l] + a[r] > v)
        {
            r--;
        }
        ans += r - l;
        l++;
    }
    return ans;
}

int main()
{
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cout << calc(R) - calc(L - 1) << endl;
}