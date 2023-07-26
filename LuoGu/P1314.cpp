#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e6 + 10;

ll n, m, nowabs;
ll maxw, minw;
ll s;
ll w[N], v[N], preva[N], pren[N];
ll l[N], r[N];

bool check(int limit)
{
    ll nowr, nowl, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (w[i] >= limit)
        {
            pren[i] = pren[i - 1] + 1;
            preva[i] = preva[i - 1] + v[i];
        }
        else
        {
            pren[i] = pren[i - 1];
            preva[i] = preva[i - 1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        nowl = l[i], nowr = r[i];
        sum += (pren[nowr] - pren[nowl - 1]) * (preva[nowr] - preva[nowl - 1]);
    }
    nowabs = llabs(sum - s);
    if (sum <= s)
        return true;
    else
        return false;
}

int main()
{
    ll answer = 0x3f3f3f3f3f3f;
    scanf("%ld%ld%ld", &n, &m, &s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%ld %ld", &w[i], &v[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%ld %ld", &l[i], &r[i]);
    }
    maxw = *max_element(w + 1, w + n + 1);
    minw = *min_element(w + 1, w + n + 1);
    ll l = minw - 1, r = maxw + 2;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
        if (nowabs < answer)
            answer = nowabs;
    }
    cout << answer;
}