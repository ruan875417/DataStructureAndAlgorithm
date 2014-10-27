#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
///////////////////////////////////////////////////////////////
class Union{
      private:
           vector <int> parent;
           vector <bool> root;
      public:
           void initial(int studentNumber);
           int find(int a);
           void union1(int a,int b);
           bool boolRoot(int i);
};
void Union::initial(int studentNumber){
     parent.resize(studentNumber+1);
     root.resize(studentNumber+1);
     for(int i=1;i<=studentNumber;i++){
         parent[i]=1;
         root[i]=true;
     }
}
int Union::find(int a){
    int r=a;
    while(!root[r]){
          r=parent[r];
    }
    int k=a;
    int temp;
    while(k!=r){
          temp=parent[k];
          parent[k]=r;
          k=temp;
    } 
    return r;
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
bool Union::boolRoot(int i){
   return root[i];
}    
////////////////////////////////////////////////////////////////////
class UbiquitousReligions{
      private:
            int maxNumber;
            static int count;
            Union un;
      public:
            void initial(int n);
            void compute(int sn,int pr);
            void output();
};
int UbiquitousReligions::count=1;
void UbiquitousReligions::initial(int n){
     maxNumber=0;
     un.initial(n);
}
void UbiquitousReligions::compute(int sn,int pr){
     int temp1,temp2;
     int rtemp1,rtemp2;
     int i;
     for(i=0;i<pr;i++){
         cin>>temp1>>temp2;
         rtemp1=un.find(temp1);
         rtemp2=un.find(temp2);
         if(rtemp1!=rtemp2){
            un.union1(rtemp1,rtemp2);
         }
     }
     for(i=1;i<=sn;i++){
         if(un.boolRoot(i)==true){
              maxNumber++;
         }
     }
}
void UbiquitousReligions::output(){
     cout<<"Case "<<count++<<": "<<maxNumber<<endl;
}
///////////////////////////////////////////////////////////////////
int main(){
    int studentNumber,pairs;
    UbiquitousReligions x;
    while(cin>>studentNumber>>pairs&&(studentNumber||pairs)){
         x.initial(studentNumber);
         x.compute(studentNumber,pairs);
         x.output();
         
    }
    system("pause");
    return 0;
}
