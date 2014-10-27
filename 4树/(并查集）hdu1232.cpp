#include<iostream>
#include<vector>
using namespace std;
/////////////////////////////////////////////////////////////////////////////
class Union{
      private:
          vector <int> parent;
          vector <bool> root;
      public:
          void initial();
          int find(int a);
          void union1(int a,int b);
          void output(int n);
};
void Union::initial(){
     parent.resize(1000);
     root.resize(1000);
     for(int i=0;i<1000;i++){
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
void Union::output(int n){
     int count=0;
     for(int i=1;i<=n;i++){
         if(root[i]==true){
            count++;
          }
     }
     cout<<count-1<<endl;
}
///////////////////////////////////////////////
int main(){
    int n,m;
    Union un;
    while(cin>>n&&n){
         cin>>m;
         int a,b;
         int ra,rb;
         un.initial();
         for(int i=0;i<m;i++){
             cin>>a>>b;
             ra=un.find(a);
             rb=un.find(b);
             if(ra!=rb){
                un.union1(ra,rb);
             }
          }
          un.output(n);
     }
     system("pause");
     return 0;
}
     
