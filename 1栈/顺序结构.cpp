#include<stdio.h>
#include<stdlib.h>
typedef struct{
        int *base;
        int *top;
        int stackSize;
}SqStack;
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:初始化操作，建立一个空栈\n");
	 printf("2:判断该栈是否为空，空返回1,否则返回0\n");
	 printf("3:输入一组整数，建立非空栈\n");
	 printf("4:从栈中弹出一个元素\n");
     printf("5:获取栈顶元素\n");
	 printf("6:将栈清空\n");
	 printf("0:退出菜单\n"); 
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
         printf("请选择要进行的操作：");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 if(InitStack(&stack))
                    printf("初始化栈成功！\n");
                 break;
            case 2:
                 printf("%d\n",StackEmpty(stack));
                 break; 
            case 3:
                 printf("请输入栈的元素个数：");
                 scanf("%d",&n);
                 for(i=0;i<n;i++){
                     scanf("%d",&e);
                     StackPush(&stack,e);
                 }
                 break;
            case 4:
                 if(StackPop(&stack,&e))
                    printf("岀栈的元素是%d\n",e);
                 else
                    printf("栈已空\n");
                 break;
            case 5:
                 if(getTop(&stack,&e))
                    printf("栈顶元素是%d\n",e);
                 else
                    printf("栈已空\n");
                 break;
            case 6:
                 if(ClearStack(&stack))
                    printf("清空栈成功\n"); 
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
