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
     printf("������ͼ�Ķ������ͱ�����\n");
     scanf("%d%d",&G->numVertexes,&G->numEdges);
     printf("������ͼ�Ķ��㣺\n");
     for(i=0;i<G->numVertexes;i++)
         scanf("%d",&G->vexs[i]);
      for(i=0;i<100;i++)
           for(j=0;j<100;j++)
               G->arc[i][j]=max;
      for(i=0;i<G->numEdges;i++){
          printf("����ߣ�vj��vk���ϵ��ϱ�j���±�k��Ȩw��\n");
          scanf("%d%d%d",&j,&k,&w);
          G->arc[j][k]=G->arc[k][j]=w;
      }
}
void PrintMraph(MGraph *G){
     int i,j;
     printf("ͼ�Ķ���:");
     for(i=0;i<G->numVertexes;i++)
         printf("%d  ",G->vexs[i]);
     printf("\n");
     for(i=0;i<100;i++)
         for(j=0;j<100;j++)
             if(G->arc[i][j]!=max)
                printf("����ߣ�vj��vk���ϵ��ϱ�%d���±�%d��Ȩ%d��\n",i,j,G->arc[i][j]);
}   
int main(){
    MGraph G;
    CreatMGraph(&G);
    PrintMraph(&G);
    system("pause");
    return 0;
}
