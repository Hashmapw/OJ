#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e7+10;
ll k,n,m;
ll a[N];

bool check(ll v)
{
    ll cnt=0,pre=a[0];
    for(ll i=0;i<=n;i++){
        if((a[i+1]-pre)>=v && (k-a[i+1])>=v){
            cnt++;
            pre=a[i+1];
        }
    }
    return cnt>=m && k-pre>=v;
}


int main()
{
    scanf("%lld %lld %lld",&k,&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    a[0]=0;a[n+1]=k;
    //sort(a,a+n+1);
    ll l=0,r=k;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(mid))  l=mid;
        else            r=mid-1;
    }
    cout<<l;
}