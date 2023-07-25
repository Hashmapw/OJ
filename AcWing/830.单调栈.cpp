#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n;
int stk[N],tt;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		while(tt && stk[tt]>=x)  tt--;
		if(tt)   printf("%d ",stk[tt]);
		else     printf("-1 ");
		
		stk[++tt]=x;
	}
}
