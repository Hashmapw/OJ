#include<bits/stdc++.h>
using namespace std;


int n;

bool check(int m)
{
    if(4*m+6<=n)  return true;
    else          return false;
}

int main()
{
    cin>>n;
    int l=0,r=199;
    while (l<=r){
        int m=(l+r)/2;
        if(check(m))  l=m+1;
        else          r=m-1;
    }
    cout<<r;
}