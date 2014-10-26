#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct{
        int data;
        int cur;
}Component,StaticLinkList[MAXSIZE];
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:��ʼ������������һ���յľ�̬����\n");
	 printf("2:�жϸþ�̬�����Ƿ�Ϊ�գ��շ���1,���򷵻�0\n");
	 printf("3:����һ��������������̬����\n");
	 printf("4:�����þ�̬����\n");
	 printf("5:����̬�������\n");
	 printf("6:�ھ�̬�����е�i��Ԫ�ز�����Ԫ��e\n");
	 printf("7:�ھ�̬������ɾ����i��Ԫ�أ�����e������ֵ\n");
	 printf("0:�˳��˵�\n"); 
     printf("----------------------------------------------------------------\n");
}
int InitList(StaticLinkList space){
      int i;
      for(i=0;i<MAXSIZE;i++)
          space[i].cur=i+1;
      space[MAXSIZE-1].cur=0;
      return 1;
}   
int ListEmpty(StaticLinkList space){
       if(space[MAXSIZE-1].cur==0)
          return 1;
       else 
          return 0;
} 
int Create(StaticLinkList space,int n){
       printf("������%d��������",n);
       int d;
       for(int i=1;i<=n;i++){
           scanf("%d",&d);
           space[i].data=d;
           space[i].cur=i+1;
       }
       space[n].cur=0;
       space[0].cur=n+1;
       space[MAXSIZE-1].cur=1;
       return 1;
}  
void ListTraverse(StaticLinkList space){
       int next=space[MAXSIZE-1].cur;
       while(space[next].cur){
           printf("%d ",space[next].data);
           next=space[next].cur;
       }
       printf("%d\n",space[next].data);
} 
int ClearList(StaticLinkList space){ 
    int next=space[MAXSIZE-1].cur;
    for(int i=1;i<space[0].cur;i++){
        space[next].data=0;
        next=space[next].cur;
    }
    for(int i=0;i<MAXSIZE;i++)
          space[i].cur=i+1;
    space[MAXSIZE-1].cur=0;
    return 1;
}
int ListLength(StaticLinkList space){
    int i=space[MAXSIZE-1].cur;
    int j=0;
    while(i){
          i=space[i].cur;
          j++;
    }
    return j;
}
int Malloc_SLL(StaticLinkList space){
    int i=space[0].cur;
    if(space[0].cur)
       space[0].cur=space[i].cur;
    return i;
}
int ListInsert(StaticLinkList space,int i,int e){  
       int j,k,l;
       k=MAXSIZE-1;
       if(i<1||i>ListLength(space)+1)
          return 0;
       j=Malloc_SLL(space);
       if(j){
          space[j].data=e;
          for(l=1;l<=i-1;l++)
              k=space[k].cur;
          space[j].cur=space[k].cur;
          space[k].cur=j;              
          return 1;
       }
       return 0;
}
void Free_SSL(StaticLinkList space,int k){
     space[k].cur=space[0].cur;
     space[0].cur=k;
}
int ListDelete(StaticLinkList space,int i,int *e){  
       int j,k;
       if(i<1||i>ListLength(space))
          return 0;
       k=MAXSIZE-1;
       for(j=1;j<=i-1;j++)
           k=space[k].cur;
       j=space[k].cur;
       *e=space[j].data;
       space[k].cur=space[j].cur;
       Free_SSL(space,j);
       return 1;
}
int main(){
    int choose;
    int i,e,n;
    bool flag=true;
    StaticLinkList List;
    while(flag){
         menu();
         printf("��ѡ��Ҫ���еĲ�����");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 if(InitList(List))
                    printf("��ʼ����̬����ɹ���\n");
                 break;
            case 2:
                 printf("%d\n",ListEmpty(List));
                 break; 
           case 3:
                 printf("������˳���˳���Ԫ�ظ�����");
                 scanf("%d",&n);
                 if(Create(List,n))
                    printf("������̬����ɹ���\n");
                 break;               
           case 4:
                  ListTraverse(List);
                  break;
           case 5:
                  if(ClearList(List))
                      printf("��̬������ճɹ�\n");                
                  break;
            case 6:
                  printf("���������λ��i����Ԫ��e��");
                  scanf("%d%d",&i,&e);
                  if(ListInsert(List,i,e))
                     printf("����ɹ�\n"); 
                  else
                     printf("����ʧ��\n");
                  break; 
           case 7:
                  printf("������ɾ��λ��i��");
                  scanf("%d",&i);
                  if(ListDelete(List,i,&e))
                     printf("ɾ���ɹ���ɾ����ֵΪ%d\n",e); 
                  else
                     printf("ɾ��ʧ��\n");
                  break;
            case 0:
                  flag=false;
                  break; 
         } 
    } 
    return 0;
}
