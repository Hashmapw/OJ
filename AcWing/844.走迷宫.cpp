#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=110;

int n,m;
int g[N][N];
int d[N][N];
PII q[N*N];
PII pre[N][N];   //用于记录当前点的前序点

int bfs()
{
	int hh=0,tt=0;
	q[0]={0,0};
	
	memset(d,-1,sizeof d);
	d[0][0]=0;
	
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	
	while(hh<=tt){
		auto t=q[hh++];
		for(int i=0;i<4;i++){
			int x=t.first+dx[i],y=t.second+dy[i];
			if( x>=0 && x<n && y>=0 && y<m && g[x][y]==0 &&d[x][y]==-1){
				d[x][y]=d[t.first][t.second]+1;
				pre[x][y]=t;
				q[++tt]={x,y};
			} 
		}
	}
	/*  用于输出遍历路径
	int x=n-1,y=m-1;
	while(x||y){
		cout<<x<<" "<<y<<endl;
		auto t=pre[x][y];
		x=t.first,y=t.second;
	}
	*/
	return d[n-1][m-1];
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	
	cout<<bfs()<<endl;
}
