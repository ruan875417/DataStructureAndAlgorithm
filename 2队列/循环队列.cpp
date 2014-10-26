
#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#define MAXQSIZE 10 
typedef struct{
        int *data;
        int front;
        int rear;
}SqQueue;
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:初始化操作，建立循环队列\n");
	 printf("2:返回循环队列元素个数\n");
	 printf("3:输入元素入循环队列\n");
	 printf("4:删除队头元素\n");
     printf("5:清空循环队列\n");
	 printf("6:判断循环队列是否为空\n");
     printf("7:遍历队列元素\n");
	 printf("0:退出菜单\n"); 
     printf("----------------------------------------------------------------\n");
}
int InitQueue(SqQueue *Q){
    Q->data=(int *)malloc(sizeof(int)*MAXQSIZE);
    if(!Q->data) 
       exit(OVERFLOW);
    Q->front=Q->rear=0;
    return 1;
}
int EnQueue(SqQueue *Q,int e){
    if((Q->rear+1)%MAXQSIZE==Q->front)
       return 0;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXQSIZE;
    return 1;
}
int DeQueue(SqQueue *Q,int *e){
    if(Q->front==Q->rear)
       return 0;
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXQSIZE;  
    return 1;
}
int ClearQueue(SqQueue *Q){
    Q->front=Q->rear=0;
    return 1;
}
int QueueEmpty(SqQueue *Q){
    if(Q->front==Q->rear)
       return 1;
    return 0;
}
void QueueTraverse(SqQueue *Q){
    int p=Q->front%MAXQSIZE;
    while(p!=Q->rear){
          printf("%d ",Q->data[p]);
          p=(p+1)%MAXQSIZE;
    }
    printf("\n");
}
int QueueLength(SqQueue *Q){
    return (Q->rear-Q->front+MAXQSIZE)%MAXQSIZE;
}
int main(){
    int choose;
    int i,e,n;
    bool flag=true;
    SqQueue Q;
    while(flag){
         menu();
         printf("请选择要进行的操作：");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 if(InitQueue(&Q))
                    printf("初始化链队列成功!\n");
                 else
                    printf("初始化链队列失败!\n");
                 break;
            case 2:
                printf("链队列的元素个数为%d\n",QueueLength(&Q)); 
                 break;
            case 3:
                 printf("请输入要入队列的元素：");
                 scanf("%d",&e);
                 if(EnQueue(&Q,e))
                    printf("入链队列成功!\n");
                 else
                    printf("入链队列失败!\n");
                 break;
            case 4:
                 if(DeQueue(&Q,&e))
                    printf("删除的队头元素是%d\n",e);
                 else
                    printf("队列为空!\n");
                 break;
            case 5:
                 if(ClearQueue(&Q))
                    printf("清空链队列成功!\n");
                 else
                    printf("清空链队列失败!\n");
                 break;
            case 6:
                 if(QueueEmpty(&Q))
                    printf("链队列为空！\n");
                 else
                    printf("链队列不为空!\n");
                 break;
            case 7:
                 QueueTraverse(&Q); 
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
