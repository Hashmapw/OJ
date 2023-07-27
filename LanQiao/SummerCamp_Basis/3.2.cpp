//3.2【算法模板题】肖恩的投球游戏加强版
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e3+10;
int n,m,q;
ll ball[N][N];
ll diff[N][N];


int main()
{
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%ld",&ball[i][j]);
        }
    }
    while(q--){
        int x1,x2,y1,y2,c;
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
        diff[x1][y1]+=c;
        diff[x2+1][y1]-=c;
        diff[x1][y2+1]-=c;
        diff[x2+1][y2+1]+=c;
    }
    //求前缀和（行）
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            diff[i][j+1]+=diff[i][j];
        }
    }
    //求前缀和（列）
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++){
            diff[i+1][j]+=diff[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",(ball[i][j]+diff[i][j]));
        }
        printf("\n");
    }
}