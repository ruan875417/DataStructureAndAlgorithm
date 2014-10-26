#include<iostream>
using namespace std;
/////////////////////////////////////////////////////
const int maxNum = 100;
const int maxInt = 99999;
typedef struct Edge{
        int begin; //起点 
        int end;   //终点 
        int weight;//权值 
}Edge;
/////////////////////////////////////////////////
class BellmanFord{
      private:
         int numOfNode; // 结点数
         int numOfEdge; // 边数
         int source;  // 源点
         Edge edge[maxNum];    // 保存边的值
         int distance[maxNum]; // 结点到源点最小距离
      public:
         void readCase();
         void relax(int u,int v,int w);
         bool Bellman_Ford();   
         void output();  
};
void BellmanFord::readCase(){
     cin>>numOfNode>>numOfEdge>>source;
     for(int i=1;i<=numOfNode;i++)
         distance[i]=maxInt;
     distance[source]=0;
     for(int i=1;i<=numOfEdge;i++)
     {
         cin>>edge[i].begin>>edge[i].end>>edge[i].weight;
         if(edge[i].begin==source) //注意这里设置初始情况
            distance[edge[i].end]=edge[i].weight;
     }
}
// 松弛计算
void BellmanFord::relax(int u,int v,int w){
     if(distance[v]>distance[u]+w)
        distance[v]=distance[u]+w;
}
bool BellmanFord::Bellman_Ford(){
     for(int i=1;i<numOfNode;i++)
         for(int j=1;j<=numOfEdge;j++)
             relax(edge[j].begin,edge[j].end,edge[j].weight);
     bool flag=true;
     // 判断是否有负环路
     for(int i=1;i<=numOfEdge;i++)
         if(distance[edge[i].end]>distance[edge[i].begin]+edge[i].weight)
         {
            flag=false;
            break;
          }
     return flag;     
}
void BellmanFord::output(){
     if(Bellman_Ford())
        for(int i=1;i<=numOfNode;i++)
           cout<<distance[i]<<endl;
     else
        cout<<"有负环"<<endl; 
}
////////////////////////////////////////////////////////////
int main(){
    BellmanFord bellmanFord;
    bellmanFord.readCase();
    bellmanFord.output();
    system("pause");
    return 0;
}
