#include<bits/stdc++.h>
using namespace std;


int n;
unordered_map<string,int> chess;

int main()
{
    cin>>n;
    getchar();
    while(n--){
        string now="",temp="";
        for(int i=0;i<8;i++){
            getline(cin,temp);
            now+=temp;
        }
        chess[now]++;
        cout<<chess[now]<<endl;
    }
}