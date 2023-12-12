#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;

int n;
int pre[N];
set<int> ans;

int main()
{
    cin>>n;
    int temp=0;
    if(n<=2){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>temp;
        pre[i]=pre[i-1]+temp;
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<pre[i]-pre[0]<<" "<<pre[j]-pre[i]<<" "<<pre[n]-pre[j]<<endl;
            //if(pre[i]-pre[0]==0 || pre[j]-pre[i]==0 || pre[n]-pre[j]==0) continue;
            if(pre[i]-pre[0]==pre[j]-pre[i] && pre[j]-pre[i]==pre[n]-pre[j] && pre[i]-pre[0]==pre[n]-pre[j]){
                ans.insert(pre[i]-pre[0]);
            }
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}
