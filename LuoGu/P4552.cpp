#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e2 + 10;
ll n;
ll a[N], diff[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll posnum=0, unposnum=0;
    for (int i = 2; i <= n; i++)
    {
        diff[i] = a[i] - a[i - 1];
        if (diff[i] > 0)
            posnum += diff[i];
        else if (diff[i] < 0)
            unposnum -= diff[i];
    }
    cout << max(posnum, unposnum) << endl;
    cout << abs(posnum - unposnum) + 1;
}