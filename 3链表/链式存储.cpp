#include<stdio.h>
#include<stdlib.h>
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:初始化操作，建立一个空的链表\n");
	 printf("2:判断该链表是否为空，空返回1,否则返回0\n");
	 printf("3:输入一组整数，建立非空链表(头插法）\n");
	 printf("4:输入一组整数，建立非空链表(尾插法）\n");
	 printf("5:遍历该链表\n");
	 printf("6:将链表清空\n");
	 printf("7:将链表中的第i个位置元素返回给e\n");
	 printf("8:在链表的第i个位置插入新元素e\n");
     printf("9:在链表的第i个位置删除元素，并用e返回其值\n");
     printf("10:归并两个非递减的链表\n"); 
     printf("11:把单向链表中的元素逆置\n");
     printf("12:在单向链表中删除所有的偶数元素结点\n");
	 printf("0:退出菜单\n"); 
     printf("----------------------------------------------------------------\n");
}
struct Node{
        int data;
        Node *next;
};
Node *InitList(Node *List){
       List=(Node *)malloc(sizeof(Node));
       List->next=NULL;
       return List;
}   
int ListEmpty(Node *List){
       if(List->next==NULL)
          return 1;
       else 
          return 0;
} 
Node *CreateHead(Node *List,int n){
       printf("请输入%d个整数：",n);
       for(int i=0;i<n;i++){
           Node *p=(Node *)malloc(sizeof(Node));
           scanf("%d",&p->data);
           p->next=List->next;
           List->next=p;
       }
       return List;
}       
Node *CreateTail(Node *List,int n){
       printf("请输入%d个整数：",n);
       Node *q=List;
       for(int i=0;i<n;i++){
           Node *p=(Node *)malloc(sizeof(Node));
           scanf("%d",&p->data);
           p->next=NULL;
           q->next=p;
           q=p;
       }
       return List;
}     
void ListTraverse(Node *List){
       Node *p=List->next;
       while(p){
           printf("%d ",p->data);
           p=p->next;
       }
       printf("\n");
}  
Node *ClearList(Node *List){ 
       Node *p=List->next; 
       Node *q=NULL;
       while(p){
            q=p->next;
            free(p);
            p=q;
       }
       List->next=NULL;
}
int GetElem(Node *List,int i,int *e){
    Node *p=List->next;
    int j=1;
    while(p&&j<i){
          p=p->next;
          j++;
    }
    if(!p||j>i)
       return 0;
    *e=p->data;
    return 1;
} 
int ListInsert(Node *List,int i,int e){  
       Node *p=List,*s;
       int j=1;
       while(p&&j<i){
             p=p->next;
             j++;
       }
       if(!p||j>i)
          return 0;
       s=(Node *)malloc(sizeof(Node));
       s->data=e;
       s->next=p->next;
       p->next=s;
       return 1;
}
int ListDelete(Node *List,int i,int *e){  
       Node *p=List,*q;
       int j=1;
       while(p->next&&j<i){
             p=p->next;
             j++;
       }
       if(!p->next||j>i)
          return 0;
       q=p->next;
       p->next=q->next;
       *e=q->data;
       free(q);
       return 1;
}
void ListMerge(Node *Listb,Node *Listc,Node *List){
     Node *pb=Listb->next;
     Node *pc=Listc->next;
     Node *pa=List;
     while(pb&&pc){
         if(pb->data<pc->data){
            pa->next=pc;
            pa=pc;
            pc=pc->next;
         }else{
            pa->next=pb;
            pa=pb;
            pb=pb->next;
         }
     }
     pa->next=pb?pb:pc;
     free(Listb);
     free(Listc);
}
void ListInvert(Node *List){   
     Node *p=List->next,*q=NULL,*s;
     while(p){
           s=q;
           q=p;
           p=p->next;
           q->next=s;
     }
     List->next=q;
     printf("元素逆置后的单链表为:\n");
     ListTraverse(List);
}
void ListOdd(Node *List){
     Node *p=List,*q=List->next;
     while(q){
           if(q->data%2==0){
              p->next=q->next;
              free(q);
              q=p->next;
           }else{
              p=q;
              q=q->next;
           }
     }
} 
void ListSort(Node *List){
     Node *s=List;
     Node *p=List->next;
     Node *q=p->next,*r;
     while(q){
           if(p->data<q->data){
              s->next=q;
              r=q->next;
              q->next=p;
              p->next=r;
              q=r;
           }else{
              p=q;
              q=q->next;
           }
     }
}
int main(){
    int choose;
    int i,e,n;
    bool flag=true;
    Node *List;
    Node *Listb;
    Node *Listc;
    while(flag){
         menu();
         printf("请选择要进行的操作：");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 List=InitList(List);
                 break;
            case 2:
                 printf("%d\n",ListEmpty(List));
                 break; 
           case 3:
                 printf("请输入顺序表顺序表元素个数：");
                 scanf("%d",&n);
                 List=CreateHead(List,n);
                 break;               
           case 4:
                 printf("请输入链表元素个数：");
                 scanf("%d",&n);
                 List=CreateTail(List,n);
                 break;
           case 5:
                 ListTraverse(List);
                 break;
           case 6:
                 List=ClearList(List);
                 break;
           case 7:
                 scanf("%d",&i);
                 if(GetElem(List,i,&e))
                    printf("链表中第%d个元素为%d\n",i,e);
                 else
                    printf("链表元素个数小于输入值或输入值小于1\n");
                 break;
            case 8:
                 printf("请输入插入位置i和新元素e：");
                 scanf("%d%d",&i,&e);
                 if(ListInsert(List,i,e))
                     printf("插入成功\n"); 
                 else
                     printf("插入失败\n");
                 break;  
           case 9: 
                  printf("请输入删除位置i：");
                  scanf("%d",&i);
                  if(ListDelete(List,i,&e))
                     printf("删除成功，删除的值为%d\n",e); 
                  else
                     printf("删除失败\n");
                  break;
             case 10:
                  Listb=InitList(Listb);
                  printf("请输入第一个非递减链表元素个数：");
                  scanf("%d",&n);
                  Listb=CreateTail(Listb,n);
                  Listc=InitList(Listc);
                  printf("请输入第二个非递减链表元素个数：");
                  scanf("%d",&n);
                  Listc=CreateTail(Listc,n);
                  List=InitList(List);
                  ListMerge(Listb,Listc,List);
                  break;                  
            case 11:
                  ListInvert(List);
                  break;
            case 12: 
                  ListOdd(List);
                  break;
            case 13:
                  ListSort(List);
                  break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
