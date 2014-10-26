#include<stdio.h>
#include<stdlib.h>
typedef struct{
        int *base;
        int *top;
        int stackSize;
}SqStack;
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
int InitStack(SqStack *stack){
    stack->base=(int *)malloc(sizeof(int)*20);
    stack->top=stack->base;
    stack->stackSize=20;
    return 1;
}
int StackEmpty(SqStack stack){
    if(stack.top==stack.base)
       return 1;
    return 0;
}
int StackPush(SqStack *stack,int e){
    if(stack->top-stack->base>=stack->stackSize){
       stack->base=(int *)realloc(stack->base,sizeof(int)*(stack->stackSize+20));
       stack->top=stack->base+stack->stackSize;
       stack->stackSize+=20;
    }
    *stack->top=e;
    stack->top++; 
    return 1;
}  
int StackPop(SqStack *stack,int *e){
    if(stack->top==stack->base)
       return 0;
    stack->top--; 
    *e=*stack->top;
    return 1;
}
int getTop(SqStack *stack,int *e){
    if(stack->top==stack->base)
       return 0;
    *e=*(stack->top-1);
    return 1;
}
int ClearStack(SqStack *stack){
    stack->top=stack->base;
    return 1;
}
int main(){
    int choose;
    int i,e,n;
    bool flag=true;
    SqStack stack;
    while(flag){
         menu();
         printf("��ѡ��Ҫ���еĲ�����");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 if(InitStack(&stack))
                    printf("��ʼ��ջ�ɹ���\n");
                 break;
            case 2:
                 printf("%d\n",StackEmpty(stack));
                 break; 
            case 3:
                 printf("������ջ��Ԫ�ظ�����");
                 scanf("%d",&n);
                 for(i=0;i<n;i++){
                     scanf("%d",&e);
                     StackPush(&stack,e);
                 }
                 break;
            case 4:
                 if(StackPop(&stack,&e))
                    printf("��ջ��Ԫ����%d\n",e);
                 else
                    printf("ջ�ѿ�\n");
                 break;
            case 5:
                 if(getTop(&stack,&e))
                    printf("ջ��Ԫ����%d\n",e);
                 else
                    printf("ջ�ѿ�\n");
                 break;
            case 6:
                 if(ClearStack(&stack))
                    printf("���ջ�ɹ�\n"); 
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
