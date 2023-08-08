#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=1e6+10;

ll n,m;
ll good[N];
pll coupon[N];
priority_queue<ll> q;


int main()
{
    cin>>n>>m;
    ll goodsum=0;
    for(ll i=0;i<n;i++){
        cin>>good[i];
        goodsum+=good[i];
    }
    for(ll i=0;i<m;i++){
        cin>>coupon[i].first;
    }
    for(ll i=0;i<m;i++){
        cin>>coupon[i].second;
    }
    sort(good,good+n);
    sort(coupon,coupon+m);
    ll l=0;
    for(ll i=0;i<n;i++){
        while(l<m&&coupon[l].first<=good[i]){
            q.push(coupon[l].second);
            l++;
        }
        if(q.size()!=0){      //在循环中减去防止爆long long
            goodsum-=q.top();
            q.pop();
        }
    }
    cout<<goodsum<<endl;
}