#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1e6+10;

int n;
int q[N],tmp[N];

LL merge_sort(int l,int r)
{
	if(l>=r) return 0;
	
	int mid=l+r>>1;
	LL res=merge_sort(l,mid) + merge_sort(mid+1,r);
	
	//归并过程
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r){
		if(q[i]<=q[j])  tmp[k++]=q[i++];
		else{
			tmp[k++]=q[j++];
			res+=mid-i+1;
		}
	}
	//扫尾（两侧）
	while(i<=mid)  tmp[k++]=q[i++];
	while(j<=r)    tmp[k++]=q[j++];
	
	//物归原主
	for(int i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
	
	return res;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)  cin>>q[i];
	
	cout<<merge_sort(0,n-1)<<endl;
	
	
}
