
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
     printf("1.输入字符序列，建立二叉树!\n");
	 printf("2.先序、中序、后序遍历二叉树(递归算法)!\n");
     printf("3.中序遍历二叉树(非递归算法)!\n");
     printf("4.层次遍历二叉树!\n");
     printf("5.求二叉树的高度!\n");
     printf("6.求二叉树的叶子个数!\n");
     printf("7.对于树中每一个元素值为x的结点，删去以它为根的子树，并释放相应的空间!\n");
     printf("0.退出程序!\n");
     printf("注意:功能7改变了二叉树的结构和元素组成,如需层次遍历菜单1建立的二叉树,请先选择4再选择7!\n");
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
	     printf("请输入要选择的功能:");
         scanf("%d",&choose);
 	     switch(choose) {
	          case 1:
          	        printf("请输入二叉树中的元素,空的左右孩子以#替代，以$代表输入结束:\n");
                    CreatBiTree(BiTree);	
                    break;
              case 2:
                   printf("先序遍历:");
                   PreOrderTraverse(BiTree);
                   printf("\n中序遍历:\n");
                   InOrderTraverse(BiTree);
                   printf("后序遍历:\n");
                   PostOrderTraverse(BiTree);
                   break;
              case 3:
	               NotRecursionInOrderTraverse(BiTree);
	               break;
	          case 4:
                   printf("层次遍历:");
                   LevelOrderTraverse(BiTree);
                   printf("\n");
                   break;
	          case 5:
                   depth=0,level=0;
                   TreeDepth(BiTree,depth,level);
		           printf("二叉树的高度为:%d\n",depth);
		           break;
	         case 6:
	           	  printf("二叉树的叶子个数为：%d\n",CountLeaf(BiTree));
	           	  break;
             case 7:
                  printf("请先输入一个值：");
                  getchar();
                  scanf("%c",&ch);
		          search(BiTree,ch);
		          break;
	         case 0: 
                  flag=false;
                  break;
             default:
                  printf("输入错误，请重新输入\n");
		       
	}
   } 
	system("pause");
	return 0;
}
