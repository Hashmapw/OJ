#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
ll n,m;
ll x[N];

bool check(ll v)
{
    int l=x[1],cnt=1;
    for(int i=2;i<=n;i++){
        if(x[i]-l>=v){
            cnt++;
            l=x[i];
        }
    }
    return cnt>=m;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>x[i];
    sort(x+1,x+n+1);
    int l=0,r=x[n]-x[1];
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(mid))  l=mid;
        else            r=mid-1;
    }
    cout<<r;
}