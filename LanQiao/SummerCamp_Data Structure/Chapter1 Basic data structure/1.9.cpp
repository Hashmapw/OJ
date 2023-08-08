#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const int N=2e5+10;
ll n,k;
pll ab[N];
priority_queue<ll,vector<ll>,greater<ll>> p;

bool cmp(pll t1,pll t2){
    return t1.second>=t2.second;   //最大气质值在前
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>ab[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>ab[i].second;
    }
    sort(ab,ab+n,cmp);
    ll maxval=0,nowval=0;
    for(int i=0;i<k;i++){
        p.push(ab[i].first);
        nowval+=ab[i].first;
        maxval=max(maxval,ab[i].second*nowval);
    }
    for(int i=k;i<n;i++){
        if(ab[i].first>p.top()){
            nowval=nowval+ab[i].first-p.top();
            p.pop();
            p.push(ab[i].first);
        }
        maxval=max(maxval,ab[i].second*nowval);
    }
    cout<<maxval<<endl;
}