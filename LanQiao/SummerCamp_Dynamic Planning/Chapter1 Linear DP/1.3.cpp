#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int n,m;
int f[N][N];
int a[N],b[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1;i<=m;i++)  cin>>b[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i][j],f[i-1][j]);
            f[i][j]=max(f[i][j],f[i][j-1]);

            if(a[i]==b[j]){
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }
        }
    }
    cout<<f[n][m];
}