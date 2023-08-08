#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e7 + 10;
ll n, m, A;
ll a[N], q[N], maxe[N], now[N], ans[N];

void insert(ll i)
{
    memset(now, 0, sizeof(now));
    for (int j = 0; j < i; j++)
    {
        now[j] = a[j];
    }
    now[i] = A;
    for (int j = i + 1; j <= n; j++)
    {
        now[j] = a[j - 1];
    }
}

int main()
{
    cin >> n >> m >> A;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sumn = 0, scnt = 0, allmax;
    for (int j = 0; j < n; j++)
    {
        memset(maxe, 0, sizeof(maxe));
        sumn = 0;
        insert(j);
        ll hh = 0, tt = -1, cnt = 0;
        for (int i = 0; i <= n; i++)
        {
            while (hh <= tt && i - m + 1 > q[hh])
                hh++;
            while (hh <= tt && now[q[tt]] <= now[i])
                tt--;
            q[++tt] = i;
            if (i >= m - 1)
                sumn += now[q[hh]];
            // maxe[cnt++] = now[q[hh]];
        }
        ans[scnt++] = sumn;
    }
    allmax = *max_element(ans, ans + scnt);
    cout << allmax;
}