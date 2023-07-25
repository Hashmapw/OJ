#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,m;
int p[N],siz[N];  //命名为size会与库函数名称冲突

int find(int x)   //返回x所在集合的编号   //返回x的祖宗节点+路径压缩
{
	if(p[x]!=x)  p[x]=find(p[x]);
	return p[x];
}


int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		siz[i]=1;
	}
	
	while(m--)
	{
		char op[2];
		int a,b;
		scanf("%s",op);
		
		if(op[0]=='C'){
			scanf("%d %d",&a,&b);
			if(find(a)==find(b)) continue;  //a和b已经在一个集合之中
			siz[find(b)]+=siz[find(a)];
			p[find(a)]=find(b);
		}
		else if(op[1]=='1')
		{
			scanf("%d%d",&a,&b);
			if(find(a)==find(b))  puts("Yes");
			else                  puts("No");
		}
		else
		{
			scanf("%d",&a);
			printf("%d\n",siz[find(a)]);
		}
	}
}
