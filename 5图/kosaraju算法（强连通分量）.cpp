
#include<iostream>
using namespace std;
///////////////////////////////////////////
class Kosaraju{
      private:
          bool map1[101][101]; //存放原图关系 
          bool map2[101][101]; //存放逆图关系 
          bool visited[101];//是否遍历过 
          int f[101];//遍历完成时间戳 
          int time;//时间戳 
          int numOfNode;//节点数量
          int numOfEdge;//边数量   
      public:
          void initial(int m,int n);
          void readCase();
          void Firstly_DFS(int x);   //第一次深搜，计算出各个点完成时间戳f[x] 
          void Inverse();  //求逆图 
          void Secondly_DFS(int x);
          void Strongly_Connected_Components();  
};
///////////////////////////////////////////////////// 
void Kosaraju::initial(int m,int n)
{
     memset(map1,0,sizeof(map1));
     memset(visited,false,sizeof(visited));
     memset(f,0,sizeof(f));
     time=0;
     numOfNode=m;
     numOfEdge=n;
}
void Kosaraju::readCase()
{
    int u,v;
    for(int i=0;i<numOfEdge;i++){
          cin>>u>>v;
          map1[u][v]=1;
    }
}
void Kosaraju::Firstly_DFS(int x){
     visited[x]=true;
     time++;
     for(int i=0;i<numOfNode;i++){
         if(map1[x][i]&&!visited[i])
            Firstly_DFS(i);
     } 
     f[x]=++time;
     cout<<x<<"  "<<f[x]<<endl;
}
void Kosaraju::Inverse(){
     for(int i = 0; i <numOfNode; i++) {
         for (int j = 0; j <numOfNode; j++){
              map2[i][j] = map1[i][j];
              if (map1[i][j] && !map1[j][i])
                  map2[i][j] = 0;
              if (!map1[i][j] && map1[j][i])
                map2[i][j] = 1;
         }
     }
} 
void Kosaraju::Secondly_DFS(int x) {  //第二次深搜，找出强连通分量 
  visited[x] = 1;
  printf("%d ", x);  //将同一个强连通分量的节点在同一行输出 
  for (int i = 0; i <numOfNode; i++) {
      if (map2[x][i] && !visited[i])
        Secondly_DFS(i);
  }
}
void Kosaraju::Strongly_Connected_Components() {   
  for (int i = 0; i <numOfNode; i++) {  //对每一个未遍历节点进行深搜 
      if (!visited[i]) {
        Firstly_DFS(i);
      }
  }
  memset(visited, 0, sizeof(visited));
  Inverse();
  while (1) {
      int max = -1, v;
    //找出时间戳最大的点 
      for (int j = 0; j < numOfNode; j++) {
        if (!visited[j] && f[j] > max) {
          max = f[j];
          v = j;
        }
      }
      //若找不到，说明所有强连通分量已经全部找出,否则进行第二次深搜 
      if (max == -1)
        break;
      Secondly_DFS(v);
      printf("\n");
  }
}
//////////////////////////////////////////////////////
int main()
{
     int m,n;
     Kosaraju x;
     while(cin>>m>>n&&!(m==0&&n==0)){
         x.initial(m,n);
         x.readCase();
         x.Strongly_Connected_Components();
    }
}
