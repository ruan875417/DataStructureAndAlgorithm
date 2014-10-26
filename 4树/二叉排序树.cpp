#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
        int data;
        struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//////////////////////////////////////////////////////////////////////////////
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:建立二叉排序树\n");
	 printf("2:二叉排序树的插入操作\n");
	 printf("3:二叉排序树有序输出：\n");
     printf("4:二叉排序树的删除操作\n");
	 printf("0:退出菜单\n"); 
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
bool searchBST(BiTree T,int key,BiTree f,BiTree *p){//T是二叉排序树,f指向T的双亲，开始调用时为NULL，p指向该数据元素结点 
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
     if((*p)->rchild==NULL){//右子树空只需重接左子树 
         q=*p;
         *p=(*p)->lchild;
         free(q);
     }else if((*p)->lchild==NULL){//左子树空只需重接右子树 
         q=*p;
         *p=(*p)->rchild;
         free(q);
     }else{
         q=*p;
         s=(*p)->lchild;
         while(s->rchild){
            q=s;
            s=s->rchild;
         }  //转左，然后向右到尽头
         (*p)->data=s->data;
         if(q!=*p)
            q->rchild=s->lchild; //重接*q的右子树
         else
            q->lchild=s->lchild;  //重接*q的右子树
         free(s);
     }
     return true;
}
///////////////////////////////////////////////////////////////////////////
bool deleteBST(BiTree *T,int key){
     if(!*T)//不存在关键字等于key的数据元素 
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
         printf("请选择要进行的操作：");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 int i; 
                 T=NULL;
                 for(int i=0;i<10;i++)
                     insertBST(&T,a[i]); 
                 break;
            case 2:
                 printf("请输入要插入的数：");
                 scanf("%d",&num);
                 if(insertBST(&T,num))
                    printf("插入数据成功！\n");
                 else
                    printf("要插入的数据已经存在\n"); 
                 break; 
           case 3:
                 order(T);
                 printf("\n"); 
                 break;               
           case 4:
                 printf("请输入删除的数：");
                 scanf("%d",&num);
                 if(deleteBST(&T,num))
                    printf("删除成功\n");
                 else
                    printf("不存在关键字等于key的数据元素 \n");
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
