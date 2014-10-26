
#include<iostream>
#include<cstring>
using namespace std;
///////////////////////////////////////////////////////////////////////
class Street{
      private:
            int len[500][500];
            int country;
            int number;
            int start;
            int end;
      public:
            void initial(int n,int m);
            void readCase();
            void floyd();
            void output();
};
void Street::initial(int n,int m){
     memset(len,10000,sizeof(len));
     for(int i=0;i<500;i++){                   ///////注意自己对自己长度必须设为0 
        for(int j=0;j<500;j++){
            if(i==j){
                 len[i][j]=0;
            }
        }
     }
     country=n;
     number=m;
}
void Street::readCase(){
     int c1,c2,l;
     for(int i=0;i<number;i++){
         cin>>c1>>c2>>l;
         if(l<len[c1][c2]){
              len[c1][c2]=l;
              len[c2][c1]=l;
         }
     }
     cin>>start>>end;
}
void Street::floyd(){
     //注意循环的嵌套顺序
     for(int k=0;k<country;k++){
         for(int i=0;i<country;i++){
             for(int j=0;j<country;j++){
                  if(len[i][k]+len[k][j]<len[i][j]){
                      // 找到更短路径
                      len[i][j]=len[i][k]+len[k][j];
                  }
             }
         }
     }             
}
void Street::output(){
     if(len[end][start]<10000){
        cout<<len[start][end]<<endl;
     }else{
         cout<<-1<<endl;
     }
}
////////////////////////////////////////////////////////////////////
int main(){
    int n,m;
    Street s;
    while(cin>>n>>m){
          s.initial(n,m);
          s.readCase();
          s.floyd();
          s.output();
    }
    system("pause");
    return 0;
}
