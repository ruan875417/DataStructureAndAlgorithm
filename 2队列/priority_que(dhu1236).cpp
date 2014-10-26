
#include<iostream>
#include<queue>
#include<string>
#include<map>
using namespace std;
///////////////////////////////////////////////////////////////////////
class Ranklist{
      private:
           int nuberOfStudent;
           int numberOfproblem;
           int passMark;
           int mark[15];
           priority_queue <int> paixu;
           int count;
           map <string,int> s;
           map <string,int>::iterator it;
      public:
           void initial();
           bool readCase();
           void compute();
           void output();
};
void Ranklist::initial(){
     if(!s.empty()){
         s.clear();
     }
     count=0;
}
bool Ranklist::readCase(){
     cin>>nuberOfStudent;
     if(nuberOfStudent==0){
        return false;
     }
     cin>>numberOfproblem>>passMark;   
     for(int i=1;i<=numberOfproblem;i++){ 
         cin>>mark[i];
     }
     return true;         
}
void Ranklist::compute(){   
     string name;
     int solvedProblem;
     int problemNumber;
     for(int i=0;i<nuberOfStudent;i++){ 
         cin>>name>>solvedProblem;
         int getMark=0;
         for(int j=0;j<solvedProblem;j++){
             cin>>problemNumber;
             getMark+=mark[problemNumber];
         }   
         if(getMark>=passMark){
              count++;
              s[name]=getMark;
              paixu.push(getMark);
         }
     }
}
void Ranklist::output(){
     map <string,int>::iterator itt;
     cout<<count<<endl;
     if(count){
        while(!paixu.empty()){
           map <string,int> ss; 
           for(it=s.begin();it!=s.end();it++){
               if(it->second==paixu.top()){
                  ss[it->first]=it->second;
               }
            }
            for(itt=ss.begin();itt!=ss.end();itt++){
                cout<<itt->first<<' '<<itt->second<<endl;
                 paixu.pop();
            }
        }
     }        
}
//////////////////////////////////////////////////////////////////////
int main(){
    Ranklist x;
    while(x.readCase()){
          x.initial();
          x.compute();
          x.output();
    }
    system("pause");
    return 0;
}
