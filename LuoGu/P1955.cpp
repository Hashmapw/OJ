#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<pair<ll, ll>, ll> pll;
const ll N = 5e6 + 10;

ll t;
ll n;
ll p[N];
ll i, j, e;
vector<pll> pro;
vector<ll> num;

ll find(ll x) // 返回x所在集合的编号   //返回x的祖宗节点+路径压缩
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

// 二分求出x对应的离散化的值
ll fbin(int x) // 找到第一个大于等于x的位置
{
    ll l = 0, r = num.size() - 1;
    while (l < r)
    {
        ll mid = l + r >> 1;
        if (num[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}

bool cmp(pll a, pll b) // 降序排序
{
    return a.second > b.second;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        pro.clear();
        cin >> n;
        while (n--)
        {
            cin >> i >> j >> e;
            pro.push_back({{i, j}, e});
            num.push_back(i);
            num.push_back(j);
        }
        sort(pro.begin(), pro.end(), cmp);
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        ll len = num.end() - num.begin();
        bool flag = true;
        for (int i = 1; i <= len; i++)
            p[i] = i;
        for (auto &x : pro)
        {
            ll fir = find(fbin(x.first.first)), sec = find(fbin(x.first.second));
            if (x.second == 1)
            {
                if (fir != sec)
                    p[fir] = sec;
            }
            else
            {
                if (fir == sec)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}