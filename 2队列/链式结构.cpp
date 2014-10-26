
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
	 printf("1:��ʼ������������������\n");
	 printf("2:����������\n");
	 printf("3:����Ԫ�������\n");
	 printf("4:ɾ����ͷԪ��\n");
     printf("5:���������\n");
	 printf("6:�ж��������Ƿ�Ϊ��\n");
     printf("7:��������Ԫ��\n");
     printf("8:����������Ԫ�ظ���\n");
	 printf("0:�˳��˵�\n"); 
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
                 if(DestroyQueue(&Q))
                    printf("���������гɹ�!\n");
                 else
                    printf("����������ʧ��!\n");
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
            case 8:
                 printf("�����е�Ԫ�ظ���Ϊ%d\n",QueueLength(&Q)); 
                 break;
            case 0:
                  flag=false;
                  break;
         } 
    } 
    return 0;
}
