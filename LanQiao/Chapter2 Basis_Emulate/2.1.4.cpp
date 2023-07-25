#include <bits/stdc++.h>
using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int yy = 2000, mm = 1, dd = 1, week = 6;
    int ans = 0;
    bool flag = false;
    for (; yy <= 2020; ++yy)
    {
        if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
        { // 错误点1：逻辑与写成逻辑非
            days[2] = 29;
        }
        else
        {
            days[2] = 28; // 错误点2：下标敲错
        }

        for (mm = 1; mm <= 12; ++mm)
        {
            for (dd = 1; dd <= days[mm]; ++dd)
            {
                if (dd == 1 || week == 1)
                {
                    ans += 2;
                }
                else
                {
                    ans += 1;
                }
                ++week;
                if (week == 8)
                    week = week % 7;
                if (yy == 2020 && mm == 10 && dd == 1)
                {
                    flag = true;
                    break;
                }
            }
            if (flag == true)
                break;
        }
        if (flag == true)
            break;
    }
    cout << ans << endl;
}