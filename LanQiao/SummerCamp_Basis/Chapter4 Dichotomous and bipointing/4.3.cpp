#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;

int n,s;
int a[N];

int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=1,tot_sum=0,ans=n+1;
    while(l<=n){
        while(r<n && tot_sum<=s){
            tot_sum+=a[r];
            r+=1;
        }
        if(tot_sum<=s) break;
        ans=min(ans,r-1);
        tot_sum-=a[l];
        l+=1;
    }
    if(ans!=n+1){
        cout<<ans;
    }
    else{
        cout<<"-1";
    }
}