#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+10;

ll n;
ll s[N],pre[N];
map<int,int> m;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%1d",&s[i]);
    }
    pre[0]=1;
    for(int i=1;i<=n;i++){
        if(s[i]==1)  pre[i]=pre[i-1]-1;
        else      pre[i]=pre[i-1]+1;
    }
    ll sum=0;
    for(int i=0;i<=n;i++){
        sum+=m[pre[i]];
        m[pre[i]]++;
    }
    cout<<sum;
}