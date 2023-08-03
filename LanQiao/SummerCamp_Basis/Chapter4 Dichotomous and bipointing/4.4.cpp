#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;

int n,q;
int a[N],pre[N];


int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    while(q--){
        int x,l,r;
        cin>>x;
        if(pre[n]<x)  cout<<"-1"<<endl;
        else{
            l=0,r=n;
            while(l<=r){
                int m=(l+r)/2;
                if(pre[m]>=x)  r=m-1;
                else           l=m+1;
            }
            cout<<l<<endl;
        }
    }
}