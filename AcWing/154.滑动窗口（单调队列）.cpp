#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int n,k;
int a[N],q[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	int hh=0,tt=-1;
	for(int i=0;i<n;i++)
	{
		while(hh<=tt && i-k+1>q[hh])  hh++;     //判断对头是否滑出窗口
		while(hh<=tt && a[q[tt]]>=a[i])  tt--;  //判断现有队尾是否已经无用
		q[++tt]=i;
		if(i>=k-1)  printf("%d ",a[q[hh]]);
	}
	printf("\n");
	
	hh=0,tt=-1;
	for(int i=0;i<n;i++)
	{
		while(hh<=tt && i-k+1>q[hh])  hh++;
		while(hh<=tt && a[q[tt]]<=a[i])  tt--;
		q[++tt]=i;
		if(i>=k-1)  printf("%d ",a[q[hh]]);
	}
}
