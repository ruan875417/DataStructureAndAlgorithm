#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
        int data;
        struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//////////////////////////////////////////////////////////////////////////////
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:��������������\n");
	 printf("2:�����������Ĳ������\n");
	 printf("3:�������������������\n");
     printf("4:������������ɾ������\n");
	 printf("0:�˳��˵�\n"); 
     printf("----------------------------------------------------------------\n");
}
/////////////////////////////////////////////////////////
void order(BiTree T){
     if(T){
        order(T->lchild);
        printf(" %d",T->data);
        order(T->rchild);
     }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
bool searchBST(BiTree T,int key,BiTree f,BiTree *p){//T�Ƕ���������,fָ��T��˫�ף���ʼ����ʱΪNULL��pָ�������Ԫ�ؽ�� 
     if(!T){
        *p=f;
        return false;
     }else if(key==T->data){
        *p=T;
        return true;
     }else if(key<T->data)
        return searchBST(T->lchild,key,T,p);
     else
        return searchBST(T->rchild,key,T,p);
} 
////////////////////////////////////////////////////////////////////////////////////////////////////////
bool insertBST(BiTree *T,int key){
     BiTree p,s;
     if(!searchBST(*T,key,NULL,&p)){
         s=(BiTree)malloc(sizeof(BiTNode));
         s->data=key;
         s->lchild=s->rchild=NULL;
         if(!p)
            *T=s;
         else if(key<p->data)
            p->lchild=s;
         else
            p->rchild=s;
         return true;
     }else
         return false;
}
///////////////////////////////////////////////////////////////////////////////
bool Delete(BiTree *p){
     BiTree q,s;
     if((*p)->rchild==NULL){//��������ֻ���ؽ������� 
         q=*p;
         *p=(*p)->lchild;
         free(q);
     }else if((*p)->lchild==NULL){//��������ֻ���ؽ������� 
         q=*p;
         *p=(*p)->rchild;
         free(q);
     }else{
         q=*p;
         s=(*p)->lchild;
         while(s->rchild){
            q=s;
            s=s->rchild;
         }  //ת��Ȼ�����ҵ���ͷ
         (*p)->data=s->data;
         if(q!=*p)
            q->rchild=s->lchild; //�ؽ�*q��������
         else
            q->lchild=s->lchild;  //�ؽ�*q��������
         free(s);
     }
     return true;
}
///////////////////////////////////////////////////////////////////////////
bool deleteBST(BiTree *T,int key){
     if(!*T)//�����ڹؼ��ֵ���key������Ԫ�� 
        return false;
     else{
        if(key==(*T)->data)
           return Delete(T);
        else if(key<(*T)->data)
           return deleteBST(&(*T)->lchild,key);
        else
           return deleteBST(&(*T)->rchild,key);
     }
}
////////////////////////////////////////////////////////////////////////////////
int main(){
    int choose;
    int num;
    bool flag=true;
    int a[10]={45,56,24,89,67,84,56,39,64,55};
    BiTree T;
    while(flag){
         menu();
         printf("��ѡ��Ҫ���еĲ�����");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 int i; 
                 T=NULL;
                 for(int i=0;i<10;i++)
                     insertBST(&T,a[i]); 
                 break;
            case 2:
                 printf("������Ҫ���������");
                 scanf("%d",&num);
                 if(insertBST(&T,num))
                    printf("�������ݳɹ���\n");
                 else
                    printf("Ҫ����������Ѿ�����\n"); 
                 break; 
           case 3:
                 order(T);
                 printf("\n"); 
                 break;               
           case 4:
                 printf("������ɾ��������");
                 scanf("%d",&num);
                 if(deleteBST(&T,num))
                    printf("ɾ���ɹ�\n");
                 else
                    printf("�����ڹؼ��ֵ���key������Ԫ�� \n");
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
