// 2.1.1 成绩统计
#include <bits/stdc++.h>
using namespace std;

long long int n, x, cnt1 = 0, cnt2 = 0;
double per1, per2;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x >= 60)
            cnt1++;
        if (x >= 85)
            cnt2++;
    }
    per1 = 1.0 * cnt1 / n * 100;
    per2 = 1.0 * cnt2 / n * 100;
    cout << setprecision(0) << fixed << per1 << "%" << endl;
    cout << setprecision(0) << fixed << per2 << "%";
}