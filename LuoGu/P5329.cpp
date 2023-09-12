#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string,ll> psl;

const int N=1e5+10;
psl p[N];

int main()
{
    int n;
    string s;
    cin>>n;
    getchar();
    getline(cin,s);
    for(int i=0;i<n;i++){
        string ch=s.substr(i,1);
        s.erase(i,1);
        p[i]={s,i+1};
        s.insert(i,ch);
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        cout<<p[i].second<<" ";
    }
}