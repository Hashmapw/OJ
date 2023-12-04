#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+10;
typedef pair<int,int> PII;

int n;
PII w[N];
int f[N];

bool cmp(PII t1,PII t2){
    if(t1.first==t2.first)  return t1.second<t2.second;
    return t1.first>t2.first;
    
}

signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i].first>>w[i].second;
    }

    sort(w+1,w+n+1,cmp);

    for(int i=1;i<=n;i++){
        cout<<w[i].first<<" "<<w[i].second<<endl;
    }
    int time=0;
    for(int i=1;i<=n;i++){
        if(w[i].first<time){
            f[i]=f[i-1];
            time-=w[i].first;
        }
        else{
            f[i]=f[i-1]+w[i].second;
            time = w[i].first;
        }
    }
    cout<<f[n]<<endl;
}