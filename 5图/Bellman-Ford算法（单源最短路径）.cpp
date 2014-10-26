#include<iostream>
using namespace std;
/////////////////////////////////////////////////////
const int maxNum = 100;
const int maxInt = 99999;
typedef struct Edge{
        int begin; //��� 
        int end;   //�յ� 
        int weight;//Ȩֵ 
}Edge;
/////////////////////////////////////////////////
class BellmanFord{
      private:
         int numOfNode; // �����
         int numOfEdge; // ����
         int source;  // Դ��
         Edge edge[maxNum];    // ����ߵ�ֵ
         int distance[maxNum]; // ��㵽Դ����С����
      public:
         void readCase();
         void relax(int u,int v,int w);
         bool Bellman_Ford();   
         void output();  
};
void BellmanFord::readCase(){
     cin>>numOfNode>>numOfEdge>>source;
     for(int i=1;i<=numOfNode;i++)
         distance[i]=maxInt;
     distance[source]=0;
     for(int i=1;i<=numOfEdge;i++)
     {
         cin>>edge[i].begin>>edge[i].end>>edge[i].weight;
         if(edge[i].begin==source) //ע���������ó�ʼ���
            distance[edge[i].end]=edge[i].weight;
     }
}
// �ɳڼ���
void BellmanFord::relax(int u,int v,int w){
     if(distance[v]>distance[u]+w)
        distance[v]=distance[u]+w;
}
bool BellmanFord::Bellman_Ford(){
     for(int i=1;i<numOfNode;i++)
         for(int j=1;j<=numOfEdge;j++)
             relax(edge[j].begin,edge[j].end,edge[j].weight);
     bool flag=true;
     // �ж��Ƿ��и���·
     for(int i=1;i<=numOfEdge;i++)
         if(distance[edge[i].end]>distance[edge[i].begin]+edge[i].weight)
         {
            flag=false;
            break;
          }
     return flag;     
}
void BellmanFord::output(){
     if(Bellman_Ford())
        for(int i=1;i<=numOfNode;i++)
           cout<<distance[i]<<endl;
     else
        cout<<"�и���"<<endl; 
}
////////////////////////////////////////////////////////////
int main(){
    BellmanFord bellmanFord;
    bellmanFord.readCase();
    bellmanFord.output();
    system("pause");
    return 0;
}
