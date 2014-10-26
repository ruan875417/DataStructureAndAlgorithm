#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
const int MAXSIZE=20;
///////////////////////////////////////////////////////////////////////////
struct HuffNode {         
       int data;        //data表示权值数据域    
       int par;                //par=0表明结点是独立的，par>0为它的双亲下标    
       int lch,rch;            //lch,rch左右孩子结点在数组中的下标,0,0则表示它是独立结点
};
////////////////////////////////////////////////////////////////////////////
class HuffTree{
      private:    
           HuffNode r[MAXSIZE];   //保存二叉树结点的数组    
           int n;                //最初权值（叶子）的个数
      public:   
           HuffTree(int n0);       //n0为权值的个数      
           void CreatHuffTree();    
           void printHuffTree();    
           void HuffTreeCode();
};
HuffTree::HuffTree(int n0){       
        n=n0;        
        for(int i=0;i<2*n-1;i++){            
            r[i].data=0;            
            r[i].par=0;
            r[i].lch=r[i].rch=0;        
        }    
}   
void HuffTree::CreatHuffTree(){   
      int i,j,m1,m2,x1,x2;    
      for(i=0;i<n;i++){                    //若n=1,即只有一个结点，则r[0].lch=r[0].rch=0;r[0].par=0;独立结点            
               cout<<"权值=";
               cin>>r[i].data;    
      }    
      for(i=0;i<n-1;i++){        //n个结点需要合并n-1次           
           m1=m2=10000;    //m1代表最小权值，m2代表次小权值，初值设得足够大        
           x1=x2=-1;        //x1,x2为最小权值，次小权值的下标号        
           for(j=0;j<n+i;j++)            //从par=0即独立结点的数组元素中选最小，次小值            
               if((r[j].data<m1)&&(r[j].par==0)){               
                    m2=m1;x2=x1;                
                    m1=r[j].data;x1=j;            
               }else if((r[j].data<m2)&&(r[j].par==0)){               
                      m2=r[j].data;x2=j;            
               }            
           r[x1].par=n+i;r[x2].par=n+i;       //双亲下标par            
           r[n+i].data=r[x1].data+r[x2].data;               
           r[n+i].lch=x1;r[n+i].rch=x2;  //为新的结点置孩子标记，左孩子为较小权值            
      }
}
void HuffTree::printHuffTree(){    
     cout<<"\n"<<"序号"<<setw(5)<<"权值"<<setw(15)<<"双亲的下标"<<setw(15)<<"左孩子的下标"<<setw(15)<<"右孩子的下标";    
     for(int j=0;j<2*n-1;j++)   //共有2*n-1个结点        
          cout<<"\n"<<j<<setw(6)<<r[j].data<<setw(15)<<r[j].par<<setw(15)<<r[j].lch<<setw(15)<<r[j].rch<<endl;
}
void HuffTree::HuffTreeCode(){    
     char co[MAXSIZE][10];                //n个权值对应的编码数组，若声明为char co[n][n],则会出现“co”: 未知的大小，所以大开    
     char *temp=new char [n];        //一个权值对应的编码数组    
     int i,j,c,k,last;   
     for(i=0;i<n;i++){    //对n个权值（叶子）编码           
         c=i;        //c为当前结点的下标        
         temp[n-1]='\0';        
         for(k=0;k<n-1;k++)
                temp[k]=' ';                //每次开始时编码串清空       
         last=n-1;        
         j=r[c].par;        //j为结点c的双亲下标        
         while(j!=0){            //当j=0则表示已经回溯到根结点了，循环断开                  
              last--;            //str指向当前编码数组的位置,注意，是从后往前倒序编码的            
              if(r[j].lch==c)                //在哈夫曼树中令所有左分支取编码为0，令所有右分支取编码为1                
                   temp[last]='0';            
              else 
                   temp[last]='1';            
              c=j;
              j=r[c].par;            //新的当前结点和双亲        
         }        
         strcpy(co[i],temp);    
      }    
      cout<<"\n    权值        编码";    
      for(i=0;i<n;i++)        
          cout<<"\n"<<setw(6)<<r[i].data<<setw(8)<<co[i];
}
/////////////////////////////////////////////////////////////////////////
int main(){    
     int num;    
     cout<<"输入的权值个数:n=?";
     cin>>num;    
     HuffTree hufftree(num);   
     hufftree.CreatHuffTree();    
     hufftree.printHuffTree();    
     hufftree.HuffTreeCode();
     system("pause");
     return 0;
}
