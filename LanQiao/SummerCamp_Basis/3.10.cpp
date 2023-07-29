#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

string s;
ll pre[N];
ll x;

int main()
{
    getline(cin, s);
    ll len = s.length();

    cin >> x;
    if (x == 0)
    {
        cout << len;
        return 0;
    }
    pre[0];
    for (int i = 0; i < len; i++)
    {
        pre[i + 1] = pre[i] + s[i] - '0'; // 实现下标从0到下标到1的转换
    }
    ll now = 0, maxlen = 0, nowlen = 0;
    bool flag = false;
    for (int i = 1; i <= len - 1; i++)
    {
        for (int j = i + 1; j <= len; j++)
        {
            now = pre[j] - pre[i - 1];
            nowlen = j - i + 1;
            if (nowlen > maxlen && now % x == 0)
            {
                flag = true;
                maxlen = nowlen;
            }
        }
    }
    if (flag)
        cout << maxlen;
    else
        cout << "0";
}