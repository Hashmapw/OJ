#include<bits/stdc++.h>
using namespace std;

void divide(int n)
{
	for(int i=2;i<=n/i;i++)
	{
		if(n%i==0)   //i一定是质数
		{
			int s=0;
			while(n%i==0){
				n/=i;
				s++;
			}
			printf("%d %d\n",i,s);
		}
	}
	if(n>1) printf("%d %d\n",n,1);
	puts("");
}

int main()
{
	int n,t;
	cin>>n;
	while(n--){
		cin>>t;
		divide(t);
	}
}
