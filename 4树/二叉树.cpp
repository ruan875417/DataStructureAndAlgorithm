
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct BiTNode{
       char data;
       BiTNode *lchild,*rchild;
};
void menu(){
     printf("========================================================================\n");
     printf("1.�����ַ����У�����������!\n");
	 printf("2.�������򡢺������������(�ݹ��㷨)!\n");
     printf("3.�������������(�ǵݹ��㷨)!\n");
     printf("4.��α���������!\n");
     printf("5.��������ĸ߶�!\n");
     printf("6.���������Ҷ�Ӹ���!\n");
     printf("7.��������ÿһ��Ԫ��ֵΪx�Ľ�㣬ɾȥ����Ϊ�������������ͷ���Ӧ�Ŀռ�!\n");
     printf("0.�˳�����!\n");
     printf("ע��:����7�ı��˶������Ľṹ��Ԫ�����,�����α����˵�1�����Ķ�����,����ѡ��4��ѡ��7!\n");
     printf("=============================================================================\n");
}
void CreatBiTree(BiTNode* &T){
     char ch=getchar();
     if(ch=='#'||ch=='$')
         T=NULL;
     else{
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
     }
        
}
void PreOrderTraverse(BiTNode* T){
     if(T){
        printf("%2c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);       
     }
}
void InOrderTraverse(BiTNode* T){
     if(T){
        InOrderTraverse(T->lchild);
        printf("%2c",T->data);
        InOrderTraverse(T->rchild);       
     }
}
void PostOrderTraverse(BiTNode* T){
     if(T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);   
        printf("%2c",T->data);    
     }   
}
void NotRecursionInOrderTraverse(BiTNode* T){
     stack <BiTNode*> stk;
     while(!stk.empty())
           stk.pop();
     stk.push(T);
     while(!stk.empty()){
           while(stk.top())
                 stk.push(stk.top()->lchild);
           stk.pop();
           if(!stk.empty()){
              BiTNode* temp=stk.top();
              printf("%2c",temp->data);
              stk.pop();
              stk.push(temp->rchild);
           }
     }
}
void LevelOrderTraverse(BiTNode* T){
     queue <BiTNode*> que;
     while(!que.empty())
           que.pop();
     que.push(T);
     while(!que.empty()){
           BiTNode* temp=que.front();
           if(temp)
              printf("%2c",temp->data);
           que.pop();
           if(temp){
              que.push(temp->lchild);
              que.push(temp->rchild);
           }
     }
}
void TreeDepth(BiTNode* T,int &depth,int level){
      if(T){
         if(level>depth)
            depth=level;
         TreeDepth(T->lchild,depth,level+1);
         TreeDepth(T->rchild,depth,level+1);       
     }
}
int CountLeaf(BiTNode* T){
     if(T==NULL)
        return 0;
     else if(T->lchild==NULL&&T->rchild==NULL)
        return 1;
     else 
        return (CountLeaf(T->lchild)+CountLeaf(T->rchild));
}
void del(BiTNode* &T){
     if(T){
        delete(T->lchild);
        delete(T->rchild);
        free(T);
     }
}
void search(BiTNode* &T,char ch){
     if(T){
           if(T->data==ch){
              del(T->lchild);
              del(T->rchild);
              T->lchild=NULL;
              T->rchild=NULL;
           }else{
              search(T->lchild,ch);
              search(T->rchild,ch);
           }
     }
}
int main(){
	int choose;
	bool flag=true;
	BiTNode* BiTree;
	int depth,level;
	char ch;
    while(flag){   
         menu();     
	     printf("������Ҫѡ��Ĺ���:");
         scanf("%d",&choose);
 	     switch(choose) {
	          case 1:
          	        printf("������������е�Ԫ��,�յ����Һ�����#�������$�����������:\n");
                    CreatBiTree(BiTree);	
                    break;
              case 2:
                   printf("�������:");
                   PreOrderTraverse(BiTree);
                   printf("\n�������:\n");
                   InOrderTraverse(BiTree);
                   printf("�������:\n");
                   PostOrderTraverse(BiTree);
                   break;
              case 3:
	               NotRecursionInOrderTraverse(BiTree);
	               break;
	          case 4:
                   printf("��α���:");
                   LevelOrderTraverse(BiTree);
                   printf("\n");
                   break;
	          case 5:
                   depth=0,level=0;
                   TreeDepth(BiTree,depth,level);
		           printf("�������ĸ߶�Ϊ:%d\n",depth);
		           break;
	         case 6:
	           	  printf("��������Ҷ�Ӹ���Ϊ��%d\n",CountLeaf(BiTree));
	           	  break;
             case 7:
                  printf("��������һ��ֵ��");
                  getchar();
                  scanf("%c",&ch);
		          search(BiTree,ch);
		          break;
	         case 0: 
                  flag=false;
                  break;
             default:
                  printf("�����������������\n");
		       
	}
   } 
	system("pause");
	return 0;
}
