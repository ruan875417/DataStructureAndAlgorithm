
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
struct Point{
       int rowx,coly;
       Point(int x,int y){
             rowx=x;
             coly=y;
       }
};
////////////////////////////////////////////////////////////////////
class OilDeposits{
      private:
            int row;
            int col;
            int count;
            char grid[102][102];
            bool visited[102][102];
            queue <Point> que;
            void bfs(int rw,int cl);
      public:
             void initial(int m,int n);
             void readCase();
             void compute();
             void output();
};
void OilDeposits::initial(int m,int n){
     row=m;
     col=n;
     count=0;
     memset(grid,'*',sizeof(grid));
     memset(visited,false,sizeof(visited));
}
void OilDeposits::readCase(){
     for(int i=1;i<=row;i++){
         for(int j=1;j<=col;j++){
             cin>>grid[i][j];
         }
     }
}   
void OilDeposits::bfs(int rw,int cl){
     Point point(rw,cl);
     que.push(point);
     visited[rw][cl]=true;
     while(!que.empty()){
           Point curPoint=que.front();
           que.pop();
           for(int i=0;i<8;i++){
                Point nextPoint(curPoint.rowx+dir[i][0],curPoint.coly+dir[i][1]);
                if(visited[nextPoint.rowx][nextPoint.coly]==false&&grid[nextPoint.rowx][nextPoint.coly]=='@'){
                   que.push(nextPoint);
                   visited[nextPoint.rowx][nextPoint.coly]=true;                                                                                                               
                }
           }
     }       
}              
void OilDeposits::compute(){
     for(int i=1;i<=row;i++){
         for(int j=1;j<=col;j++){
             if(visited[i][j]==false&&grid[i][j]=='@'){
                  bfs(i,j);
                  count++;
             }
         }
     }
}
void OilDeposits::output(){
       cout<<count++<<endl;
}
////////////////////////////////////////////////////////////////////
int main(){
    int m,n;
    OilDeposits x;
    while(cin>>m>>n&&!(m==0&&n==0)){
         x.initial(m,n);
         x.readCase();
         x.compute();
         x.output();
    }
    system("pause");
    return 0;
}
