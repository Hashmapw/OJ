#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10,M=2e3+10;

typedef pair<int,int> PII;

int n,k;
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];

void dijkstra()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	heap.push({0,1});
	
	while(heap.size())
	{
		auto t=heap.top();
		heap.pop();
		
		int ver=t.second,distance=t.first;
		if(st[ver])   continue;   //冗余备份无需处理
		st[ver] = true;
		
		for(int i=h[ver];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>distance+w[i])
			{
				dist[j]=distance+w[i];
				heap.push({dist[j],j});
			}
		}
	}
	
	if(dist[k]==0x3f3f3f3f)  cout<<"-1";
	else    cout<<dist[k]+1;
}

void add(int a,int b,int c)
{
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

int main()
{
    cin>>n>>k;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b,1);
    }
    
    dijkstra();
}