#include "stdio.h"    
#include "stdlib.h"   
#define max 100
typedef int VertexType; //��������
typedef int EdgeType; //�ߵ�Ȩֵ����
typedef struct EdgeNode{//�߱��� 
        int adjvex;//�ڽӵ��� 
        EdgeType weight;// Ȩֵ 
        struct EdgeNode *next;//ָ����һ���ڽӵ� 
}EdgeNode;
typedef struct VertexNode{//������� 
        VertexType data;//������ 
        EdgeNode *firstedge;//�߱�ͷָ�� 
}vertexNode,AdjList[max];
typedef struct GraphAdjList{
        AdjList adjList;
        int numVertexes,numEdges;
}GraphAdjList;
void CreatALGraph(GraphAdjList *G){
     int i,j,k,weight;
     EdgeNode *e;
     printf("�����붥�����ͱ�����\n");
     scanf("%d%d",&G->numVertexes,&G->numEdges);
     for(i=0;i<G->numVertexes;i++){
         printf("�����붥�㣺");
         scanf("%d",&G->adjList[i].data);
         G->adjList[i].firstedge=NULL;
     }
     for(k=0;k<G->numEdges;k++){
         printf("�����(vi,vj)�ϵĶ�����ź�Ȩֵ:\n");
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
