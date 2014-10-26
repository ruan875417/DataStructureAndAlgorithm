#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
const int MAXSIZE=20;
///////////////////////////////////////////////////////////////////////////
struct HuffNode {         
       int data;        //data��ʾȨֵ������    
       int par;                //par=0��������Ƕ����ģ�par>0Ϊ����˫���±�    
       int lch,rch;            //lch,rch���Һ��ӽ���������е��±�,0,0���ʾ���Ƕ������
};
////////////////////////////////////////////////////////////////////////////
class HuffTree{
      private:    
           HuffNode r[MAXSIZE];   //�����������������    
           int n;                //���Ȩֵ��Ҷ�ӣ��ĸ���
      public:   
           HuffTree(int n0);       //n0ΪȨֵ�ĸ���      
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
      for(i=0;i<n;i++){                    //��n=1,��ֻ��һ����㣬��r[0].lch=r[0].rch=0;r[0].par=0;�������            
               cout<<"Ȩֵ=";
               cin>>r[i].data;    
      }    
      for(i=0;i<n-1;i++){        //n�������Ҫ�ϲ�n-1��           
           m1=m2=10000;    //m1������СȨֵ��m2�����СȨֵ����ֵ����㹻��        
           x1=x2=-1;        //x1,x2Ϊ��СȨֵ����СȨֵ���±��        
           for(j=0;j<n+i;j++)            //��par=0��������������Ԫ����ѡ��С����Сֵ            
               if((r[j].data<m1)&&(r[j].par==0)){               
                    m2=m1;x2=x1;                
                    m1=r[j].data;x1=j;            
               }else if((r[j].data<m2)&&(r[j].par==0)){               
                      m2=r[j].data;x2=j;            
               }            
           r[x1].par=n+i;r[x2].par=n+i;       //˫���±�par            
           r[n+i].data=r[x1].data+r[x2].data;               
           r[n+i].lch=x1;r[n+i].rch=x2;  //Ϊ�µĽ���ú��ӱ�ǣ�����Ϊ��СȨֵ            
      }
}
void HuffTree::printHuffTree(){    
     cout<<"\n"<<"���"<<setw(5)<<"Ȩֵ"<<setw(15)<<"˫�׵��±�"<<setw(15)<<"���ӵ��±�"<<setw(15)<<"�Һ��ӵ��±�";    
     for(int j=0;j<2*n-1;j++)   //����2*n-1�����        
          cout<<"\n"<<j<<setw(6)<<r[j].data<<setw(15)<<r[j].par<<setw(15)<<r[j].lch<<setw(15)<<r[j].rch<<endl;
}
void HuffTree::HuffTreeCode(){    
     char co[MAXSIZE][10];                //n��Ȩֵ��Ӧ�ı������飬������Ϊchar co[n][n],�����֡�co��: δ֪�Ĵ�С�����Դ�    
     char *temp=new char [n];        //һ��Ȩֵ��Ӧ�ı�������    
     int i,j,c,k,last;   
     for(i=0;i<n;i++){    //��n��Ȩֵ��Ҷ�ӣ�����           
         c=i;        //cΪ��ǰ�����±�        
         temp[n-1]='\0';        
         for(k=0;k<n-1;k++)
                temp[k]=' ';                //ÿ�ο�ʼʱ���봮���       
         last=n-1;        
         j=r[c].par;        //jΪ���c��˫���±�        
         while(j!=0){            //��j=0���ʾ�Ѿ����ݵ�������ˣ�ѭ���Ͽ�                  
              last--;            //strָ��ǰ���������λ��,ע�⣬�ǴӺ���ǰ��������            
              if(r[j].lch==c)                //�ڹ������������������֧ȡ����Ϊ0���������ҷ�֧ȡ����Ϊ1                
                   temp[last]='0';            
              else 
                   temp[last]='1';            
              c=j;
              j=r[c].par;            //�µĵ�ǰ����˫��        
         }        
         strcpy(co[i],temp);    
      }    
      cout<<"\n    Ȩֵ        ����";    
      for(i=0;i<n;i++)        
          cout<<"\n"<<setw(6)<<r[i].data<<setw(8)<<co[i];
}
/////////////////////////////////////////////////////////////////////////
int main(){    
     int num;    
     cout<<"�����Ȩֵ����:n=?";
     cin>>num;    
     HuffTree hufftree(num);   
     hufftree.CreatHuffTree();    
     hufftree.printHuffTree();    
     hufftree.HuffTreeCode();
     system("pause");
     return 0;
}
