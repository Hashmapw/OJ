#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
	if(n<2) return false;
	for(int i=2;i<=n/i;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

int main()
{
	int n,t;
	cin>>n;
	while(n--){
		cin>>t;
		if(is_prime(t))   cout<<"Yes"<<endl;
		else              cout<<"No"<<endl;
	}
}
