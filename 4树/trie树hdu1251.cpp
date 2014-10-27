#include<iostream>
#include<cstring>
using namespace std;
/////////////////////////////////////////////////
struct TrieNode{
       TrieNode *next[26];
       int num;
};
////////////////////////////////////////////////////////
class Trie{
      private:
         TrieNode *root;
      public:
         void initial();
         void readCase();
         void insert(char *s);
         void search();
};
void Trie::initial(){
     root=(TrieNode *)malloc(sizeof(TrieNode));
     for(int i=0;i<26;i++)
         root->next[i]=NULL; 
     root->num=0;    
}
void Trie::readCase(){
     char str[12];
     while(gets(str)&&str[0]!='\0'){
           insert(str);
     }
}
void Trie::insert(char *s){
     if(root==NULL||*s=='\0')
        return ;
     TrieNode *p=root;
     while(*s!='\0'){
           if(p->next[*s-'a']==NULL){
              TrieNode *temp=(TrieNode *)malloc(sizeof(TrieNode));
              for(int i=0;i<26;i++)
                  temp->next[i]=NULL;
              temp->num=0;
              p->next[*s-'a']=temp;
           }
           p->next[*s-'a']->num++;
           p=p->next[*s-'a'];
           s++;
     }
}
void Trie::search(){
     char str[12];
     while(scanf("%s",str)!=EOF){
           TrieNode *p=root;   
           char *s=str;
           while(p!=NULL&&*s!='\0'){
                 p=p->next[*s-'a'];
                 s++;
           }   
           if(p==NULL)
              printf("0\n");
           else
              printf("%d\n",p->num);
     }  
}
/////////////////////////////////////////////////////////////
int main(){
    Trie x;
    x.initial();
    x.readCase();
    x.search();
    system("pause");
    return 0;
}
