#include<bits/stdc++.h>
using namespace std;

const int N=2e3+10;

int n;
int a[N],f[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i]=max(f[i],1);
        for(int j=1;j<i;j++){
            if(a[j]<a[i])  f[i]=max(f[i],f[j]+1);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)  ans=max(ans,f[i]);
    cout<<ans;
}