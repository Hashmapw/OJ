#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long,long> pll;
const int N=1e2+10;
ll n,x,temp;
queue<pll> p;
priority_queue<ll> q;

int main()
{
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>temp;
        p.push({i,temp});
        q.push(temp);
    }
    ll time=0;
    while(p.size()!=0){
        if(q.top()==p.front().second){
            time++;
            if(p.front().first==x){
                cout<<time;
                return 0;
            }
            q.pop();
            p.pop();
        }else{
            p.push(p.front());
            p.pop();
        }
    }
}