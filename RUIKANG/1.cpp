#include<bits/stdc++.h>
using namespace std;

int n;
string s;

void deal()
{
    int bigcnt=0,smallcnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'&&(s[i+1]<'A'||s[i+1]>'Z')){
            bigcnt=0;
            smallcnt=0;
        }
        if(s[i]>='a'&&s[i]<='z'&&(s[i+1]<'a'||s[i+1]>'z')){
            bigcnt=0;
            smallcnt=0;
        }
        if(s[i]=='Z'){
            s[i]='A';
            bigcnt++;
        }
        else if(s[i]=='a'){
            s[i]='z';
            smallcnt++;
        }
        else if(s[i]>='A'&&s[i]<'Z'){
            s[i]=s[i]+1;
            bigcnt++;
        }
        else if(s[i]>'a'&&s[i]<='z'){
            s[i]=s[i]-1;
            smallcnt++;
        }
        if(bigcnt>=3&&(s[i+1]<'A'||s[i+1]>'Z')){
            for(int j=i;j>i-bigcnt;j--){
                s[j]=s[j]+32;
            }
            bigcnt=0;
            smallcnt=0;
        }
        if(smallcnt>=3&&(s[i+1]<'a'||s[i+1]>'z')){
            for(int j=i;j>i-smallcnt;j--){
                s[j]=s[j]-32;
            }
            bigcnt=0;
            smallcnt=0;
        }
    }
}


int main()
{
    cin>>n;
    getchar();
    getline(cin,s);
    if(s.find("yourname")!=-1)  s.replace(s.find("yourname"),s.find("yourname")+8,"liwentao");
    cout<<s<<endl;
    while(n--){
        deal();
    }
    cout<<s<<endl;
}