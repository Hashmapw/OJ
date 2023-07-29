#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, num[N], pre[N], suf[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i] = __gcd(pre[i - 1], num[i]);
        suf[n - i + 1] = __gcd(suf[n - i + 2], num[n - i + 2]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, __gcd(pre[i - 1], suf[i + 1]));
    }
    cout << ans;
}