#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll q;
deque<ll> stu;

int main()
{
    cin>>q;
    ll op;
    while(q--){
        cin>>op;
        if(op==1){
            ll x;
            cin>>x;
            stu.push_back(x);
        }else if(op==2){
            stu.pop_front();
        }else if(op==3){
            cout<<stu.front()<<" "<<stu.back()<<endl;
        }
    }
}