#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 3e5 + 10;

ll n;
ll s[N];
map<pll, int> m;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", &s[i]);
    }
    int x = 0, y = 0;
    ll sum = 0;
    m[{0, 0}] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 0)
            x++, y++;
        else if (s[i] == 1)
            x--;
        else if (s[i] == 2)
            y--;
        sum += m[{x, y}];
        m[{x, y}]++;
    }
    cout << sum;
}