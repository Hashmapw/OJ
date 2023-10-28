#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n;
int a[N];
int f1[N],f2[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
        f1[i]=f2[i]=1;
    }
    for(int i=1;i<=n;i++){
        f1[i]=max(f1[i],1);
        for(int j=1;j<i;j++){
            if(a[j]<=a[i])  f1[i]=max(f1[i],f1[j]+1);
        }
    }
    for(int i=n;i>=1;i--){
        f2[i]=max(f2[i],1);
        for(int j=n;j>i;j--){
            if(a[j]<=a[i])  f2[i]=max(f2[i],f2[j]+1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)  ans=max(ans,f1[i]+f2[i]-1);
    cout<<n-ans;
}