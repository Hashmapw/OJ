#include<bits/stdc++.h>
using namespace std;

const int N=1e2+10;

int e[N],l[N],r[N],idx;

//初始化  r表示右端,l表示左端
void Init()
{
	r[0]=1,l[1]=0;
	idx=2;
}

//在下标是k的点的右边插入x <-> 在下标是k+1的点的左边插入x
void add(int k,int x)
{
	e[idx]=x;
	r[idx]=r[k];
	l[idx]=k;
	l[r[k]]=idx;
	r[k]=idx++;
}

//删除第k个点
void remove(int k)
{
	r[l[k]]=r[k];
	l[r[k]]=l[k];
}

int main()
{
	int m,x,k;
	cin>>m;
	Init();
	
	while(m--){
		string ch;
		cin>>ch;
		
		if(ch=="L"){
			cin>>x;
			add(0,x);
		}else if(ch=="R"){
			cin>>x;
			add(l[1],x);
		}else if(ch=="D"){
			cin>>k;
			remove(k+1);
		}else if(ch=="IL"){
			cin>>k>>x;
			add(l[k+1],x);
		}else if(ch=="IR"){
			cin>>k>>x;
			add(k+1,x);
		}
	}
	for(int i=r[0];i!=1;i=r[i]){
		cout<<e[i]<<" ";
	}
	cout<<endl;
}
