#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
ll n, k;
ll l, d;
ll diff[N], pre[N];

void insert(int l, int r, int c)
{
    diff[l] += c;
    diff[r + 1] -= c;
}

int main()
{
    cin >> n >> k;
    ll maxtime = 0;
    while (n--)
    {
        cin >> l >> d;
        insert(l, l + d - 1, 1);
        maxtime = max(l + d - 1, maxtime);
    }
    ll sum = 0;
    for (int i = 1; i <= maxtime; i++)
        diff[i] += diff[i - 1];
    ll maxsugar = 0, ans = 0;
    for (int i = 1; i <= maxtime; i++)
    {
        pre[i] = pre[i - 1] + diff[i];
    }
    k = min(k, maxtime); // 特殊处理：特制胶囊持续时间大于吃糖时间，防止数组越界。
    for (int i = k; i <= maxtime; i++)
    {
        ans = pre[i] - pre[i - k];
        maxsugar = max(ans, maxsugar);
    }
    cout << maxsugar;
}