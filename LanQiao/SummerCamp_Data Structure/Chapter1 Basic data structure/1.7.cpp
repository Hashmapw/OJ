#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;
deque<ll> d[N];
ll q,m;

int main()
{
    cin>>q>>m;
    while(q--){
        string op;
        ll a,x;
        cin>>op;
        if(op=="push_back"){
            cin>>a>>x;
            d[a].push_back(x);
        }else if(op=="push_front"){
            cin>>a>>x;
            d[a].push_front(x);
        }else if(op=="pop_front"){
            cin>>a;
            if(d[a].empty())  continue;
            d[a].pop_front();
        }else if(op=="pop_back"){
            cin>>a;
            if(d[a].empty())  continue;
            d[a].pop_back();
        }else if(op=="size"){
            cin>>a;
            cout<<d[a].size()<<endl;
        }else if(op=="front"){
            cin>>a;
            if(d[a].empty())  continue;
            cout<<d[a].front()<<endl;
        }else if(op=="back"){
            cin>>a;
            if(d[a].empty())  continue;
            cout<<d[a].back()<<endl;
        }
    }
}