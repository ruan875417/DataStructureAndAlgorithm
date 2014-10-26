
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkStack{
        int data;
        LinkStack *next;
}LinkStack;
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:��ʼ������������һ����ջ\n");
	 printf("2:�жϸ�ջ�Ƿ�Ϊ�գ��շ���1,���򷵻�0\n");
	 printf("3:����һ�������������ǿ�ջ\n");
	 printf("4:��ջ�е���һ��Ԫ��\n");
     printf("5:��ȡջ��Ԫ��\n");
	 printf("6:��ջ���\n");
	 printf("0:�˳��˵�\n"); 
     printf("----------------------------------------------------------------\n");
}
LinkStack* InitStack(LinkStack *top){
    top=(LinkStack *)malloc(sizeof(LinkStack));
    top->next=NULL;
    return top;
}
int StackEmpty(LinkStack *top){
    if(top->next==NULL)
       return 1;
    return 0;
}
LinkStack* StackPush(LinkStack *top,int e){
    LinkStack *p=(LinkStack *)malloc(sizeof(LinkStack));
    p->data=e;
    p->next=top;
    top=p;
    return top;
}  
LinkStack* StackPop(LinkStack *top,int *e){
    if(top->next==NULL)
       return top;
    LinkStack *p=top; 
    *e=top->data;
    top=top->next;
    free(p);
    return top;
}
LinkStack* getTop(LinkStack *top,int *e){
    if(top->next==NULL)
       return top;
    *e=top->data;
    return top;
}
LinkStack* ClearStack(LinkStack *top){
    LinkStack *p;
    while(top->next!=NULL){
          p=top;
          top=top->next;
          free(p);
    }
    return top;
}
int main(){
    int choose;
    int i,e,n;
    bool flag=true;
    LinkStack *top;
    while(flag){
         menu();
         printf("��ѡ��Ҫ���еĲ�����");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 top=InitStack(top);
                 if(top->next==NULL)
                     printf("��ʼ��ջ�ɹ���\n");
                 break;
            case 2:
                 printf("%d\n",StackEmpty(top));
                 break; 
            case 3:
                 printf("������ջ��Ԫ�ظ�����");
                 scanf("%d",&n);
                 for(i=0;i<n;i++){
                     scanf("%d",&e);
                     top=StackPush(top,e);
                 }
                 break;
            case 4:
                top=StackPop(top,&e);
                if(top->next!=NULL)
                    printf("��ջ��Ԫ����%d\n",e);
                 else
                    printf("ջ�ѿ�\n");
                 break;
            case 5:
                 top=getTop(top,&e);
                 if(top->next!=NULL)
                    printf("ջ��Ԫ����%d\n",e);
                 else
                    printf("ջ�ѿ�\n");
                 break;
            case 6:
                 top=ClearStack(top);
                 if(top->next==NULL)
                    printf("���ջ�ɹ�\n"); 
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
