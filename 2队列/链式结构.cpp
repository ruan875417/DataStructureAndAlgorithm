
#include<stdio.h>
#include<stdlib.h>
#include<math.h>  
typedef struct Qnode{
        int data;
        Qnode *next;
}Qnode,*QueuePtr;
typedef struct{
        QueuePtr front;
        QueuePtr rear;
}LinkQueue;
void menu(){
     printf("----------------------------------------------------------------\n");
	 printf("1:初始化操作，建立链队列\n");
	 printf("2:销毁链队列\n");
	 printf("3:输入元素入队列\n");
	 printf("4:删除队头元素\n");
     printf("5:清空链队列\n");
	 printf("6:判断链队列是否为空\n");
     printf("7:遍历队列元素\n");
     printf("8:返回链队列元素个数\n");
	 printf("0:退出菜单\n"); 
     printf("----------------------------------------------------------------\n");
}
int InitQueue(LinkQueue *Q){
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(Qnode));
    if(!Q->front)
		exit(OVERFLOW);   
    Q->front->next=NULL;
    return 1;
}
int DestroyQueue(LinkQueue *Q){
    while(Q->front){
          Q->rear=Q->front->next;
          free(Q->front);
          Q->front=Q->rear;
    }
    return 1;
}
int EnQueue(LinkQueue *Q,int e){
    QueuePtr p=(QueuePtr)malloc(sizeof(Qnode));
    if(!p)
       exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return 1;
}
int DeQueue(LinkQueue *Q,int *e){
    if(Q->front==Q->rear)
       return 0;
    QueuePtr p=Q->front->next;
    *e=p->data;
    Q->front=Q->front->next;
    if(Q->rear==p)
       Q->rear=Q->front;
    free(p);
    return 1;
}
int ClearQueue(LinkQueue *Q){
    QueuePtr p,q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;
    while(p){
          q=p;
          p=p->next;
          free(q);
    }
    return 1;
}
int QueueEmpty(LinkQueue *Q){
    if(Q->front==Q->rear)
       return 1;
    return 0;
}
void QueueTraverse(LinkQueue *Q){
    QueuePtr p=Q->front->next;
    while(p){
          printf("%d ",p->data);
          p=p->next;
    }
    printf("\n");
}
int QueueLength(LinkQueue *Q){
    int num=0;
    QueuePtr p=Q->front->next;
    while(p){
          num++;
          p=p->next;
    }
    return num;
}
int main(){
    int choose;
    int i,e,n;
    bool flag=true;
    LinkQueue Q;
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
                 if(DestroyQueue(&Q))
                    printf("销毁链队列成功!\n");
                 else
                    printf("销毁链队列失败!\n");
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
            case 8:
                 printf("链队列的元素个数为%d\n",QueueLength(&Q)); 
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
