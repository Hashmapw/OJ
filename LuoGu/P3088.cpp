#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 1e6 + 10;
ll n, d;
pll cow[N];
ll q[N];
bool l[N], r[N];

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> cow[i].first >> cow[i].second;
    }
    sort(cow, cow + n);
    ll hh = 0, tt = -1;
    memset(q, -1, sizeof(q));
    for (ll i = 0; i < n; i++)
    {
        while (hh <= tt && cow[q[hh]].first + d < cow[i].first)
            hh++;
        while (hh <= tt && cow[q[tt]].second <= cow[i].second)
            tt--;
        if (cow[q[hh]].second >= cow[i].second * 2)
            r[i] = true;
        q[++tt] = i;
    }
    hh = 0, tt = -1;
    memset(q, -1, sizeof(q));
    for (ll i = n - 1; i >= 0; i--)
    {
        while (hh <= tt && cow[i].first + d < cow[q[hh]].first)
            hh++;
        while (hh <= tt && cow[q[tt]].second <= cow[i].second)
            tt--;
        if (cow[q[hh]].second >= cow[i].second * 2)
            l[i] = true;
        q[++tt] = i;
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (r[i] && l[i])
            cnt++;
    }
    cout << cnt;
}