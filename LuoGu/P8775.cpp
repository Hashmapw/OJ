#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, x;
int height[N], sumHeight[N];

bool check(int mid)
{
    for (int l = 1; l <= n - mid; l++)
    {
        int r = l + mid - 1;
        if (sumHeight[r] - sumHeight[l - 1] < 2 * x)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> x;
    memset(height, 0, sizeof(height));
    memset(sumHeight, 0, sizeof(sumHeight));
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> height[i];
        sumHeight[i] = sumHeight[i - 1] + height[i];
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid ;
        else
            l = mid + 1;
    }
    cout << r;
}
