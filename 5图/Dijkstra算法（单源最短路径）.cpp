#include <iostream>
#include <cstring>
using namespace std;
const int maxnum =100;
const int maxint =999999;
////////////////////////////////////////////////////////////////////
class Dij{
      private:
          int numOfNode;// 图的结点数
          int numOfEdge;// 图的路径数
          bool s[maxnum]; // 判断是否已存入该点到S集合中
          int distance[maxnum];     // 表示当前点到源点的最短路径长度
          int pre[maxnum];// 记录当前点的前一个结点
          int path[maxnum][maxnum];// 记录图的两点间路径长度
      public:
          void initial(int m,int n);
          void readCase();
          void Dijkstra(int v,int end);
          void searchPath(int v,int end);
};
void Dij::initial(int m,int n){
     numOfNode=m;
     numOfEdge=n;
     memset(s,false,sizeof(s));
     for(int i=1;i<=numOfNode;i++){
         distance[i] = maxint;
         for(int j=1;j<=numOfNode;j++)
            path[i][j]=maxint; 
     }
}
void Dij::readCase(){
     int n1,n2,len;           
     for(int i=1;i<=numOfEdge;i++){
         cin>>n1>>n2>>len;
         if(len<path[n1][n2]){
            path[n1][n2]=path[n2][n1]=len;
        }
    }
}
void Dij::Dijkstra(int v,int end){
    int i,j;
    for(i=1;i<=numOfNode;i++){
        distance[i]=path[v][i];
        if(distance[i]==maxint)
            pre[i] = 0;
        else
            pre[i] = v;
    }
    distance[v]=0;
    s[v]=true;
    // 依次将未放入S集合的结点中，取distance[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，distance[]就记录了从源点到所有其他顶点之间的最短路径长度
 // 注意是从第二个节点开始，第一个为源点
    for(i=2;i<=numOfNode;i++){
        int min=maxint;
        int u=v;
        // 找出当前未使用的点j的distance[j]最小值
        for(j=1;j<=numOfNode;j++)
            if((!s[j])&&distance[j]<min){
                u=j;
                min=distance[j];
            }
        s[u]=true; // 表示u点已存入S集合中
        // 更新distance[j]
        for(j=1;j<=numOfNode;j++)
            if((!s[j])&&path[u][j]<maxint){
                int newdist = distance[u]+path[u][j];
                if(newdist<distance[j]){
                    distance[j]=newdist;
                    pre[j]=u;
                }
            }
    }
    cout<<"源点到最后一个顶点的最短路径长度: "<<distance[end]<<endl;
} 
// 查找从源点v到终点u的路径，并输出
void Dij::searchPath(int v,int end){
    int que[maxnum];
    int tot=1;
    que[tot]=end;
    tot++;
    int tmp=pre[end];
    while(tmp!=v){
        que[tot] =tmp;
        tot++;
        tmp = pre[tmp];
    }
    que[tot]=v;
    cout<<"源点到最后一个顶点的路径为: ";
    for(int i=tot;i>=1;i--)
        if(i!= 1)
            cout << que[i] << " -> ";
        else
            cout << que[i] << endl;
}
////////////////////////////////////////////////////////////////
int main(){
    int n,line;
    Dij x;
    int start,end;
    while(cin>>n>>line){
          x.initial(n,line);
          x.readCase();
          cin>>start>>end;
          x.Dijkstra(start,end);
          x.searchPath(start,end);
    }
    system("pause");
    return 0;
}
