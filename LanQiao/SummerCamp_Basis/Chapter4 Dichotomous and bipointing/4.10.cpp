#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+10;
ll n,m;
ll a[N],pre[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll l=1,r=1,cnt=0;
    while(l<=n){
        while(r<=n){
            if(pre[r]-pre[l-1]>=m){
                cnt+=n-r+1;
                break;
            }else{
                r++;
            }
        }
        l++;
    }
    cout<<cnt<<endl;
}