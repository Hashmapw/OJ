// 2.1.2 成绩分析
#include <bits/stdc++.h>
using namespace std;

long long int n, x, Max = 0, Min = 100, Sum = 0;
double av;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > Max)
            Max = x;
        if (x < Min)
            Min = x;
        Sum += x;
    }
    av = 1.0 * Sum / n;
    cout << Max << endl
         << Min << endl;
    // cout<<setprecision(2)<<fixed<<av;
    printf("%.2lf", av);
}
