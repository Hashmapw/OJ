#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e2+10;

int n,q;
int a[N],diff[N];

int main()
{
    cin>>n>>q;
    vector<ll> left,right;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        left.push_back(l);
        right.push_back(r);
    }
    int l=1,r=q;
    while(l<=r){
        int m=(l+r)/2;
        memset(diff,0,sizeof(diff));
        for(int i=0;i<m;i++){
            diff[left[i]]+=1;
            diff[right[i]]-=1;
        }
        for(int i=1;i<=n;i++){
            diff[i]+=diff[i-1];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(diff[i]>0)  cnt++;
        }
        if((cnt*2)>=n)  r=m-1;
        else          l=m+1;
    }
    if(l==q+1)   cout<<"-1";
    else         cout<<l;
}