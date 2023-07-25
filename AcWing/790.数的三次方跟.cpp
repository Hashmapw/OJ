#include<bits/stdc++.h>
using namespace std;

int main()
{
	double x;
	cin>>x;
	
	double l=-10000,r=10000;        //这里的值是根据本题的结果给定的
	while(r-l>1e-8)                 //保留6位小数，取10-8；保留4位小数，取10-6；（多两位）
	{
		double mid=(l+r)/2;
		if(mid*mid*mid>=x)  r=mid;
		else                l=mid;
	}
	printf("%lf\n",l);
	
	return 0;
}
