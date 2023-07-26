#include<bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<string,vector<int>>  school;
map<int,char> subject;
vector<int> grade[4];

int getrank(vector<int> &a,int x){
    int l=0,r=a.size()-1;
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]<=x)    r=mid;
        else             l=mid+1;   
    }
    return r+1;
}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        char id[10];
        int temp[4];
        scanf("%s %d %d %d",id,&temp[1],&temp[2],&temp[3]);
        temp[0]=round((temp[1]+temp[2]+temp[3])/3.0);
        for(int j=0;j<4;j++){
            grade[j].push_back(temp[j]);
            school[id].push_back(temp[j]);
        }
    }
    subject[0]='A';
    subject[1]='C';
    subject[2]='M';
    subject[3]='E';
    for(int i=0;i<4;i++)  sort(grade[i].begin(),grade[i].end(),greater<int>());

    while(m--){
        string nowid;
        int nowbest=n+1,nowsubject;
        cin>>nowid;
        if(school.count(nowid)==0){
            cout<<"N/A";
            continue;
        }
        for(int i=3;i>=0;i--){
            int nowrank=getrank(grade[i],school[nowid][i]);
            if(nowrank<=nowbest){
                nowbest=nowrank;
                nowsubject=i;
            }
        }
        cout<<nowbest<<" "<<subject[nowsubject];
    }
}