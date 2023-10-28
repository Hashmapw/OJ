#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10,MOD=1e9+7;

int n,k;
int f[N];

int main()
{
    cin>>n>>k;
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(i>=k+1){
            f[i]=(f[i]+f[i-k-1])%MOD;
        }else{
            f[i]=f[i]+1;
        }
    }
    cout<<f[n];
}
