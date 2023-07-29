#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

ll n;
ll h[N], sum[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        sum[i] = sum[i - 1] + h[i];
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (sum[i] < i * (i - 1) / 2)
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}