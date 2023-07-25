#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int stk[N],tt;

void init()
{
	tt=0;     // tt 表示栈顶
}

//插入
void insert(int x){
	stk[++tt]=x;
}

//弹出
void pop()
{
	tt--;
}

//判断是否为空
bool empty()
{
	if(tt>0) return false;  //不为空
	else     return true;   //为空
}

//取栈顶元素
int top()
{
	return stk[tt];
}

int main()
{
	int m,x;
	cin>>m;
	init();
	while(m--)
	{
		string ch;
		cin>>ch;
		if(ch=="push"){
			cin>>x;
			insert(x);
		}
		else if(ch=="query"){
			cout<<top()<<endl;
		}
		else if(ch=="pop"){
			pop();
		}
		else if(ch=="empty"){
			cout<<(empty()?"YES":"NO")<<endl;
		}
	}
}
