#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7, base = 32107;
const int N = 1e5 + 10;
ll n, m, k, pos;
ll pw[N], ml[N], mr[N];
char s[N], t[N];

struct Hash
{
    ll a[N];
    void JS(char *s)
    {
        ll len = strlen(s + 1);
        for (ll i = 1; i <= len; ++i)
            a[i] = (a[i - 1] * base % MOD + s[i] - 'a') % MOD;
    }
    ll Get(int l, int r)
    {
        --l;
        if (l >= 0)
            return (a[r] - a[l] * pw[r - l] % MOD + MOD) % MOD;
        else
            return a[r];
    }
} S, T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    cin >> s + 1;
    cin >> t + 1;
    pw[0] = 1;
    for (ll i = 1; i <= n; ++i)
        pw[i] = pw[i - 1] * base % MOD;
    S.JS(s), T.JS(t);
    pos = k;
    for (ll i = 1; i <= m; ++i)
        ml[i] = n + 1;
    for (ll i = 1; i <= min(m, k); ++i)
    {
        while (pos <= n && S.Get(pos - i + 1, pos) != T.Get(1, i))
            ++pos;
        if (S.Get(k - i + 1, k) == T.Get(1, i))
            pos = k;
        ml[i] = pos;
    }
    pos = n - k + 1;
    for (ll i = 1; i <= min(m, k); ++i)
    {
        while (pos && S.Get(pos, pos + i - 1) != T.Get(m - i + 1, m))
            --pos;
        if (S.Get(n - k + 1, n - k + i) == T.Get(m - i + 1, m))
            pos = n - k + 1;
        mr[m - i + 1] = pos;
    }
    for(int i=0;i<n;i++){
        cout<<ml[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<mr[i]<<" ";
    }
    cout<<endl;
    for (ll i = 1; i < m; ++i)
        if (ml[i] < mr[i + 1] && ml[i] < n + 1 && mr[i + 1])
        {
            cout << ml[i] << " " << mr[i + 1] << " " << i << endl;
            cout << "Yes1\n";
            return 0;
        }
    for (ll i = 1; i <= n - m + 1; ++i)
        if (S.Get(i, i + m - 1) == T.Get(1, m))
        {
            cout << "Yes2\n";
            return 0;
        }
    cout << "No\n";
    return 0;
}