#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+10;

ll n;
ll a[N],pre[N];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(pre,INT_MIN,sizeof(pre));
    for(int i=n-2;i>=0;i--){
        if(a[i]<pre[i+1])  pre[i]=a[i];
        else               pre[i]=pre[i+1];
    }
    stack<ll> st;
    bool flag=false;
    ll k=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]<k){
            if(a[i]>pre[i])   flag=true;    //已经确定c，判断存在d
        }
        while(st.size()!=0 && st.top()<a[i]){
            k=max(k,st.top());    //确定a : nums[a]
            st.pop();
        }
        st.push(a[i]);    //确定b : nums[b]入栈
    }
    if(flag)  cout<<"YES";
    else      cout<<"NO";
}