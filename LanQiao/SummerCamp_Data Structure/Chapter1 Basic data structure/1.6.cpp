#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m;
queue<string> vip;
queue<string> common;

int main(){
    cin>>m;
    while(m--){
        string op;
        cin>>op;
        if(op=="IN"){
            string name,type;
            cin>>name>>type;
            if(type=="V")   vip.push(name);
            else if(type=="N")  common.push(name);
        }else if(op=="OUT"){
            string type;
            cin>>type;
            if(type=="V")   vip.pop();
            else if(type=="N")  common.pop();
        }
    }
    while(vip.size()!=0){
        cout<<vip.front()<<endl;
        vip.pop();
    }
    while(common.size()!=0){
        cout<<common.front()<<endl;
        common.pop();
    }
}