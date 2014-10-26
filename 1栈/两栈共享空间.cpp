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
	 printf("1:初始化操作，建立一个空栈\n");
	 printf("2:判断该栈是否为空，空返回1,否则返回0\n");
	 printf("3:输入一组整数，建立非空栈\n");
	 printf("4:从栈中弹出一个元素\n");
     printf("5:获取栈顶元素\n");
	 printf("6:将栈清空\n");
	 printf("0:退出菜单\n"); 
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
                     printf("请输入栈的序号（1或2）和入栈元素：");             
                     scanf("%d%d",&num,&e);
                     StackPush(&stack,num,e);
                 }
                 break;
            case 4:
                 printf("请输入岀栈的栈的序号（1或2）：");
                 scanf("%d",&num);
                 if(StackPop(&stack,num,&e))
                    printf("岀栈的元素是%d\n",e);
                 else
                    printf("栈已空\n");
                 break;
            case 5:
                 printf("请输入栈的序号（1或2）：");
                 scanf("%d",&num);
                 if(getTop(&stack,num,&e))
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
