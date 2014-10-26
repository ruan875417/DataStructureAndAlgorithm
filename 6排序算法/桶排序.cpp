#include<iostream>  
#include<malloc.h>  
using namespace std;

typedef struct node
{
    int key;
    struct node* next;
}keyNode;
void bucket_sort(int keys[],int size,int bucket_size)
{
     keyNode** bucket_table=(keyNode**)malloc(bucket_size*sizeof(keyNode));
     for(int i=0;i<bucket_size;i++)
     {
        bucket_table[i]=(keyNode*)malloc(sizeof(keyNode));
        bucket_table[i]->key=0;
        bucket_table[i]->next=NULL;
     }
     for(int i=0;i<size;i++)
     {
        keyNode* node=(keyNode*)malloc(sizeof(keyNode));
        node->key=keys[i];
        node->next=NULL;
        int index=keys[i]/10;
        keyNode* p=bucket_table[index];
        if(p->key==0)
        {
           bucket_table[index]->next=node;
           (bucket_table[index]->key)++;
        }
        else
        {
            while(p->next!=NULL&&p->next->key<=node->key)
                  p=p->next;
            node->next=p->next;
            p->next=node;
            (bucket_table[index]->key)++; 
        }
     }
      for(int i=0;i<bucket_size;i++)  
        for(keyNode *k=bucket_table[i]->next;k!=NULL;k=k->next)  
            cout<<k->key<<" ";  
    cout<<endl;  
}
int main(){  
    int raw[]={49,38,32,36,37,38,34,55};     
    int size=sizeof(raw)/sizeof(int);     
    bucket_sort(raw,size,10);  
    system("pause");
    return 0;
}
