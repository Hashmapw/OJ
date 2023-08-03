#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
ll n;
int h[N],l[N],r[N],q[N];

int main()
{
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++) cin>>h[i];
        h[0]=-1,h[n+1]=-1;
        int tt=0;
        q[0]=0;
        for(int i=1;i<=n;i++){
            while(h[i]<=h[q[tt]])  tt--;
            l[i]=q[tt];
            q[++tt]=i;
        }
        tt=0;
        q[0]=n+1;
        for(int i=n;i;i--){
             while(h[i]<=h[q[tt]])  tt--;
             r[i]=q[tt];
             q[++tt]=i;
        }
        ll res=0; 
        for(int i=1;i<=n;i++){
            res=max(res,(ll)h[i]*(r[i]-l[i]-1));
        }
        cout<<res<<endl;
    }
}