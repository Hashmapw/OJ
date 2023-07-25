#include<bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int>&A,int b)
{
	vector<int> C;
	
	int t=0;
	for(int i=0;i<A.size()||t;i++){   //条件判断中的t表示进位未处理完
		if(i<A.size())  t+=A[i]*b;
		C.push_back(t%10);
		t/=10;                        //下一级进位后权重是原来十分之一
	}
	while(C.size()>1 &&C.back()==0)  C.pop_back();   //删除前导0
	return C;
}

int main()
{
	string a;
	int b;
	
	cin>>a>>b;
	
	vector<int> A;
	for(int i=a.size()-1;i>=0;i--)  A.push_back(a[i]-'0');
	
	auto C=mul(A,b);
	
	for(int i=C.size()-1;i>=0;i--)  printf("%d",C[i]);
	
	return 0;
}
