#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

const int N=3e5+10;

int n,m;
int a[N],s[N];

vector<int> alls;
vector<PII> add,query;

int find(int x)
{
	int l=0,r=alls.size()-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(alls[mid]>=x) r=mid;
		else             l=mid+1;
	}
	return r+1;
}
//find函数也可以写作
/*
int find(int x)
{
	  return lower_bound(alls.begin(),alls.end(),x)-alls.begin()+1;
}
*/

vector<int>::iterator unique(vector<int> &a)
{
	//利用双指针算法实现
	int j=0;
	for(int i=0;i<a.size();i++){
		if(!i||a[i]!=a[i-1])   //!i处理第1个元素
			a[j++]=a[i];
		//a[0]~a[j-1]所有a中不重复的数
	}
	return a.begin()+j;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x,c;
		cin>>x>>c;
		add.push_back({x,c});
		alls.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		query.push_back({l,r});
		
		alls.push_back(l);
		alls.push_back(r);
	}
	
	//去重
	sort(alls.begin(),alls.end());
	//alls.erase(unique(alls.begin(),alls.end()),alls.end());   //调库做
	alls.erase(unique(alls),alls.end());                        //自己写
	
	for(auto item:add)
	{
		int x=find(item.first);
		a[x]+=item.second;
	}
	
	//预处理前缀和
	for(int i=1;i<=alls.size();i++)  s[i]=s[i-1]+a[i];
	
	//处理询问
	for(auto item:query)
	{
		int l=find(item.first),r=find(item.second);
		cout<<s[r]-s[l-1]<<endl;
	}
	return 0;
}
