#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef unsigned long long ULL;

const int N = 1e6 + 10, P = 13131;
int n;
char str[N];
ULL h[N], p[N];
unordered_set<ULL> all;

ULL get(int l, int r)
{
    return (h[r] - h[l - 1] * p[r - l + 1]) * p[l - 1] + h[l - 1];
}

signed main()
{
    cin >> n;
    scanf("%s", str + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    for (int i = 0; i <= n; i++)
    {
        ULL temp = get(i+1, n);
        all.insert(temp);
    }
    cout << all.size();
}
