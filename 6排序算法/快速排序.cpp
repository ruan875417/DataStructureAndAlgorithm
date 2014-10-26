#include <iostream>
using namespace std;
int partition(int a[],int i,int j){
     int X=a[i];  //������ĵ�1����¼��Ϊ��׼
     while(i<j){   //���������˽������м�ɨ�裬ֱ��i=jΪֹ
         while(i<j&&a[j]>=X) //X�൱����λ��i��
             j--;     //��������ɨ�裬�鵽��1���ؼ���С��X�ļ�¼a[j]
         if(i<j)    //��ʾ�ҵ��Ĺؼ���С��X
             a[i++] = a[j];   //�൱�ڽ���a[i]��a[j]
         while(i<j&&a[i]<=X)
             i++;
         if(i<j)
             a[j--] = a[i];
     }
     a[i]=X;  //��׼��¼�ѱ����λ
     return i;  
}
void QuickSort(int a[],int low,int high){
     int pivotpos;   //���ֺ�Ļ�׼��¼��λ��
     if(low < high)   //�������䳤�ȴ���1ʱ������
     {
         pivotpos = partition(a,low,high); //������
         QuickSort(a,low,pivotpos-1);
         QuickSort(a,pivotpos+1,high);
     }
     
} 
void printArray(int a[],int n){
     int i;
     for(i = 0;i < n;i++)
         cout<<a[i]<<" ";
     cout<<endl;
}
int main(){
     int dec[]={0,5,2,9,7,4,3};
     QuickSort(dec,0,6);
     printArray(dec,7);
     system("pause");
     return 0;
}
