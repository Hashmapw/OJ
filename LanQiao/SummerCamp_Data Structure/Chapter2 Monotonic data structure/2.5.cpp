#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e6+10;
const ll M=998244353;

ll n,k,x;
ll a[N];
ll minn[N],maxn[N];
deque<ll> q;

ll pow_mod(ll a, ll b, ll p){  //快速幂模板
    ll ret = 1;
    while(b){
        if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}

int main()
{
    cin>>n>>k>>x;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        if(q.size()!=0 && q.front()<=i-k)  q.pop_front();
        while(q.size()!=0 && a[q.back()]>=a[i])   q.pop_back();
        q.push_back(i);
        minn[i]=a[q.front()];
    }
    q.clear();
    for(ll i=1;i<=n;i++){
        if(q.size()!=0 && q.front()<=i-k)  q.pop_front();
        while(q.size()!=0 && a[q.back()]<=a[i])   q.pop_back();
        q.push_back(i);
        maxn[i]=a[q.front()];
    }
    ll now=0,cnt=0;
    for(ll i=k;i<=n;i++){
        now=maxn[i]-minn[i];
        if(now<=x)  cnt++;
    }
    ll ans=cnt*pow_mod(n-k+1, M-2, M) % M;
    cout<<ans<<endl;
}