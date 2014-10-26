#include<stdio.h>
#include<stdlib.h>
typedef struct{
        int *base;
        int *top1;
        int *top2; 
        int stackSize;
}SqDoubleStack;
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
int InitStack(SqDoubleStack *stack){
    stack->base=(int *)malloc(sizeof(int)*100);
    stack->top1=stack->base;
    stack->top2=stack->base+99;
    stack->stackSize=100;
    return 1;
}
int StackEmpty(SqDoubleStack stack){
    if(stack.top1==stack.base&&stack.top2==(stack.base+99))
       return 1;
    return 0;
}
int StackPush(SqDoubleStack *stack,int stackNum,int e){
    if(stack->top1+1==stack->top2)
       return 0;
    if(stackNum==1){
       *stack->top1=e;
       stack->top1++;
    }else if(stackNum==2){
       *stack->top2=e;
       stack->top2--;
    }
    return 1;
}  
int StackPop(SqDoubleStack  *stack,int stackNum,int *e){
    if(stackNum==1){
       if(stack->top1==stack->base)
          return 0;
       stack->top1--; 
       *e=*stack->top1;
    }else if(stackNum==2){
       if(stack->top2==(stack->base+99))
          return 0;
       stack->top2++; 
       *e=*stack->top2;
    }
    return 1;
}
int getTop(SqDoubleStack  *stack,int stackNum,int *e){
    if(stackNum==1){
       if(stack->top1==stack->base)
          return 0;
       *e=*(stack->top1-1);
    }else if(stackNum==2){
       if(stack->top2==(stack->base+99))
          return 0;
       *e=*(stack->top2+1);
    }
    return 1;
}
int ClearStack(SqDoubleStack  *stack){
    stack->top1=stack->base;
    stack->top2=stack->base+99;
    return 1;
}
int main(){
    int choose;
    int i,e,n,num;
    bool flag=true;
    SqDoubleStack stack;
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
                     printf("������ջ����ţ�1��2������ջԪ�أ�");             
                     scanf("%d%d",&num,&e);
                     StackPush(&stack,num,e);
                 }
                 break;
            case 4:
                 printf("�������ջ��ջ����ţ�1��2����");
                 scanf("%d",&num);
                 if(StackPop(&stack,num,&e))
                    printf("��ջ��Ԫ����%d\n",e);
                 else
                    printf("ջ�ѿ�\n");
                 break;
            case 5:
                 printf("������ջ����ţ�1��2����");
                 scanf("%d",&num);
                 if(getTop(&stack,num,&e))
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
