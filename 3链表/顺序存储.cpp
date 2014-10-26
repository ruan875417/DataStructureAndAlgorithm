#include<stdio.h>
#include<stdlib.h>
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:初始化操作，建立一个空的顺序表\n");
	 printf("2:判断该顺序表是否为空，空返回1,否则返回0\n");
	 printf("3:输入一组整数，建立非空顺序表\n");
	 printf("4:遍历该顺序表\n");
	 printf("5:将线性表清空\n");
	 printf("6:将线性表中的第i个位置元素返回给e\n");
	 printf("7:线性表中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功，否则返回0表示失败\n");
	 printf("8:在线性表的第i个位置插入新元素e\n");
     printf("9:在线性表的第i个位置删除元素，并用e返回其值\n");
     printf("10:求两个线性表的并集\n"); 
     printf("11:归并两个非递减的顺序表\n");
	 printf("0:退出菜单\n"); 
     printf("----------------------------------------------------------------\n");
}
typedef struct{
        int *data;
        int length;
}SqList;
SqList *InitList(SqList *List){
       List=(SqList *)malloc(sizeof(SqList));
       List->length=0;
       return List;
}   
int ListEmpty(SqList *List){
       if(List->length==0)
          return 1;
       else 
          return 0;
}   
SqList *Create(SqList *List,int n){
       printf("请输入%d个整数：",n);
       List->data=(int *)malloc(sizeof(int)*20);
       for(int i=0;i<n;i++){
           scanf("%d",&List->data[i]);
       }
       List->length=n;
       return List;
}     
void ListTraverse(SqList *List){
       if(List->length)
          printf("%d",List->data[0]);
       for(int i=1;i<List->length;i++){
           printf(" %d",List->data[i]);
       }
       printf("\n");
}  
SqList *ClearList(SqList *List){  
       for(int i=0;i<List->length;i++){
           List->data[i]=0;
       }
       List->length=0;
}
int GetElem(SqList *List,int i,int *e){
    if(List->length==0||i<1||i>List->length)
       return 0;
    *e=List->data[i-1];
    return 1;
} 
int LocateElem(SqList *List,int e){
    for(int i=0;i<List->length;i++){
        if(List->data[i]==e){
           return i+1;
           break;
        }
    }
    return 0;
} 
int ListInsert(SqList *List,int i,int e){  
       if(i<1||i>List->length+1)
          return 0;
       if(List->length==20)
          return 0;
       for(int j=List->length-1;j>=i-1;j--){
           List->data[j+1]=List->data[j];
       }
       List->data[i-1]=e;
       List->length++;
       return 1;
}
int ListDelete(SqList *List,int i,int *e){  
       if(i<1||i>List->length)
          return 0;
       *e=List->data[i-1];
       for(int j=i;j<=List->length-1;j++){
           List->data[j-1]=List->data[j];
       }
       List->length--;
       return 1;
}
void ListUnion(SqList *List,SqList *Listb){
     int e; 
     int alength=List->length;
     int blength=Listb->length;
     printf("%d\n",List->length); 
     for(int i=1;i<=blength;i++){
        GetElem(Listb,i,&e);
        if(!LocateElem(List,e)){
           ListInsert(List,++alength,e);   
        }
     }
           
}
void ListMerge(SqList *Listb,SqList *Listc,SqList *List){
     List->data=(int *)malloc(sizeof(int)*20);
     List->length=Listb->length+Listc->length;
     int *pb=Listb->data;
     int *pc=Listc->data;
     int *pa=List->data;
     int *pbLast=pb+Listb->length-1;
     int *pcLast=pc+Listc->length-1;
     while(pb<=pbLast&&pc<=pcLast){
         if(*pb<=*pc)
            *pa++=*pc++;
         else
            *pa++=*pb++;
     }
     while(pb<=pbLast) *pa++=*pb++;
     while(pc<=pcLast) *pa++=*pc++;
}
int main(){
    int choose;
    int i,e,n;
    bool flag=true;
    SqList *List;
    SqList *Listb;
    SqList *Listc;
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
                 List=Create(List,n);
                 break;
            case 4:
                 ListTraverse(List);
                 break;
            case 5:
                 List=ClearList(List);
                 break;
            case 6:
                 scanf("%d",&i);
                 if(GetElem(List,i,&e))
                    printf("顺序表中第%d个元素为%d\n",i,e);
                 else
                    printf("顺序表元素个数小于输入值或输入值小于1\n");
                 break;
             case 7:
                  printf("请输入给定值：");
                  scanf("%d",&e);
                  printf("给定值%d的位置是%d\n",e,LocateElem(List,e));
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
                  printf("请输入第二个顺序表元素个数：");
                  scanf("%d",&n);
                  Listb=Create(Listb,n);
                  ListUnion(List,Listb);
                  break;
            case 11:
                  Listb=InitList(Listb);
                  printf("请输入第一个非递减顺序表元素个数：");
                  scanf("%d",&n);
                  Listb=Create(Listb,n);
                  Listc=InitList(Listc);
                  printf("请输入第二个非递减顺序表元素个数：");
                  scanf("%d",&n);
                  Listc=Create(Listc,n);
                  List=InitList(List);
                  ListMerge(Listb,Listc,List);
                  break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
