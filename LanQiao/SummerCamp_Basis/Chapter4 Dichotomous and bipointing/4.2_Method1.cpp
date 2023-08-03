//使用二分
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
ll n,s;
ll a[N],pre[N];

int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll l=1,r=n-1;
        while(l<=r){
            ll m=(l+r)/2;
            if((pre[m+1]-pre[i])<=s)   l=m+1;
            else  r=m-1;
        }
        ans+=(r-i+1);
    }
    cout<<ans;
}