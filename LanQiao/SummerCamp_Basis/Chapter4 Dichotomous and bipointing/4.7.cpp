#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e2+10;
ll n,k,m;
ll a[N],pre[N];
vector<ll> b;

bool check(int v)
{
    ll cnt=0;
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++){
        if(a[i]>=v)  pre[i]=pre[i-1]+1;
        else         pre[i]=pre[i-1];
    }
    for(int i=1;i<=n;i++){
        ll res=lower_bound(pre+1,pre+n+1,pre[i-1]+k)-pre;
        cnt+=n-res+1;
    }
    return cnt>=m;
}

int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll l=*min_element(a+1,a+n+1);
    ll r=*max_element(a+1,a+n+1);
    //枚举左端点，二分找右端点
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(mid))  l=mid;
        else            r=mid-1;
    }
    cout<<l<<endl;
}