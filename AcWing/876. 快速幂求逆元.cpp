#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int qmi(int a,int k,int p)  //返回a^k%p
{
	int res=1;
	while(k){
		if(k&1)  res=(LL)res*a%p;
		k>>=1;
		a=(LL)a*a%p;
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--){
		int a,k,p;
		scanf("%d%d",&a,&p);
		
		int res=qmi(a,p-2,p);
		if(a%p!=0) printf("%d\n",res);
		else       puts("impossible");
	}
}
