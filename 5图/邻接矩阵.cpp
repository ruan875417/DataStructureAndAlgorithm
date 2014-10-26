#include<stdio.h>
#include<stdlib.h>
#define max 10000
struct MGraph{
       int vexs[100];
       int arc[100][100];
       int numVertexes,numEdges;
};
void CreatMGraph(MGraph *G){
     int i,j,k,w;
     printf("请输入图的顶点数和边数：\n");
     scanf("%d%d",&G->numVertexes,&G->numEdges);
     printf("请输入图的顶点：\n");
     for(i=0;i<G->numVertexes;i++)
         scanf("%d",&G->vexs[i]);
      for(i=0;i<100;i++)
           for(j=0;j<100;j++)
               G->arc[i][j]=max;
      for(i=0;i<G->numEdges;i++){
          printf("输入边（vj，vk）上的上标j，下标k和权w：\n");
          scanf("%d%d%d",&j,&k,&w);
          G->arc[j][k]=G->arc[k][j]=w;
      }
}
void PrintMraph(MGraph *G){
     int i,j;
     printf("图的顶点:");
     for(i=0;i<G->numVertexes;i++)
         printf("%d  ",G->vexs[i]);
     printf("\n");
     for(i=0;i<100;i++)
         for(j=0;j<100;j++)
             if(G->arc[i][j]!=max)
                printf("输入边（vj，vk）上的上标%d，下标%d和权%d：\n",i,j,G->arc[i][j]);
}   
int main(){
    MGraph G;
    CreatMGraph(&G);
    PrintMraph(&G);
    system("pause");
    return 0;
}
