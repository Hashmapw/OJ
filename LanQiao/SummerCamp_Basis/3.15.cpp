#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e2 + 10;
ll n, k;
ll l, d;
ll diff[N];

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
    k = max(k, maxtime); // 特殊处理：特制胶囊持续时间大于吃糖时间
    // 特殊处理：如果此处不进行处理，diff[maxtime++]处存在脏数据
    for (int i = 1; i <= k; i++)
    {
        ans += diff[i];
    }
    maxsugar = max(maxsugar, ans);
    for (int i = k + 1; i <= maxtime; i++)
    {
        ans += diff[i] - diff[i - k];
        maxsugar = max(maxsugar, ans);
    }
    cout << maxsugar;
}