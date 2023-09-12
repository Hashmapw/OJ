#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e6+10;
ll n,k;
ll a[N];
ll minn[N],maxn[N];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<ll> q;
    for(int i=1;i<=n;i++){
        if(q.size()!=0 && q.front()<=max((ll)1,i-k))  q.pop_front();
        while(q.size()!=0 && a[q.back()]>=a[i])   q.pop_back();
        q.push_back(i);
        minn[i]=a[q.front()];
    }
    for(int i=1;i<=n;i++){
        if(q.size()!=0 && q.front()<=max((ll)1,i-k))  q.pop_front();
        while(q.size()!=0 && a[q.back()]<=a[i])   q.pop_back();
        q.push_back(i);
        maxn[i]=a[q.front()];
    }
    ll ans=INT_MIN;
    for(int i=1;i<=n;i++){
        ans=max(ans,maxn[i]-minn[i]);
    }
    cout<<ans;
}