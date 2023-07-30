#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+10;
ll n,m;
ll prov[N],diff[N];
ll d[N],s[N],t[N];

void insert(ll l,ll r,ll c)
{
	diff[l]+=c;
	diff[r+1]-=c;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>prov[i];
    }
    for(int i=1;i<=m;i++){
        cin>>d[i]>>s[i]>>t[i];
        insert(s[i],t[i],d[i]);
    }
    for(int i=1;i<=n;i++)  diff[i]+=diff[i-1];
    for(int i=1;i<=n;i++){
        if(diff[i]>prov[i]){
            ll now=diff[i],deal;
            for(int j=m;j>=1;j--){
                if(s[j]<=i && t[j]>=i){  //包含超过了的这一天
                    now-=d[j];
                    if(now<=prov[i]){
                        deal=j;
                        break;
                    }
                }
            }
            cout<<"-1"<<endl<<deal;
            return 0;
        }
    }
    cout<<"0"<<endl;
}