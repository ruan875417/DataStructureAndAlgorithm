#include<iostream>
#include<cstdlib>
using namespace std;
///////////////////////////////////////////////////////////////////////
struct TrieNode{
       bool isStr;
       TrieNode *next[26];
};
/////////////////////////////////////////////////////////////////////
class Trie{
      private:
           TrieNode *root;
      public:
           void initial();
           void readCase(int m);
           void insert(char *str);
           int search(char *str);
           void compute();
           void del(TrieNode *rt);
};
void Trie::initial(){
     int i;
     root=(TrieNode *)malloc(sizeof(TrieNode));
     for(i=0;i<26;i++){
         root->next[i]=NULL;
     }
     root->isStr=false;
}
void Trie::readCase(int m){
     int i;
     char str[100];
     for(i=0;i<m;i++){
         getchar();
         scanf("%s",str);
         insert(str);
     }                
}
void Trie::insert(char *str){
     if(root==NULL||*str=='\0')
        return ;
     int i;
     TrieNode *p=root;
     while(*str!='\0'){
           if(p->next[*str-'a']==NULL){
              TrieNode *temp=(TrieNode *)malloc(sizeof(TrieNode));
              for(i=0;i<26;i++){
                  temp->next[i]=NULL;
              }
              temp->isStr=false;
              p->next[*str-'a']=temp;
              p=p->next[*str-'a'];
           }else{
              p=p->next[*str-'a'];
           }
           str++;
     }
     p->isStr=true;
}
int Trie::search(char *str){
    TrieNode *p=root;
    while(p!=NULL&&*str!='\0'){
          p=p->next[*str-'a'];
          str++;
    }
    return (p!=NULL&&p->isStr==true);
}
void Trie::compute(){
     int m,i;
     char str[100];
     scanf("%d",&m);
     for(i=0;i<m;i++){
         getchar();
         scanf("%s",str);
         if(search(str)==1)
             printf("YES\n"); 
         else   
             printf("NO\n");
     }       
     del(root);          
}
void Trie::del(TrieNode *rt){
     int i;
     for(i=0;i<26;i++)
         if(rt->next[i]!=NULL)
            del(rt->next[i]);
     free(rt);
}
////////////////////////////////////////////////////////////////////
int main(){
    int m;
    Trie x;
    while(cin>>m&&m){
          x.initial();
          x.readCase(m);
          x.compute();
    }
    system("pause");
    return 0;
}
