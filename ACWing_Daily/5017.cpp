#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
ll n,m,k;
ll t[N],c[N];

bool check(ll x)
{
    if(x<k)  return false;
    ll need=0;
    for(int i=0;i<n;i++){
        if(t[i]>x) need+=c[i]*(t[i]-x);
    }
    if(need<m)  return true;
    else         return false;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)  cin>>t[i]>>c[i];
    ll l=0,r=*max_element(t,t+n);
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid))   r=mid;
        else             l=mid+1;
    }
    cout<<r;
}