#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;

ll n,m;
ll a[N];
ll r[N],l[N];

void calc(){
    stack<ll> num;
    for(int i=0;i<n;i++){
        while(num.size()!=0 && num.top()>=a[i])  num.pop();
        if(num.size()!=0)  l[i]=num.top();
        else               l[i]=0;
        num.push(a[i]);
    }
    num=stack<ll>();
    for(int i=n-1;i>=0;i--){
        while(num.size()!=0 && num.top()<=a[i])  num.pop();
        if(num.size()!=0)  r[i]=num.top();
        else               r[i]=0;
        num.push(a[i]);
    }

}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    calc();
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=r[i]*l[i];
    }
    if(ans>=m)  cout<<"YES";
    else        cout<<"NO";
}