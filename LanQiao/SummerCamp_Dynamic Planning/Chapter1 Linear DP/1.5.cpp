#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,MOD=1e9+7;

int n,m;
int a[N];
int f[N];

int main()
{
    int x;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        a[x]=1;
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]) continue;
        f[i]=f[i-1]+f[i-2];
        f[i]%=MOD;
    }
    cout<<f[n];
}