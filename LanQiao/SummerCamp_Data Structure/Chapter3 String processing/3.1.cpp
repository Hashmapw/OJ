#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e6 + 10, P = 13131, Q = 233;

int n;
char str[N];
ULL h1[N], p1[N];
ULL h2[N], p2[N];

ULL get1(int l, int r)
{
    return h1[r] - h1[l - 1] * p1[r - l + 1];
}

ULL get2(int l, int r)
{
    return h2[r] - h2[l - 1] * p2[r - l + 1];
}

bool check(int x)
{
    unordered_map<ULL,int> data1, data2;
    for (int i = 1; i <= n - x; i++)
    {
        ULL nowa = get1(i, i + x), nowb = get2(i, i + x);
        if (data1.find(nowa) == data1.end() && data2.find(nowb) == data2.end())
        {
            data1[nowa] = i;
            data2[nowb] = i;
        }
        else
        {
            if (data1[nowa] + x >= i && data2[nowb] + x >= i)
                continue;
            else
                return true;
        }
    }
    return false;
}

int main()
{
    memset(str, '\0', sizeof str);
    scanf("%s", str + 1);

    for (int i = 1; str[i] != '\0'; i++)
    {
        n++;
    }

    p1[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p1[i] = p1[i - 1] * P;
        h1[i] = h1[i - 1] * P + str[i];
    }

    p2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p2[i] = p2[i - 1] * Q;
        h2[i] = h2[i - 1] * Q + str[i];
    }

    int l = 1, r = n, mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (!check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r;
}