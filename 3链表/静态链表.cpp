#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct{
        int data;
        int cur;
}Component,StaticLinkList[MAXSIZE];
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:初始化操作，建立一个空的静态链表\n");
	 printf("2:判断该静态链表是否为空，空返回1,否则返回0\n");
	 printf("3:输入一组整数，建立静态链表\n");
	 printf("4:遍历该静态链表\n");
	 printf("5:将静态链表清空\n");
	 printf("6:在静态链表中第i个元素插入新元素e\n");
	 printf("7:在静态链表中删除第i个元素，并用e返回其值\n");
	 printf("0:退出菜单\n"); 
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
       printf("请输入%d个整数：",n);
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
         printf("请选择要进行的操作：");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 if(InitList(List))
                    printf("初始化静态链表成功！\n");
                 break;
            case 2:
                 printf("%d\n",ListEmpty(List));
                 break; 
           case 3:
                 printf("请输入顺序表顺序表元素个数：");
                 scanf("%d",&n);
                 if(Create(List,n))
                    printf("建立静态链表成功！\n");
                 break;               
           case 4:
                  ListTraverse(List);
                  break;
           case 5:
                  if(ClearList(List))
                      printf("静态链表清空成功\n");                
                  break;
            case 6:
                  printf("请输入插入位置i和新元素e：");
                  scanf("%d%d",&i,&e);
                  if(ListInsert(List,i,e))
                     printf("插入成功\n"); 
                  else
                     printf("插入失败\n");
                  break; 
           case 7:
                  printf("请输入删除位置i：");
                  scanf("%d",&i);
                  if(ListDelete(List,i,&e))
                     printf("删除成功，删除的值为%d\n",e); 
                  else
                     printf("删除失败\n");
                  break;
            case 0:
                  flag=false;
                  break; 
         } 
    } 
    return 0;
}
