#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const int N=1e8+10;

ll p[N];
ll n,m;
ll s,e;
string type;
vector<pll> odd;
vector<pll> even;
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

int main()
{
    cin>>n;
    cin>>m;
    while(m--)
    {
        cin>>l>>r>>type;
        if(type=="even")  even.push_back({l,r});
        else(type=="odd")  odd.push_back({l,r});
        num.push_back(l);
        num.push_back(r);
    }
}