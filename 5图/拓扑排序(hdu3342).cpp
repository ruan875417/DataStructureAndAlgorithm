
#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
class LegalorNot{
      private:
         int numOfMember;
         int numOfTest;
         vector <int> vec[105];
         int in[105];
      public:
         void initial(int m,int n);
         void build();
         bool tuopo();
         void output();
};
void LegalorNot::initial(int m,int n){
     memset(in,0,sizeof(in));
     for(int i=0;i<105;i++)
         vec[i].clear();
     numOfMember=m;
     numOfTest=n;
}
void LegalorNot::build(){
     int m,n;
     for(int i=0;i<numOfTest;i++){
         cin>>m>>n;
         in[n]++;
         vec[m].push_back(n);
     }
}
bool LegalorNot::tuopo(){
     stack <int> stk;
     int count=0;
     for(int i=0;i<numOfMember;i++)
        if(in[i]==0)
            stk.push(i);
     while(!stk.empty()){
           int temp=stk.top();
           stk.pop();
           count++;
           for(int i=0;i<vec[temp].size();i++){
               in[vec[temp][i]]--;
               if(in[vec[temp][i]]==0)
                  stk.push(vec[temp][i]);
           }
     }
     if(count==numOfMember)
        return true;
     return false;
}
void LegalorNot::output(){
     if(tuopo())
        cout<<"YES"<<endl;
     else 
        cout<<"NO"<<endl;
}
int main(){
    LegalorNot x;
    int m,n;
    while(cin>>m>>n&&(m||n)){
          x.initial(m,n);
          x.build();
          x.output();
    }
    system("pause");
    return 0;
}
