#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int q[N],hh,tt;

void Init()
{
	hh=0;
	tt=-1;
}

//插入
void insert(int x)
{
	q[++tt]=x;
}

//弹出
void pop()
{
	hh++;
}

//判断是否为空
bool empty()
{
	if(hh<=tt) return false; //不为空
	else       return true;  //为空
}

//取对头元素
int front()
{
	return q[hh];
}

//取队尾元素
int back()
{
	return q[tt];
}

int main()
{
	int m,x;
	cin>>m;
	Init();
	while(m--){
		string ch;
		cin>>ch;
		if(ch=="push"){
			cin>>x;
			insert(x);
		}
		else if(ch=="empty"){
			cout<<(empty()?"YES":"NO")<<endl;
		}
		else if(ch=="query"){
			cout<<front()<<endl;
		}
		else if(ch=="pop"){
			pop();
		}
	}
}



