#include "stdio.h"    
#include "stdlib.h" 
#include<stack>  
#define max 100
using namespace std;
typedef int VertexType; //��������
typedef int EdgeType; //�ߵ�Ȩֵ����
typedef struct EdgeNode{//�߱��� 
        int adjvex;//�ڽӵ��� 
        EdgeType weight;// Ȩֵ 
        struct EdgeNode *next;//ָ����һ���ڽӵ� 
}EdgeNode;
typedef struct VertexNode{//������� 
        int in;
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
         G->adjList[i].in=0;
         G->adjList[i].firstedge=NULL;
     }
     for(k=0;k<G->numEdges;k++){
         printf("�����<vi,vj>�ϵĶ�����ź�Ȩֵ:\n");
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
       printf("��������ɹ�\n");
    else
       printf("��������ʧ��\n");
    system("pause");
    return 0;
}
