#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int primes[N],cnt;
bool st[N];

void get_primes(int n)   // 埃式筛
{
	for(int i=2;i<=n;i++){
		if(!st[i]) primes[cnt++]=i;
		for(int j=i+i;j<=n;j+=i){   //注意这里是i+i
			st[j]=true;
		}
	}
}

void get_primes_pro(int n)  // 线性筛
{
	for(int i=2;i<=n;i++){
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]<=n/i;j++){
			st[primes[j]*i]=true;
			if(i%primes[j]==0)  break;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	get_prime_pro(n);
	cout<<cnt;
}
