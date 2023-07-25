#include<bits/stdc++.h>
using namespace std;

typedef struct Book
{
    int id;
    string name;
    string author;
    set<string> key;
    string copyright;
    string year;
}Book;

const int N=1e4+10;

int n,m;
Book library[N];
vector<int> output;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string keyline,temp;
        cin>>library[i].id;
        getchar();
        getline(cin,library[i].name);
        getline(cin,library[i].author);
        getline(cin,keyline);
        getline(cin,library[i].copyright);
        getline(cin,library[i].year);
        
        stringstream ssin(keyline);
        while(ssin>>temp)  library[i].key.insert(temp);
    }
    scanf("%d",&m);
    while(m--){
        int cas;
        bool flag=false;
        char cintemp[500];
        string lookup;
        output.clear();

        scanf("%d: ",&cas);
        cin.get(cintemp,500);
        lookup=cintemp;


        if(cas==1){
            for(int i=0;i<n;i++){
                if(library[i].name==lookup){
                    output.push_back(library[i].id);
                    flag=true;
                }
            }
        }
        else if(cas==2){
             for(int i=0;i<n;i++){
                if(library[i].author==lookup){
                    output.push_back(library[i].id);
                    flag=true;
                }
            }
        }
        else if(cas==3){
            for(int i=0;i<n;i++){
               if(library[i].key.count(lookup)){
                    output.push_back(library[i].id);
                    flag=true;
               }
            }
        }
        else if(cas==4){
            for(int i=0;i<n;i++){
                if(library[i].copyright==lookup){
                    output.push_back(library[i].id);
                    flag=true;
                }
            }
        }
        else if(cas==5){
            for(int i=0;i<n;i++){
                if(library[i].year==lookup){
                    output.push_back(library[i].id);
                    flag=true;
                }
            }
        }
        cout<<cas<<": "<<lookup<<endl;
        if(flag==false)  cout<<"Not Found\n";
        else{
            sort(output.begin(),output.end());
            for(auto x:output){
                printf("%07d\n",x);
            }
        }
    }
}