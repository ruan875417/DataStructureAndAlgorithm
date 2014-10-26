#include "stdio.h"    
#include "stdlib.h"   
#define max 100
typedef int VertexType; //顶点类型
typedef int EdgeType; //边的权值类型
typedef struct EdgeNode{//边表结点 
        int adjvex;//邻接点域 
        EdgeType weight;// 权值 
        struct EdgeNode *next;//指向下一个邻接点 
}EdgeNode;
typedef struct VertexNode{//顶点表结点 
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
         G->adjList[i].firstedge=NULL;
     }
     for(k=0;k<G->numEdges;k++){
         printf("输入边(vi,vj)上的顶点序号和权值:\n");
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
    }
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
    system("pause");
    return 0;
}
