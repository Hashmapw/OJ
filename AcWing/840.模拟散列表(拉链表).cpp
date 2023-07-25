#include<bits/stdc++.h>
using namespace std;

const int N=1e6+3;   //取成靠近规模的质数，能够使得冲突尽可能少

int h[N],e[N],ne[N],idx;

void insert(int x)
{
	int k=(x%N+N)%N;    //防止的负数取模后仍是负数的情况出现
	e[idx]=x;
	ne[idx]=h[k];
	h[k]=idx++;
}

bool find(int x)
{
	int k=(x%N+N)%N;
	for(int i=h[k];i!=-1;i=ne[i]){
		if(e[i]==x)  return true;
	}
	return false;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	memset(h,-1,sizeof h);   //清空所有的槽
	
	while(n--)
	{
		char op[2];
		int x;
		scanf("%s%d",op,&x);
		
		if(*op=='I')  insert(x);
		else
		{
			if(find(x))  puts("Yes");
			else         puts("No");
			
		}
	}
}
