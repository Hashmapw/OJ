#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long ll;
const ll N = 1e6 + 10, P = 13131;
// const ll TN = 1e2 + 10;

ll n, m, k;
ll pos;
ll pre[N], suf[N];
char s[N], t[N];
ULL h1[N], p1[N];
ULL h2[N], p2[N];

ULL get1(ll l, ll r)
{
    return h1[r] - h1[l - 1] * p1[r - l + 1];
}

ULL get2(ll l, ll r)
{
    return h2[r] - h2[l - 1] * p2[r - l + 1];
}

int main()
{
    cin >> n >> m >> k;
    scanf("%s", s + 1);
    p1[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        p1[i] = p1[i - 1] * P;
        h1[i] = h1[i - 1] * P + s[i];
    }
    scanf("%s", t + 1);
    p2[0] = 1;
    for (ll i = 1; i <= m; i++)
    {
        p2[i] = p2[i - 1] * P;
        h2[i] = h2[i - 1] * P + t[i];
    }

    for (int i = 0; i <= n; i++)
    {
        pre[i] = n + 1;
        suf[i] = 0;
    }

    pos = k;
    for (ll i = 1; i <= min(m, k); ++i)
    {
        while (pos <= n && get1(pos - i + 1, pos) != get2(1, i))
            ++pos;
        if (get1(k - i + 1, k) == get2(1, i))
            pos = k;
        pre[i] = pos;
    }

    pos = n - k + 1;
    for (ll i = 1; i <= min(m, k); ++i)
    {
        while (pos >= 1 && get1(pos, pos + i - 1) != get2(m - i + 1, m))
            --pos;
        if (get1(n - k + 1, n - k + i) == get2(m - i + 1, m))
            pos = n - k + 1;
        suf[m - i + 1] = pos;
    }

    /*
    for (int i = 0; i < n; i++)
    {
        cout << pre[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << suf[i] << " ";
    }
    cout << endl;
    */

    for (ll i = 1; i < m; ++i)
    {
        if (pre[i] < suf[i + 1] && pre[i] < n + 1 && suf[i + 1] > 0)
        {
            // cout << i << ":" << pre[i] << " " << suf[i + 1] << endl;
            cout << "Yes" << endl;
            return 0;
        }
    }
    for (ll i = 1; i <= n - m + 1; ++i)
    {
        if (get1(i, i + m - 1) == get2(1, m))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}