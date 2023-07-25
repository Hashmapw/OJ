#include<bits/stdc++.h>
using namespace std;

const int N=2e6+3;   //取成靠近规模的质数，能够使得冲突尽可能少
const int null=0x3f3f3f3f;   //用于标记无法找到  0x3f3f3f3f大于10^9

int h[N]; 

int find(int x)
{
	int k=(x%N+N)%N;
	while (h[k]!=null && h[k]!=x)
	{
		k++;
		if(k==N)  k=0;
	}
	return k;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	memset(h,0x3f,sizeof h);   //清空所有的槽
	
	while(n--)
	{
		char op[2];
		int x;
		scanf("%s%d",op,&x);
		
		int k=find(x);
		if(*op=='I')        h[k]=x;
		else
		{
			if(h[k]!=null)  puts("Yes");
			else            puts("No");
		}
	}
}
