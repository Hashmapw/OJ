#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
ll n;
ll temp;
stack<ll> q;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp==0){
            if(q.size()!=0){
                q.pop();
            }
        }
        else{
            q.push(temp);
        }
    }
    while(q.size()!=0){
        cout<<q.top()<<endl;
        q.pop();
    }
}