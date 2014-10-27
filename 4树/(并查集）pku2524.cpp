#include<iostream>
#include<vector>
using namespace std;
////////////////////////////////////////////////////////////////////
class Union{
      private:
            vector <int> parent;
            vector <bool> root;
            static int cnt;
      public:
             void initial();
             int find(int a);
             void union1(int a,int b);
             void output(int number);
};
int Union::cnt=1;
void Union::initial(){
     parent.resize(50001);
     root.resize(50001);
     for(int i=0;i<50001;i++){
         parent[i]=1;
         root[i]=true;
     }
}
int Union::find(int a){
    int k=a;
    while(!root[k]){
          k=parent[k];
    }
    int t=a;
    int temp;
    while(t!=k){
          temp=parent[t];
          parent[t]=k;
          t=temp;
     }
     return k;
}
void Union::union1(int a,int b){
     if(parent[a]>parent[b]){
         parent[b]+=parent[a];
         parent[a]=b;
         root[a]=false;
     }else{
         parent[a]+=parent[b];
         parent[b]=a;
         root[b]=false;
     }
}
void Union::output(int number){
     int count=0;
     for(int i=1;i<=number;i++){
         if(root[i]==true){
            count++;
         }
     }
     cout<<"Case "<<cnt++<<": "<<count<<endl;     
}
///////////////////////////////////////////////////////////////////
int main(){
    int m,n;
    int a,b;
    int ra,rb;
    Union un;
    while(cin>>m>>n&&(m||n)){
          un.initial();
          for(int i=0;i<n;i++){
              cin>>a>>b;
              ra=un.find(a);
              rb=un.find(b);
              if(ra!=rb){
                 un.union1(ra,rb);
              }
          }
          un.output(m);
    }
    system("pause");
    return 0;
}
