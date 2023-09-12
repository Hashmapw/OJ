#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,pair<ll,ll>> pll;
const int N=1e6+10;

ll n;
string s;
ll ability[N];
priority_queue<pll,vector<pll>,greater<pll>> q;
bool already[N];
queue<pll> ans;

void append()
{
    ll i=0,j=1;
    while(i<n)
    {
        while(j<=n){
            if(s[i]==s[j]){
                i=j;
                j++;
            }
            else{
                if(already[i]==false && already[j]==false){
                    q.push({abs(ability[j]-ability[i]),{i,j}});
                    i++;
                    j++;
                }
                else if(already[i]==false && already[j]==true){
                    j++;
                }
                else if(already[i]==true && already[j]==false){
                    i++;
                }
                else if(already[i]==true && already[j]==true){
                    i++;
                    j++;
                }
            }
        }
    }
}

int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
        cin>>ability[i];
    ll cnt=0;
    append();
    while(q.size()!=0){
        
        ll x=q.top().second.first,y=q.top().second.second;
        if(already[x]==false && already[y]==false){
            ans.push(q.top());
            already[x]=true;
            already[y]=true;
            q.pop();
            cnt++;
        }
        else if(already[x]==true || already[y]==true){
            q.pop();
        }
        append();
    }
    cout<<ans.size()<<endl;
    while(ans.size()!=0){
        cout<<ans.front().second.first+1<<" "<<ans.front().second.second+1<<endl;
        ans.pop();
    }
}