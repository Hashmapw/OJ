#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+10;
ll n,s;
ll a[N];

int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll l=0,r=0,tot_sum=0,ans=0;
    while(l<n){
        while(r<n&&tot_sum+a[r]<=s){
            tot_sum+=a[r];
            r+=1;
        }
        ans+=r-l;   //共有[l,l][l,l+1],...,[l,r-1]区间满足要求
        tot_sum-=a[l];
        l+=1;
    }
    cout<<ans;
}