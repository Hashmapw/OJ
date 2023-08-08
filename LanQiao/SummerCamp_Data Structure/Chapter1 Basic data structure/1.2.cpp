#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e2+10;

ll n,k,temp;
ll a[N];
stack<ll> r;   //能够收获的铜锣烧

int main()
{
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>temp;
        a[i]=k-temp;
    }
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=k-1,j=n;i>=0;i--){
        while(j>0 && a[j]>=i){
            r.push(a[j--]);
        }
        if(r.size()!=0){
            ans+=k-r.top()+i;
            r.pop();
        }
    }
    cout<<ans;
}