#include<stdio.h>
#include<stdlib.h>
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:��ʼ������������һ���յ�˳���\n");
	 printf("2:�жϸ�˳����Ƿ�Ϊ�գ��շ���1,���򷵻�0\n");
	 printf("3:����һ�������������ǿ�˳���\n");
	 printf("4:������˳���\n");
	 printf("5:�����Ա����\n");
	 printf("6:�����Ա��еĵ�i��λ��Ԫ�ط��ظ�e\n");
	 printf("7:���Ա��в��������ֵe��ȵ�Ԫ�أ�������ҳɹ������ظ�Ԫ���ڱ�����ű�ʾ�ɹ������򷵻�0��ʾʧ��\n");
	 printf("8:�����Ա�ĵ�i��λ�ò�����Ԫ��e\n");
     printf("9:�����Ա�ĵ�i��λ��ɾ��Ԫ�أ�����e������ֵ\n");
     printf("10:���������Ա�Ĳ���\n"); 
     printf("11:�鲢�����ǵݼ���˳���\n");
	 printf("0:�˳��˵�\n"); 
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
       printf("������%d��������",n);
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
                    printf("˳����е�%d��Ԫ��Ϊ%d\n",i,e);
                 else
                    printf("˳���Ԫ�ظ���С������ֵ������ֵС��1\n");
                 break;
             case 7:
                  printf("���������ֵ��");
                  scanf("%d",&e);
                  printf("����ֵ%d��λ����%d\n",e,LocateElem(List,e));
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
                  printf("������ڶ���˳���Ԫ�ظ�����");
                  scanf("%d",&n);
                  Listb=Create(Listb,n);
                  ListUnion(List,Listb);
                  break;
            case 11:
                  Listb=InitList(Listb);
                  printf("�������һ���ǵݼ�˳���Ԫ�ظ�����");
                  scanf("%d",&n);
                  Listb=Create(Listb,n);
                  Listc=InitList(Listc);
                  printf("������ڶ����ǵݼ�˳���Ԫ�ظ�����");
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
