#include<bits/stdc++.h>
using namespace std;
//思路：Trie树在每个节点尽可能选择与自身各位相反的方向走，遍历一遍即可得到最大异或值。

const int N=1e6+10,M=31*N;

int n;
int a[N];
int son[M][2],idx;

void insert(int x)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int u=x>>i&1;
		if(!son[p][u]) son[p][u]=++idx;
		p=son[p][u];
	}
}

int query(int x)
{
	int p=0,res=0;
	for(int i=30;i>=0;i--)
	{
		int u=x>>i&1;
		if(son[p][!u]){
			p=son[p][!u];
			res=res*2+!u;
		}
		else{
			p=son[p][u];
			res=res*2+u;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		insert(a[i]);
		int t=query(a[i]);
		res=max(res,a[i]^t);
	}
	printf("%d\n",res);
	return 0;
}
