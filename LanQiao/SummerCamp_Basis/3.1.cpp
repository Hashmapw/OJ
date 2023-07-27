//3.1【算法模板题】肖恩的投球游戏
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,q;
int ball[N],op[N];
int l,r,c;

int main()
{
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        scanf("%d",&ball[i]);
    }
    while(q--)
    {
        scanf("%d%d%d",&l,&r,&c);
        op[l]+=c;
        op[r+1]-=c;
    }
    for(int i=1;i<=n;i++)  op[i]+=op[i-1];
    for(int i=1;i<=n;i++)  cout<<ball[i]+op[i]<<" ";
}