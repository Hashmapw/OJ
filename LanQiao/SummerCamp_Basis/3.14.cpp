#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
ll n, t, q, x;
ll l, r;
ll diff[N], pren[N];

void insert(ll l, ll r, ll c)
{
    diff[l] += c;
    diff[r + 1] -= c;
}

int main()
{
    cin >> n >> t >> q >> x;
    memset(diff, 0, sizeof(diff));
    memset(pren, 0, sizeof(pren));
    while (t--)
    {
        cin >> l >> r;
        insert(l, r, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (diff[i] >= x)
            pren[i] = pren[i - 1] + 1;
        else
            pren[i] = pren[i - 1];
    }
    while (q--)
    {
        cin >> l >> r;
        cout << pren[r] - pren[l - 1] << endl;
    }
}