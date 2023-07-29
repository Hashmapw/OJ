#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;

typedef long long ll;
ll n, q;
ll l, r;
ll pre[N];
bool sushu[N];

bool isprime(ll x)
{
    if (x < 2)
        return false;
    if (x == 2 || x == 3)
        return true;
    for (int i = 2; i <= sqrt(x) + 1; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    memset(sushu, false, sizeof(sushu));
    for (int i = 1; i <= n; i++)
    {
        if (isprime(i))
            sushu[i] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (sushu[i / 2]==true && sushu[i]==true)
        {
            pre[i] = pre[i - 1] + 1;
        }
        else
        {
            pre[i] = pre[i - 1];
        }
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
}