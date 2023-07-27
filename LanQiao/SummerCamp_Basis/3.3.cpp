#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e2 + 10;

ll n;
ll a[N], pre[N];
map<int, int> m;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    pre[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i] - 1;
    }
    ll sum = 0, temp;
    for (int i = 0; i <= n; i++)    //请注意这里从0开始
    {
        sum += m[pre[i]];
        m[pre[i]]++;
    }
    cout << sum;
}