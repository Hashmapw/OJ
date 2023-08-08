#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,temp,x;
queue<ll> q;

int main()
{
    cin>>n;
    while(n--){
        cin>>temp;
        if(temp==1){
            cin>>x;
            q.push(x);
        }
        else if(temp==2){
            if(q.size()!=0)  q.pop();
            else             cout<<"lan"<<endl;
        }
        else if(temp==3){
            if(q.size()!=0)  cout<<q.front()<<endl;
            else             cout<<"qiao"<<endl;
        }
        else if(temp==4){
            cout<<q.size()<<endl;
        }
    }
}