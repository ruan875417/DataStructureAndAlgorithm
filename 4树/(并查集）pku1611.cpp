#include<iostream>
#include<vector>
using namespace std;
////////////////////////////////////////////////////////////////////
class Union{
      private:
            vector <int> parent;
            vector <bool> root;
      public:
             void initial(int number);
             int find(int a);
             void union1(int a,int b);
             void output();
};
void Union::initial(int number){
     parent.resize(number);
     root.resize(number);
     for(int i=0;i<number;i++){
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
void Union::output(){
     cout<<parent[find(0)]<<endl;;
}
////////////////////////////////////////////////////////////////////
int main(){
    int m,n;
    Union un;
    while(cin>>m>>n&&(m||n)){
          un.initial(m);
          int count,a,b;
          int ra,rb;
          for(int i=0;i<n;i++){
              cin>>count>>a;
              ra=un.find(a);
              for(int j=1;j<count;j++){
                  ra=un.find(a);
                  cin>>b;
                  rb=un.find(b);
                  if(ra!=rb){
                     un.union1(ra,rb);
                  }
              }
          }
          un.output();
    }
    system("pause");
    return 0;
} 
