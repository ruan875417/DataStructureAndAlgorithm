
#include<iostream>
#include<cstring>
#define max 10000
using namespace std;
////////////////////////////////////////////////////////////////////
class Hdu1233{
      private:
           int path[101][101];
           int distance[101];
           bool visited[101];
           int numberOfVillage;
           int minLength;
      public:
           void initial(int n);
           void readCase();
           void prim(int n);
           void compute();
           void output();
};
void Hdu1233::initial(int n){
     memset(path,10000,sizeof(path));
     memset(distance,10000,sizeof(distance));
     memset(visited,false,sizeof(visited));
     minLength=0;
     numberOfVillage=n;
}
void Hdu1233::readCase(){
     int number=numberOfVillage*(numberOfVillage-1)/2;
     int v1,v2,l;
     for(int i=0;i<number;i++){
         scanf("%d%d%d",&v1,&v2,&l);
         path[v1][v2]=path[v2][v1]=l;
     }
}
void Hdu1233::prim(int n){
     int min;
     int k;
     int i,j;
     visited[n]=true;/* 标记1号节点加入生成树 */
     for(i=1;i<=numberOfVillage;i++){
         /* 最短距离初始化为其他节点到1号节点的距离 */
         distance[i]=path[n][i];
     }
     /* n个节点至少需要n-1条边构成最小生成树 */
     for(i=2;i<=numberOfVillage;i++){
         min=max;
         /* 找满足条件的最小权值边的节点k*/
         for(j=1;j<=numberOfVillage;j++){ 
             if(min>distance[j]&&!visited[j]){
                   min=distance[j];
                   k=j;
              }
         }
         /* 累加权值 */
         minLength+=min;
         visited[k]=true;
         /* 更新当前节点k到其他节点的权值 */
         for(j=1;j<=numberOfVillage;j++){
             if(distance[j]>path[k][j]&&!visited[j]){
                /* 更新权值信息 */
                  distance[j]=path[k][j];
             }
         }
     }
}
void Hdu1233::compute(){
     prim(1);                 
}
void Hdu1233::output(){
     printf("%d\n",minLength);
}
//////////////////////////////////////////////////////////////////////////////
int main(){
    int n;
    Hdu1233 x;
    while(scanf("%d",&n)&&n){
          x.initial(n);
          x.readCase();
          x.compute();
          x.output();
    }
    system("pause");
    return 0;
}
