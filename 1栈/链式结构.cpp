
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkStack{
        int data;
        LinkStack *next;
}LinkStack;
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
         printf("请选择要进行的操作：");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 top=InitStack(top);
                 if(top->next==NULL)
                     printf("初始化栈成功！\n");
                 break;
            case 2:
                 printf("%d\n",StackEmpty(top));
                 break; 
            case 3:
                 printf("请输入栈的元素个数：");
                 scanf("%d",&n);
                 for(i=0;i<n;i++){
                     scanf("%d",&e);
                     top=StackPush(top,e);
                 }
                 break;
            case 4:
                top=StackPop(top,&e);
                if(top->next!=NULL)
                    printf("岀栈的元素是%d\n",e);
                 else
                    printf("栈已空\n");
                 break;
            case 5:
                 top=getTop(top,&e);
                 if(top->next!=NULL)
                    printf("栈顶元素是%d\n",e);
                 else
                    printf("栈已空\n");
                 break;
            case 6:
                 top=ClearStack(top);
                 if(top->next==NULL)
                    printf("清空栈成功\n"); 
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
