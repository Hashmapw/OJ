// 2.1.3 九进制转十进制
#include <bits/stdc++.h>
using namespace std;

string s;
long long int ans = 0;

int main()
{
    cin >> s;
    for (char i : s)
    {
        ans = ans * 9 + i - '0';
    }
    cout << ans << endl;
}