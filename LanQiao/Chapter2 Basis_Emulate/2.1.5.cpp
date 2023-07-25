#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a, b, n, week = 1, now = 0, dayCnt = 0;
    long long int weeks, ans;
    cin >> a >> b >> n;
    weeks = n / (5 * a + 2 * b);
    now += weeks * (5 * a + 2 * b);
    dayCnt += weeks * 7;
    while (now < n)
    { // 注意边界条件 now表示当前已刷题数
        if (week <= 5)
            now = now + a;
        else
            now = now + b;
        week++;
        dayCnt++;
        if (week > 7)
            week = week % 7;
    }
    cout << dayCnt;
}