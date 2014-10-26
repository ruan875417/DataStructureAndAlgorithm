#include "stdio.h"    
#include "stdlib.h" 
#include<stack>  
#define max 100
using namespace std;
typedef int VertexType; //顶点类型
typedef int EdgeType; //边的权值类型
typedef struct EdgeNode{//边表结点 
        int adjvex;//邻接点域 
        EdgeType weight;// 权值 
        struct EdgeNode *next;//指向下一个邻接点 
}EdgeNode;
typedef struct VertexNode{//顶点表结点 
        int in;
        VertexType data;//顶点域 
        EdgeNode *firstedge;//边表头指针 
}vertexNode,AdjList[max];
typedef struct GraphAdjList{
        AdjList adjList;
        int numVertexes,numEdges;
}GraphAdjList;
void CreatALGraph(GraphAdjList *G){
     int i,j,k,weight;
     EdgeNode *e;
     printf("请输入顶点数和边数：\n");
     scanf("%d%d",&G->numVertexes,&G->numEdges);
     for(i=0;i<G->numVertexes;i++){
         printf("请输入顶点：");
         scanf("%d",&G->adjList[i].data);
         G->adjList[i].in=0;
         G->adjList[i].firstedge=NULL;
     }
     for(k=0;k<G->numEdges;k++){
         printf("输入边<vi,vj>上的顶点序号和权值:\n");
		 scanf("%d%d%d",&i,&j,&weight); 
		 
		 e=(EdgeNode *)malloc(sizeof(EdgeNode));
		 e->adjvex=j;
		 e->weight=weight;
		 e->next=G->adjList[i].firstedge;
		 G->adjList[i].firstedge=e;
		 
		 e=(EdgeNode *)malloc(sizeof(EdgeNode));
		 e->adjvex=i;
		 e->weight=weight;
		 e->next=G->adjList[j].firstedge;
		 G->adjList[j].firstedge=e;
		 G->adjList[j].in++;
    }
}
bool TopologicalSort(GraphAdjList *GL){
     EdgeNode *e;
     stack <int> stk;
     int i,j,temp,count=0;
     for(i=0;i<GL->numVertexes;i++)
         if(GL->adjList[i].in==0)
            stk.push(i);
     while(!stk.empty()){
           temp=stk.top();
           stk.pop();
           printf("%d -> ",GL->adjList[temp].data);
           count++;
           for(e=GL->adjList[temp].firstedge;e;e=e->next){
               j=e->adjvex;
               if(!(--GL->adjList[j].in))
                  stk.push(j);
           }
     }
     if(count<GL->numVertexes)
        return false;
     return true;
}    
void PrintALGraph(GraphAdjList *G){
     int i;
     EdgeNode *e;
     for(i=0;i<G->numVertexes;i++){
         printf("%d  ",G->adjList[i].data);
         if(G->adjList[i].firstedge){        
            e=G->adjList[i].firstedge;
            while(e){
                  printf("%d  ",e->adjvex);
                  e=e->next;
            }
         }
         printf("\n");
     }
}
int main(){
    GraphAdjList G;
    CreatALGraph(&G);
    PrintALGraph(&G);
    if(TopologicalSort(&G))
       printf("拓扑排序成功\n");
    else
       printf("拓扑排序失败\n");
    system("pause");
    return 0;
}
