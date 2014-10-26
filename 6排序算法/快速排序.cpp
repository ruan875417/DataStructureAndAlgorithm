#include <iostream>
using namespace std;
int partition(int a[],int i,int j){
     int X=a[i];  //用区间的第1个记录作为基准
     while(i<j){   //从区间两端交替向中间扫描，直到i=j为止
         while(i<j&&a[j]>=X) //X相当于在位置i上
             j--;     //从右向左扫描，查到第1个关键字小于X的记录a[j]
         if(i<j)    //表示找到的关键字小于X
             a[i++] = a[j];   //相当于交换a[i]和a[j]
         while(i<j&&a[i]<=X)
             i++;
         if(i<j)
             a[j--] = a[i];
     }
     a[i]=X;  //基准记录已被最后定位
     return i;  
}
void QuickSort(int a[],int low,int high){
     int pivotpos;   //划分后的基准记录的位置
     if(low < high)   //仅当区间长度大于1时才排序
     {
         pivotpos = partition(a,low,high); //做划分
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
