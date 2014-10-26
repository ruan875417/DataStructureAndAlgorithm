
#include<iostream>
using namespace std;
/////////////////////////////////////////////////////////////////
struct node{
       //建立一个储存两个顶点和它们之间权值大小的结构体
       int begin;
       int end;
       int len;
};
/////////////////////////////////////////////////////////////
class AgriNet{
      private:
          int numOfNode;
          int numOfEdge;
          node edge[5000];
          int father[101];
      public:
          void initial(int n);
          void readCase();
          int find(int n);
          int Kruskal();
};
void AgriNet::initial(int n){
     numOfNode=n;
     numOfEdge=0;
     int i;
     for(i=0;i<n;i++){
         edge[i].begin=0;
         edge[i].end=0;
         edge[i].len=100001;
         father[i]=i;
     }
}
int cmp(const void* a,const void* b){
    node m=*(node*)a;
    node n=*(node*)b;
    return m.len-n.len;
}
void AgriNet::readCase(){
     int i,j;
     int len;
     for(i=0;i<numOfNode;i++){
         for(j=0;j<numOfNode;j++){
             scanf("%d",&len);
             if(j>i){
                edge[numOfEdge].begin=i;
                edge[numOfEdge].end=j;
                edge[numOfEdge++].len=len;
             }
         }
     }  
     //将所有边从小到大排序
     qsort(edge,numOfEdge,sizeof(node),cmp);  
}
//查找一个节点的根节点并剪枝 
int AgriNet::find(int n){
       int k=n;
       while(father[k]!=k){
             k=father[k];
       }
       int t=n;
       int temp;
       while(t!=k){
             temp=father[t];
             father[t]=k;
             t=temp;
       }
       return k;
}
int AgriNet::Kruskal(){
     int i;
     int a,b;
     int sum=0;
     for(i=0;i<numOfEdge;i++){
         a=find(edge[i].begin);
         b=find(edge[i].end);
         //根节点相同，说明已经加入了，再加入该边则会形成回路，该边舍弃
         if(a!=b){
            father[a]=b;
            sum+=edge[i].len;
         }
     }
     return sum;
}
///////////////////////////////////////////////////////////////////
int main(){
    int n;
    AgriNet x;
    while(cin>>n){
          x.initial(n);
          x.readCase();
          cout<<x.Kruskal()<<endl;
    }
    system("pause");
    return 0;
}
