#include<bits/stdc++.h>
using namespace std;

const int N=1e2+10;
int son[N][26],cnt[N],idx;   //下标为0的点，既是根节点，又是空节点
char str[N];

void insert(char str[])
{
	int p=0;
	for(int i=0;str[i];i++)   //str结尾'\0'作为结束条件
	{
		int u=str[i]-'a';
		if(!son[p][u])  son[p][u]=++idx;
		p=son[p][u];
	}
	cnt[p]++;
}

int query(char str[])
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u])  return 0;
		p=son[p][u];
	}
	
	return cnt[p];
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char op[2];
		scanf("%s%s",op,str);
		if(op[0]=='I') insert(str);
		else printf("%d\n",query(str));
	}
}
