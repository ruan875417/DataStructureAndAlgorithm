#include<iostream>
#include<cstring>
using namespace std;
///////////////////////////////////////////////////////////////////
struct TrieNode{
       bool isStr;
       int next[10];
}root[500000];
/////////////////////////////////////////////////////////////////
class Trie{
      private:
          int len;
      public:
          void initial();
          void readCase(int m);
          bool insert(char *s);
};
void Trie::initial(){
     len=0;
     int i;
     for(i=0;i<500000;i++){
         root[i].isStr=false;
         memset(root[i].next,0,sizeof(root[i].next));
     }     
}
void Trie::readCase(int m){
     int i;
     bool flag=false;
     char str[12];
     for(i=0;i<m;i++){
         getchar();
         scanf("%s",str);
         if(!flag){
            flag=insert(str);
         }
     }
     if(flag)
         cout<<"NO"<<endl;
     else
         cout<<"YES"<<endl;
}
bool Trie::insert(char *s){
     TrieNode *p=&root[0];
     while(*s!='\0'){
           if(p->next[*s-'0']==0){
              p->next[*s-'0']=++len;
           }
           if(p->isStr)
              return true;
           p=&root[p->next[*s-'0']];
           s++;
     } 
     p->isStr=true;
     for(int i=0;i<10;i++)
         if(p->next[i]!=0)//此单词为其它单词的前缀
              return true;
    return false;  
}
////////////////////////////////////////////////////////////////////////////
int main(){
    int t;
    Trie x;
    scanf("%d",&t);
          int m;
          while(t--){
                scanf("%d",&m);
                x.initial();
                x.readCase(m);
          }
    system("pause");
    return 0;
}
          
