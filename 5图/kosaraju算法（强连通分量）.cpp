
#include<iostream>
using namespace std;
///////////////////////////////////////////
class Kosaraju{
      private:
          bool map1[101][101]; //���ԭͼ��ϵ 
          bool map2[101][101]; //�����ͼ��ϵ 
          bool visited[101];//�Ƿ������ 
          int f[101];//�������ʱ��� 
          int time;//ʱ��� 
          int numOfNode;//�ڵ�����
          int numOfEdge;//������   
      public:
          void initial(int m,int n);
          void readCase();
          void Firstly_DFS(int x);   //��һ�����ѣ���������������ʱ���f[x] 
          void Inverse();  //����ͼ 
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
void Kosaraju::Secondly_DFS(int x) {  //�ڶ������ѣ��ҳ�ǿ��ͨ���� 
  visited[x] = 1;
  printf("%d ", x);  //��ͬһ��ǿ��ͨ�����Ľڵ���ͬһ����� 
  for (int i = 0; i <numOfNode; i++) {
      if (map2[x][i] && !visited[i])
        Secondly_DFS(i);
  }
}
void Kosaraju::Strongly_Connected_Components() {   
  for (int i = 0; i <numOfNode; i++) {  //��ÿһ��δ�����ڵ�������� 
      if (!visited[i]) {
        Firstly_DFS(i);
      }
  }
  memset(visited, 0, sizeof(visited));
  Inverse();
  while (1) {
      int max = -1, v;
    //�ҳ�ʱ������ĵ� 
      for (int j = 0; j < numOfNode; j++) {
        if (!visited[j] && f[j] > max) {
          max = f[j];
          v = j;
        }
      }
      //���Ҳ�����˵������ǿ��ͨ�����Ѿ�ȫ���ҳ�,������еڶ������� 
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
