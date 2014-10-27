#include <iostream>
#include <vector>
using namespace std;
/////////////////////
class UnionFind{
      private:
              vector<int> parent;
              vector<bool> root;
              int intLargestSize;
      public:
             void initial(int size);
             void unionl(int a,int b);
             int find(int k);
             int largestSize(){return intLargestSize;}
};
void UnionFind::initial(int n){
     root.resize(n+1);
     parent.resize(n+1);
     for(int k=1;k<=n;k++){
           root[k]=true;
           parent[k]=1;
     }
     intLargestSize=1;
}
void UnionFind::unionl(int r1,int r2){
    if(parent[r1]>parent[r2]){
        parent[r2]+=parent[r1];
        parent[r1]=r2;
        root[r1]=false;
        if(parent[r2]>intLargestSize){
            intLargestSize=parent[r2];
        }
    }else{
          parent[r1]+=parent[r2];
          parent[r2]=r1;
          root[r2]=false;
          if(parent[r1]>intLargestSize){
            intLargestSize=parent[r1];
          }
    } 
}
int UnionFind::find(int k){
    int r=k;
    while(!root[r]){
        r=parent[r];
    }
    int e=k;
    int pe;
    while(e!=r){
        pe=parent[e];
        parent[e]=r;
        e=pe;
    }
    return r;
}
////////////////////////
class FRIENDS{
      private:
              int intNumberOfCitizens;
              int intNumberOfPairs;
              int intNumberOfPeopleInLargestGroup;
              UnionFind uf;
      public:
             void readCase();
             void initial();
             void computing();
             void outReasult();
             
};
void FRIENDS::readCase()
{
     cin>>intNumberOfCitizens>>intNumberOfPairs;
}
void FRIENDS::initial(){
     uf.initial(intNumberOfCitizens);
}
void FRIENDS::computing(){
     int a,b;
     int ra,rb;
     for(int i=0;i<intNumberOfPairs;i++){
             cin>>a>>b;
             ra=uf.find(a);
             rb=uf.find(b);
             if(ra!=rb)
                {uf.unionl(ra,rb);}
     }
     intNumberOfPeopleInLargestGroup=uf.largestSize();
}
void FRIENDS::outReasult(){
     cout<<intNumberOfPeopleInLargestGroup<<endl;
}
int main()
{
    int NumOfCase;
    cin>>NumOfCase;
    FRIENDS f;
    for(int i=0;i<NumOfCase;i++)
    {
         f.readCase();
         f.initial();
         f.computing();
         f.outReasult();
     }
     system("pause");
     return 0;
}
