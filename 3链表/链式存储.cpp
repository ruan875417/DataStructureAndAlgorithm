#include<stdio.h>
#include<stdlib.h>
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:��ʼ������������һ���յ�����\n");
	 printf("2:�жϸ������Ƿ�Ϊ�գ��շ���1,���򷵻�0\n");
	 printf("3:����һ�������������ǿ�����(ͷ�巨��\n");
	 printf("4:����һ�������������ǿ�����(β�巨��\n");
	 printf("5:����������\n");
	 printf("6:���������\n");
	 printf("7:�������еĵ�i��λ��Ԫ�ط��ظ�e\n");
	 printf("8:������ĵ�i��λ�ò�����Ԫ��e\n");
     printf("9:������ĵ�i��λ��ɾ��Ԫ�أ�����e������ֵ\n");
     printf("10:�鲢�����ǵݼ�������\n"); 
     printf("11:�ѵ��������е�Ԫ������\n");
     printf("12:�ڵ���������ɾ�����е�ż��Ԫ�ؽ��\n");
	 printf("0:�˳��˵�\n"); 
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
       printf("������%d��������",n);
       for(int i=0;i<n;i++){
           Node *p=(Node *)malloc(sizeof(Node));
           scanf("%d",&p->data);
           p->next=List->next;
           List->next=p;
       }
       return List;
}       
Node *CreateTail(Node *List,int n){
       printf("������%d��������",n);
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
     printf("Ԫ�����ú�ĵ�����Ϊ:\n");
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
         printf("��ѡ��Ҫ���еĲ�����");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 List=InitList(List);
                 break;
            case 2:
                 printf("%d\n",ListEmpty(List));
                 break; 
           case 3:
                 printf("������˳���˳���Ԫ�ظ�����");
                 scanf("%d",&n);
                 List=CreateHead(List,n);
                 break;               
           case 4:
                 printf("����������Ԫ�ظ�����");
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
                    printf("�����е�%d��Ԫ��Ϊ%d\n",i,e);
                 else
                    printf("����Ԫ�ظ���С������ֵ������ֵС��1\n");
                 break;
            case 8:
                 printf("���������λ��i����Ԫ��e��");
                 scanf("%d%d",&i,&e);
                 if(ListInsert(List,i,e))
                     printf("����ɹ�\n"); 
                 else
                     printf("����ʧ��\n");
                 break;  
           case 9: 
                  printf("������ɾ��λ��i��");
                  scanf("%d",&i);
                  if(ListDelete(List,i,&e))
                     printf("ɾ���ɹ���ɾ����ֵΪ%d\n",e); 
                  else
                     printf("ɾ��ʧ��\n");
                  break;
             case 10:
                  Listb=InitList(Listb);
                  printf("�������һ���ǵݼ�����Ԫ�ظ�����");
                  scanf("%d",&n);
                  Listb=CreateTail(Listb,n);
                  Listc=InitList(Listc);
                  printf("������ڶ����ǵݼ�����Ԫ�ظ�����");
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
