#include<bits/stdc++.h>
using namespace std;

string s;
stack<char> check;

int main()
{
    char topch;
    getline(cin,s);
    for(char i:s){
        if(i=='('||i=='['||i=='{'){
            check.push(i);
        }
        else{
            if(check.size()!=0) topch=check.top();
            else{
                cout<<"N";
                return 0;
            }
            bool flag=true;
            if(topch=='('&&i!=')')       flag=false;
            else if(topch=='['&&i!=']')  flag=false;
            else if(topch=='{'&&i!='}')  flag=false;
            if(flag==true){
                check.pop();
            }
            else{
                cout<<"N";
                return 0;
            }
        }
    }
    cout<<"Y";
}