#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10,M=N*2;

int n,m;
int h[N],e[N],ne[N],idx;
bool st[N];

int ans=N;

void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u)
{
	st[u]=true;   //标记已经被搜索过
	
	int sum=1,res=0;
	for(int i=h[u];i!=-1;i=ne[i]){
		int j=e[i];
		if(!st[j]){
			int s=dfs(j);
			res=max(res,s);
			sum+=s;
		}
	}
	
	res=max(res,n-sum);
	
	ans=min(ans,res);
	return sum;
}

int main()
{
	cin>>n;
	memset(h,-1,sizeof h);
	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);  add(b,a);
	}
	
	dfs(1);
	cout<<ans<<endl;
}
