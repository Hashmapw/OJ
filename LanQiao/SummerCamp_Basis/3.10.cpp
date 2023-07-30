#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

string s;
ll pre[N];
ll x;
ll f[N];

int main()
{
    getline(cin, s);
    ll len = s.length();

    cin >> x;
    if (x == 0)
    {
        cout << len;
        return 0;
    }
    pre[0];
    for (int i = 0; i < len; i++)
    {
        pre[i + 1] = (pre[i] + s[i] - '0') % x; // 实现下标从0到下标到1的转换
    }
    ll maxlen = len * 9;
    for (int i = 1; i <= maxlen; i++)
        f[i] = N;
    int anslen = 0;
    for (int j = 1; j <= len; j++)
    {
        if (j - f[pre[j]] > anslen)
            anslen = j - f[pre[j]];
        if (f[pre[j]] == N)
            f[pre[j]] = j;
    }
    cout << anslen;
}