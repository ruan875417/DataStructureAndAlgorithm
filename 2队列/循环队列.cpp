
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
	 printf("1:��ʼ������������ѭ������\n");
	 printf("2:����ѭ������Ԫ�ظ���\n");
	 printf("3:����Ԫ����ѭ������\n");
	 printf("4:ɾ����ͷԪ��\n");
     printf("5:���ѭ������\n");
	 printf("6:�ж�ѭ�������Ƿ�Ϊ��\n");
     printf("7:��������Ԫ��\n");
	 printf("0:�˳��˵�\n"); 
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
         printf("��ѡ��Ҫ���еĲ�����");
         scanf("%d",&choose);
         switch(choose){
            case 1:
                 if(InitQueue(&Q))
                    printf("��ʼ�������гɹ�!\n");
                 else
                    printf("��ʼ��������ʧ��!\n");
                 break;
            case 2:
                printf("�����е�Ԫ�ظ���Ϊ%d\n",QueueLength(&Q)); 
                 break;
            case 3:
                 printf("������Ҫ����е�Ԫ�أ�");
                 scanf("%d",&e);
                 if(EnQueue(&Q,e))
                    printf("�������гɹ�!\n");
                 else
                    printf("��������ʧ��!\n");
                 break;
            case 4:
                 if(DeQueue(&Q,&e))
                    printf("ɾ���Ķ�ͷԪ����%d\n",e);
                 else
                    printf("����Ϊ��!\n");
                 break;
            case 5:
                 if(ClearQueue(&Q))
                    printf("��������гɹ�!\n");
                 else
                    printf("���������ʧ��!\n");
                 break;
            case 6:
                 if(QueueEmpty(&Q))
                    printf("������Ϊ�գ�\n");
                 else
                    printf("�����в�Ϊ��!\n");
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
