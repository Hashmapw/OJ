#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	int res=0;
	
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		if(x%2!=0) res^=x;
	}
	if(res) puts("Yes");
	else    puts("No");
}
