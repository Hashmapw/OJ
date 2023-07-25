#include<bits/stdc++.h>
using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		
		int res=0;
		while(x){
			x-=lowbit(x);  //每次减去x的最后一次1
			res++;
		}
		cout<<res<<" ";
	}
}
