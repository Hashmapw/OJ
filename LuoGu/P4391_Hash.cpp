#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 10000010, P = 13331;

ll n;
char str[N];
ull h[N], p[N];

ull get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    cin >> n;
    cin >> str + 1;

    p[0] = 1;
    for (ull i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    for (ull i = 1; i <= n; i++)
    {
        bool flag = true;
        ull now = get(1, i);
        for (int j = 1; (j + 1) * i <= n; j++)
        {
            if (get(j * i + 1, (j + 1) * i) != now)
            {
                flag = false;
                break;
            }
        }
        if (n * i != 0)   //处理不是整段复制的
        {
            ull len = n % i;
            if (get(1, len) != get(n - len + 1, n))
                flag = false;
        }
        if (flag)
        {
            cout<<i;
            return 0;
        }
    }
}