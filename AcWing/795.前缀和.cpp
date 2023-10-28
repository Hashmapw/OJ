#include<bits/stdc++.h>
using namespace std;

const int N=100010;

int n,m;
int a[N],s[N];

int main()
{
	FILE *f1,*f2;
	f1 = fopen("1.txt","rw+");
	f2 = fopen("2.txt","rw+");
	fscanf(f1,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)  fscanf(f1,"%d",&a[i]);
	
	//求前缀和数组
	for(int i=1;i<=n;i++)  s[i]=s[i-1]+a[i];
	
	while(m--)
	{
		int l,r;
		fscanf(f1,"%d%d",&l,&r);
		fprintf(f2,"%d\n",s[r]-s[l-1]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
