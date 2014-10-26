#include <iostream>
#include <cstring>
using namespace std;
const int maxnum =100;
const int maxint =999999;
////////////////////////////////////////////////////////////////////
class Dij{
      private:
          int numOfNode;// ͼ�Ľ����
          int numOfEdge;// ͼ��·����
          bool s[maxnum]; // �ж��Ƿ��Ѵ���õ㵽S������
          int distance[maxnum];     // ��ʾ��ǰ�㵽Դ������·������
          int pre[maxnum];// ��¼��ǰ���ǰһ�����
          int path[maxnum][maxnum];// ��¼ͼ�������·������
      public:
          void initial(int m,int n);
          void readCase();
          void Dijkstra(int v,int end);
          void searchPath(int v,int end);
};
void Dij::initial(int m,int n){
     numOfNode=m;
     numOfEdge=n;
     memset(s,false,sizeof(s));
     for(int i=1;i<=numOfNode;i++){
         distance[i] = maxint;
         for(int j=1;j<=numOfNode;j++)
            path[i][j]=maxint; 
     }
}
void Dij::readCase(){
     int n1,n2,len;           
     for(int i=1;i<=numOfEdge;i++){
         cin>>n1>>n2>>len;
         if(len<path[n1][n2]){
            path[n1][n2]=path[n2][n1]=len;
        }
    }
}
void Dij::Dijkstra(int v,int end){
    int i,j;
    for(i=1;i<=numOfNode;i++){
        distance[i]=path[v][i];
        if(distance[i]==maxint)
            pre[i] = 0;
        else
            pre[i] = v;
    }
    distance[v]=0;
    s[v]=true;
    // ���ν�δ����S���ϵĽ���У�ȡdistance[]��Сֵ�Ľ�㣬������S��
	// һ��S����������V�ж��㣬distance[]�ͼ�¼�˴�Դ�㵽������������֮������·������
 // ע���Ǵӵڶ����ڵ㿪ʼ����һ��ΪԴ��
    for(i=2;i<=numOfNode;i++){
        int min=maxint;
        int u=v;
        // �ҳ���ǰδʹ�õĵ�j��distance[j]��Сֵ
        for(j=1;j<=numOfNode;j++)
            if((!s[j])&&distance[j]<min){
                u=j;
                min=distance[j];
            }
        s[u]=true; // ��ʾu���Ѵ���S������
        // ����distance[j]
        for(j=1;j<=numOfNode;j++)
            if((!s[j])&&path[u][j]<maxint){
                int newdist = distance[u]+path[u][j];
                if(newdist<distance[j]){
                    distance[j]=newdist;
                    pre[j]=u;
                }
            }
    }
    cout<<"Դ�㵽���һ����������·������: "<<distance[end]<<endl;
} 
// ���Ҵ�Դ��v���յ�u��·���������
void Dij::searchPath(int v,int end){
    int que[maxnum];
    int tot=1;
    que[tot]=end;
    tot++;
    int tmp=pre[end];
    while(tmp!=v){
        que[tot] =tmp;
        tot++;
        tmp = pre[tmp];
    }
    que[tot]=v;
    cout<<"Դ�㵽���һ�������·��Ϊ: ";
    for(int i=tot;i>=1;i--)
        if(i!= 1)
            cout << que[i] << " -> ";
        else
            cout << que[i] << endl;
}
////////////////////////////////////////////////////////////////
int main(){
    int n,line;
    Dij x;
    int start,end;
    while(cin>>n>>line){
          x.initial(n,line);
          x.readCase();
          cin>>start>>end;
          x.Dijkstra(start,end);
          x.searchPath(start,end);
    }
    system("pause");
    return 0;
}
